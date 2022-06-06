import os
import numpy as np
import torch
from PIL import Image
import cv2
import torchvision
from torchvision.models.detection.faster_rcnn import FastRCNNPredictor
from torchvision.models.detection.mask_rcnn import MaskRCNNPredictor
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from engine import train_one_epoch, evaluate
import utils
import transforms as T
import tkinter as tk
from tkinter import filedialog
from PIL import ImageTk
from torchvision import models
from torchsummary import summary
from PyQt5.QtWidgets import QMainWindow, QApplication, QMessageBox
from mask_RCNN_ui import Ui_MainWindow
import sys

class PennFudanDataset(object):
    def __init__(self, root, transforms):
        self.root = root
        self.transforms = transforms
        # load all image files, sorting them to
        # ensure that they are aligned
        self.imgs = list(sorted(os.listdir(os.path.join(root, "PNGImages"))))
        self.masks = list(sorted(os.listdir(os.path.join(root, "PedMasks"))))

    def __getitem__(self, idx):
        # load images and masks
        img_path = os.path.join(self.root, "PNGImages", self.imgs[idx])
        mask_path = os.path.join(self.root, "PedMasks", self.masks[idx])
        img = Image.open(img_path).convert("RGB")
        # note that we haven't converted the mask to RGB,
        # because each color corresponds to a different instance
        # with 0 being background
        mask = Image.open(mask_path)

        mask = np.array(mask)
        # instances are encoded as different colors
        obj_ids = np.unique(mask)
        # first id is the background, so remove it
        obj_ids = obj_ids[1:]

        # split the color-encoded mask into a set
        # of binary masks
        masks = mask == obj_ids[:, None, None]

        # get bounding box coordinates for each mask
        num_objs = len(obj_ids)
        boxes = []
        for i in range(num_objs):
            pos = np.where(masks[i])
            xmin = np.min(pos[1])
            xmax = np.max(pos[1])
            ymin = np.min(pos[0])
            ymax = np.max(pos[0])
            boxes.append([xmin, ymin, xmax, ymax])

        boxes = torch.as_tensor(boxes, dtype=torch.float32)
        # there is only one class
        labels = torch.ones((num_objs,), dtype=torch.int64)
        masks = torch.as_tensor(masks, dtype=torch.uint8)

        image_id = torch.tensor([idx])
        area = (boxes[:, 3] - boxes[:, 1]) * (boxes[:, 2] - boxes[:, 0])
        # suppose all instances are not crowd
        iscrowd = torch.zeros((num_objs,), dtype=torch.int64)

        target = {}
        target["boxes"] = boxes
        target["labels"] = labels
        target["masks"] = masks
        target["image_id"] = image_id
        target["area"] = area
        target["iscrowd"] = iscrowd

        if self.transforms is not None:
            img, target = self.transforms(img, target)

        return img, target

    def __len__(self):
        return len(self.imgs)

def get_model_instance_segmentation(num_classes):
    # load an instance segmentation model pre-trained pre-trained on COCO
    model = torchvision.models.detection.maskrcnn_resnet50_fpn(pretrained=True)

    # get number of input features for the classifier
    in_features = model.roi_heads.box_predictor.cls_score.in_features
    # replace the pre-trained head with a new one
    model.roi_heads.box_predictor = FastRCNNPredictor(in_features, num_classes)

    # now get the number of input features for the mask classifier
    in_features_mask = model.roi_heads.mask_predictor.conv5_mask.in_channels
    hidden_layer = 256
    # and replace the mask predictor with a new one
    model.roi_heads.mask_predictor = MaskRCNNPredictor(in_features_mask,
                                                       hidden_layer,
                                                       num_classes)

    return model


def get_transform(train):
    transforms = []
    transforms.append(T.ToTensor())
    if train:
        transforms.append(T.RandomHorizontalFlip(0.5))
    return T.Compose(transforms)


def start():
    file_path = filedialog.askopenfilename()
    img = mpimg.imread(file_path)
    plt.subplot(1,2,1)
    plt.title('origin')
    plt.imshow(img)
    model_trained = torch.load('Save_model_Mask_RCNN.pt')

    device = 'cpu'
    model = model_trained.to(device)
    model.eval()
    x = torch.tensor(img).permute(2,0,1).numpy()
    format_img = np.zeros([1,x.shape[0],x.shape[1],x.shape[2]])
    format_img[0] = x
    format_img = torch.tensor(format_img,dtype = torch.float)
    with torch.no_grad():
            format_img = format_img.to(device) 
            pred = model(format_img)
    pred_cpu = pred[0]['masks'].cpu()

    pred_cpu_mask = pred_cpu[0].permute(1,2,0).numpy()
    plt.subplot(1, 2, 2)
    plt.title('Prediction')
    plt.imshow(pred_cpu_mask)
    plt.show()

    # model = torchvision.models.detection.fasterrcnn_resnet50_fpn(pretrained=True)
    # dataset = PennFudanDataset('PennFudanPed', get_transform(train=True))
    # data_loader = torch.utils.data.DataLoader(
    # dataset, batch_size=2, shuffle=True, num_workers=4,
    # collate_fn=utils.collate_fn)
    # # For Training
    # images,targets = next(iter(data_loader))
    # images = list(image for image in images)
    # targets = [{k: v for k, v in t.items()} for t in targets]
    # output = model(images,targets)   # Returns losses and detections
    # # For inference
    # model.eval()
    # x = [torch.rand(3, 300, 400), torch.rand(3, 500, 400)]
    # predictions = model(x)           # Returns predictions


def main():
    win = tk.Tk() # 創建主視窗
    win.title("2021 Opencvdl Hw1") # 標題
    # 大小
    win.geometry("250x200") # 寬 x 高
    win.resizable(0,0) # 無法改變size
    #顏色
    win.config(bg = "#A0A0A0") # 直接打顏色或是 #RGB (十六進制)
    #透明度
    win.attributes("-alpha",1) # range:0-1  1為完全不透明
    #視窗置頂
    win.attributes("-topmost",0) # 1 = True 0 = False
    
    group_1 = tk.LabelFrame(win, text ="Demo_Mask_RCNN",padx=5,pady=25)
    group_1.pack(padx=10,pady=10)
    group_1.place(x = 20,y = 50)
    group_1.config(bg = "#A0A0A0")
    
    Start = tk.Button(group_1 , text=" Start", bg = "#E0E0E0") #顏色也可以用config
    Start.config(width = 25,height = 2) # 長寬是以網格做調整
    Start.config(command = start) # 使用function
    Start.grid(row = 0,column = 0,padx=10,pady=7)
    

    win.mainloop() # 循環
    

    
    # Training code
    # # train on the GPU or on the CPU, if a GPU is not available
    # device = torch.device('cuda') if torch.cuda.is_available() else torch.device('cpu')

    # # our dataset has two classes only - background and person
    # num_classes = 2
    # # use our dataset and defined transformations
    # dataset = PennFudanDataset('PennFudanPed', get_transform(train=True))
    # dataset_test = PennFudanDataset('PennFudanPed', get_transform(train=False))

    # # split the dataset in train and test set
    # indices = torch.randperm(len(dataset)).tolist()
    # dataset = torch.utils.data.Subset(dataset, indices[:-50])
    # dataset_test = torch.utils.data.Subset(dataset_test, indices[-50:])

    # # define training and validation data loaders
    # data_loader = torch.utils.data.DataLoader(
    #     dataset, batch_size=2, shuffle=True, num_workers=4,
    #     collate_fn=utils.collate_fn)

    # data_loader_test = torch.utils.data.DataLoader(
    #     dataset_test, batch_size=1, shuffle=False, num_workers=4,
    #     collate_fn=utils.collate_fn)

    # # get the model using our helper function
    # model = get_model_instance_segmentation(num_classes)

    # # move model to the right device
    # model.to(device)

    # # construct an optimizer
    # params = [p for p in model.parameters() if p.requires_grad]
    # optimizer = torch.optim.SGD(params, lr=0.005,
    #                             momentum=0.9, weight_decay=0.0005)
    # # and a learning rate scheduler
    # lr_scheduler = torch.optim.lr_scheduler.StepLR(optimizer,
    #                                                step_size=3,
    #                                                gamma=0.1)

    # # let's train it for 10 epochs
    # num_epochs = 10

    # for epoch in range(num_epochs):
    #     # train for one epoch, printing every 10 iterations
    #     train_one_epoch(model, optimizer, data_loader, device, epoch, print_freq=10)
    #     # update the learning rate
    #     lr_scheduler.step()
    #     # evaluate on the test dataset
    #     evaluate(model, data_loader_test, device=device)
        
    # torch.save(model, 'Save_model_Mask_RCNN.pt')
    # print("That's it!")

class MainWindow(QMainWindow, Ui_MainWindow):
    
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)
        self.setupUi(self)
        self.BindComponents()
        self.mask_RCNN = PennFudanDataset('PennFudanPed', get_transform(train=True))
        self.model = torch.load('Save_model_Mask_RCNN.pt', map_location=torch.device('cpu'))
    
    def BindComponents(self):
        self.button_1.clicked.connect(self.button_1_click)
        self.button_2.clicked.connect(self.button_2_click)
        self.button_3.clicked.connect(self.button_3_click)
        self.button_4.clicked.connect(self.button_4_click)
    
    def button_1_click(self):
        img1 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00001.png'), cv2.COLOR_BGR2RGB)
        img2 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00002.png'), cv2.COLOR_BGR2RGB)
        img3 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00003.png'), cv2.COLOR_BGR2RGB)
        img4 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00004.png'), cv2.COLOR_BGR2RGB)
        img5 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00005.png'), cv2.COLOR_BGR2RGB)
        img6 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00006.png'), cv2.COLOR_BGR2RGB)
        img7 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00007.png'), cv2.COLOR_BGR2RGB)
        img8 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00008.png'), cv2.COLOR_BGR2RGB)
        img9 = cv2.cvtColor(cv2.imread('./PennFudanPed/PNGImages/FudanPed00009.png'), cv2.COLOR_BGR2RGB)

        fig = plt.figure(figsize=(16,9))
        fig.add_subplot(3,3,1)
        plt.axis('off')
        plt.title('img1')
        plt.imshow(img1)

        fig.add_subplot(3,3,2)
        plt.axis('off')
        plt.title('')
        plt.title('img2')
        plt.imshow(img2)

        fig.add_subplot(3,3,3)
        plt.axis('off')
        plt.title('img3')
        plt.imshow(img3)

        fig.add_subplot(3,3,4)
        plt.axis('off')
        plt.title('img4')
        plt.imshow(img4)

        fig.add_subplot(3,3,5)
        plt.axis('off')
        plt.title('img5')
        plt.imshow(img5)

        fig.add_subplot(3,3,6)
        plt.axis('off')
        plt.title('img6')
        plt.imshow(img6)

        fig.add_subplot(3,3,7)
        plt.axis('off')
        plt.title('img7')
        plt.imshow(img7)

        fig.add_subplot(3,3,8)
        plt.axis('off')
        plt.title('img8')
        plt.imshow(img8)

        fig.add_subplot(3,3,9)
        plt.axis('off')
        plt.title('img9')
        plt.imshow(img9)
        plt.show()

    def button_2_click(self):
        #show model structure
        print(repr(self.model))
        
    def button_3_click(self):
        #show accuracy and loss graph
        img1 = cv2.imread('Figure_1.png')
        img2 = cv2.imread('Figure_2.png')
        fig = plt.figure(figsize=(16,9))
        fig.add_subplot(1,2,1)
        plt.axis('off')
        plt.title('img1')
        plt.imshow(img1)
    
        fig.add_subplot(1,2,2)
        plt.axis('off')
        plt.title('')
        plt.title('img2')
        plt.imshow(img2)

        plt.show()

    def button_4_click(self):
        #test image
        start()

if __name__ == "__main__":

    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
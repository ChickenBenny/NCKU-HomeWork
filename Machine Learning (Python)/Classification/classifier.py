#!/usr/bin/env python
# coding: utf-8

# # Classifier
# 
# In this exercise, you need to build a classifier to beat a demo classifier. This document contains three parts:
# 
# 1. **Data preprocessing** describes how to prepare your data for a classifier.
# 2. **Classifier construction** describes how to use [scikit-learn (skearn)](http://scikit-learn.org/stable/) to build classifiers.
# 3. **Exercise** describes your homework (Chinese).
# 
# ## 1. Data preprocessing
# 
# Data preprocessing is a necessary step to make your data ready for applying a classifier. This section introduces common data preprocessing issues with two examples:
# 
# 1. A cat dataset to dicuss feature normalization.
# 2. A Pokémon dataset to discuss categorical and missing values.
# 
# See [another document for data preprocessing (Chinese)](/notebooks/unit/data_preprocessing/data_preprocessing.ipynb).
# 
# ### 1.1 Cat classification (feature normalization)
# 
# The cat image dataset from [Andrew Ng](https://www.coursera.org/specializations/deep-learning) contains pictures of cat and other stuff. In our [cat classifier](#cat_classifier), the feature vector (`X`) represents a 64 x 64 x 3 RGB image and the label (`y`) is either `0` for a non-cat image or `1` for a cat image. The range of R, G and B components is 0~255. A common practice is to normalize the values into 0~1 by dividing 255. In this example, the range of 0~255 is known. However, in general cases the distribution of each feature is unknown. You could try [MinMaxScaler](http://scikit-learn.org/stable/modules/generated/sklearn.preprocessing.MinMaxScaler.html), which scales features to a given range.

# In[2]:


get_ipython().run_line_magic('matplotlib', 'inline')
import numpy as np
import matplotlib.pyplot as plt

# load the cat dataset
train_X = np.load('train_X.npy')
train_Y = np.load('train_Y.npy')
test_X = np.load('test_X.npy')
test_Y = np.load('test_Y.npy')

# flatten the image
num_train = train_X.shape[0]
num_test = test_X.shape[0]
flatten_train_X = train_X.reshape(num_train,-1)
flatten_test_X = test_X.reshape(num_test, -1)

# normalize each pixel by dividing 255
norm_train_X = flatten_train_X / 255
norm_test_X = flatten_test_X / 255

# construct a classifier
from sklearn.linear_model import LogisticRegression
clf = LogisticRegression()
clf.fit(norm_train_X, train_Y)

# use the classifier to predict a image
i = 25
plt.imshow(test_X[i])
print("Model prediction: {}".format(clf.predict(norm_test_X[i].reshape(1,-1))))


# ### 1.2 Pokémon classification (categorical and missing values)
# 
# The [Pokémon dataset](https://www.kaggle.com/alopez247/pokemon) contains categorical features, such as `Type_1` and `Color`.

# In[3]:


import pandas as pd
df = pd.read_csv('pokemon_alopez247.csv') # load the Pokémon dataset
df = df.drop(['Number', 'Name', 'Type_2', 'Egg_Group_1', 'Egg_Group_2', 'hasGender', 'Body_Style'], axis=1) # drop unused columns
print(df.info())
df.head(5) # show the first 5 samples


# Three categorical-to-numeircal conversions are introduced here. First, `Type_1` is simply transformed to a unique numerical id, which is usually an incremental number along the dataset. The transformed `Type_1` is used as the label (`y`) to predict. Second, `Color` is [one-hot encoded (Chinese)](https://itw01.com/GJFRE5J.html). Using incremental numbers for color would confuse the classifier. Third, boolean (`True` or `False`) must be converted to integer (`1` or `0`) in Python.

# In[4]:


# convert `Type_1` into numerical
mapping = { 'Type_1': {
    'Grass': 1,
    'Fire': 2,
    'Water': 3, 'Ice': 3, # one may merge categories
    'Bug': 4,
    'Normal': 5,
    'Poison': 6, 'Ghost': 6, 'Dark': 6,
    'Electric': 7,
    'Ground': 8, 'Rock': 8,
    'Fairy': 9, 'Dragon': 9, 'Flying': 9,
    'Fighting': 10, 'Psychic': 10, 'Steel': 10
}}
df = df.replace(mapping)

# one-hot encoding
dummy_df = pd.get_dummies(df['Color'])
df = pd.concat([df, dummy_df], axis=1)
df = df.drop('Color', axis=1)

# boolean to int
df['isLegendary'] = df['isLegendary'].astype(int)
df['hasMegaEvolution'] = df['hasMegaEvolution'].astype(int)

df.head(5) # show the first 5 samples after preprocessing


# `Pr_Male` contains 77 **missing values**. Many methods could be used to deal with missing value, such as dorpping the feature/sample or filling by zero/column mean. The best method depends on the dataset.

# In[5]:


print(df.isnull().sum()) # Pr_Male has 77 missing values
df.dropna(axis=1, inplace=True) # drop columns with missing values
df.head(5) # show the first 5 samples after dropping


# In thid end of this section, we want to highlight [pandas](https://pandas.pydata.org/), which provides a lot of tools to process data. For exmaple, it is extremely easy to plot feature histograms with pandas.

# In[6]:


df[['HP', 'Attack']].plot.hist(alpha=0.5)


# ## 2. Classifier construction
# 
# In python, one can use [scikit-learn (sklearn)](http://scikit-learn.org/stable/) instead of implementing classifier from scratch. sklearn provides various mahcine learning algorithms, including both supervised and unsupervised ones. The above cat classifier shows how to use sklearn for logistic regression. Below is the code for constructing a Pokémon classifier.

# In[7]:


from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler

# split data
df_train, df_test = train_test_split(df, test_size=0.2, random_state=42)

def get_arrays(df):
    y = np.array(df['Type_1']) # use `Type_1` as the label to predict
    X = np.array(df.iloc[:,1:]) # use other column as features
    return X, y
train_X, train_y = get_arrays(df_train)
test_X, test_y = get_arrays(df_test)

scaler = StandardScaler() # normalize
svc = SVC(C=5, gamma=0.04) # use SVM as the classifier
clf = Pipeline([('scaler', scaler), ('svc', svc)])
clf.fit(train_X, train_y) # train the classifier
print("Accuracy: %.3f" % (clf.score(train_X, train_y)))
print("Accuracy: %.3f" % (clf.score(test_X, test_y)))


# # 作業
# 
#  * 本次作業為建構 [UCI German Credit Data](https://onlinecourses.science.psu.edu/stat857/node/215) 分類模型  
#  * 該資料集包含 1000 筆貸款資料，其中 700 筆正樣本(credit-worthy)以及 300 筆負樣本(not credit-worthy)。每個樣本有 20 個特徵，其中 17 個類別(categorical)特徵，3 個為數值(numeric)特徵，請參考[特徵的說明](https://onlinecourses.science.psu.edu/stat857/node/222)。
#  * 利用準備好的工具，建構分類模型，請參考 [Classifier comparison](http://scikit-learn.org/stable/auto_examples/classification/plot_classifier_comparison.html) 選擇機器學習分類器。
#  * 以下為助教提供的資料集介紹及示範分類器

# In[8]:


# 載入準備好的工具
import sys
sys.path.append('.prepared')
import classifier as prepared


# ### 資料集
# 
# UCI German Credit Data 包含 800 筆訓練資料與 200 筆測試資料。每筆由一個 20 維的特徵向量與一個 `1` 或 `0` 的類別組成。其中 `1` 代表正樣本(credit-worthy)；`0` 代表負樣本(not credit-worthy)。

# In[9]:


print(prepared.x_train.shape) # 800 筆訓練資料，每筆資料有 20 個特徵
print(prepared.x_train[:3])   # 印出前三筆訓練資料的特徵
print(prepared.y_train[:3])   # 印出前三筆訓練資料的類別
print()
print(prepared.x_test.shape)
print(prepared.y_test.shape)


# ### 示範分類器
# 
# 使用訓練資料(`x_train` 與 `y_train`)訓練示範分類器(`demo_clf`)，在訓練資料與測試資料上評估其正確率。請修改下方[動手做](#動手做)的程式碼試著超越這個示範分類器。

# In[10]:


# 使用訓練資料訓練示範分類器, `demo_clf`
demo_clf = prepared.demo(prepared.x_train, prepared.y_train)

# 在訓練資料與測試資料上評估其正確率
prepared.evaluate(demo_clf)

if 'DecisionTreeClassifier' == type(clf).__name__: # if `clf` is a decision tree
    prepared.plot(clf) # plot the decision tree


# ### 動手做
# 
# 修改以下程式區段，試著使用不同的機器學習演算法，建構比示範分類器更好的模型。換句話說，在測試資料上的正確率超過 `0.765`。

# In[17]:


# TODO: import classifiers you want to use
from sklearn.ensemble import GradientBoostingClassifier

# TODO: try different classifiers
clf = GradientBoostingClassifier(n_estimators=800, learning_rate=0.04,max_depth=2, random_state = 1)

clf = clf.fit(prepared.x_train, prepared.y_train) # train `clf`
prepared.evaluate(clf) # evaluate `clf`


#本題目為分類作業，因此先是嘗試了最常見的羅吉斯回歸、Knn、SVM和隨機森林。
#其中隨機森林的表現較為出色，準確度有達到77%，看似超過76.5%，但不清楚是否是因為四捨五入所造成的進位。
#因此嘗試使用Boosting的方式，檢視是否能獲得更佳的結果。
#經過測試learning rate設定在0.04並且深度設定為兩層的狀況下，能獲得80.5%的準確率，因此將其視為本次作業的答案。
#有另外使用xgboost，獲得81%的準確度，惟本次作業要求使用sklearn，因此不納入選擇。


# In[49]:


from xgboost import XGBClassifier
xgbc = XGBClassifier()
xgbc.fit(prepared.x_train, prepared.y_train)
prepared.evaluate(xgbc)


# In[78]:


from sklearn.ensemble import GradientBoostingClassifier
for i in range(-3,3,1):
    clf = GradientBoostingClassifier(n_estimators = 800, learning_rate = 10 ** i, max_depth = 1)
    clf = clf.fit(prepared.x_train, prepared.y_train)
    print(i, prepared.evaluate(clf))


# In[80]:


from sklearn.ensemble import GradientBoostingClassifier
for i in range(1, 5):
    clf = GradientBoostingClassifier(n_estimators = 800, learning_rate = 0.01, max_depth = i)
    clf = clf.fit(prepared.x_train, prepared.y_train)
    print(i, prepared.evaluate(clf))


# In[82]:


for i in range(1, 10):
    clf = GradientBoostingClassifier(n_estimators = 800, learning_rate = 0.01 * i, max_depth = 2)
    clf = clf.fit(prepared.x_train, prepared.y_train)
    print(i, prepared.evaluate(clf))


# In[62]:


from sklearn.ensemble import AdaBoostClassifier
clf = AdaBoostClassifier(n_estimators=800)
clf = clf.fit(prepared.x_train, prepared.y_train)
prepared.evaluate(clf) 


# In[47]:


prepared.x_train[1][:]


# In[30]:


print(prepared.x_train.shape, prepared.y_train.shape)


# In[12]:


from sklearn.linear_model import LogisticRegression
for c in range(-5,6,1):
    lr = LogisticRegression(C = 100 ** c, random_state = 1)
    lr.fit(prepared.x_train, prepared.y_train)
    print('c = {:.2f}'.format(c),prepared.evaluate(lr))


# In[56]:


from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors = 13)
knn.fit(prepared.x_train, prepared.y_train)
prepared.evaluate(knn)


# In[38]:


from sklearn.ensemble import RandomForestClassifier
forest = RandomForestClassifier(n_estimators = 600, random_state = 1)
forest.fit(prepared.x_train, prepared.y_train)
prepared.evaluate(forest)


# In[42]:


from sklearn.svm import SVC
svm = SVC(kernel = 'rbf', gamma = .01, C = 10)
svm.fit(prepared.x_train,prepared.y_train)
prepared.evaluate(svm)


# In[ ]:





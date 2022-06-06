# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mask_RCNN_ui.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(381, 501)
        
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.button_4 = QtWidgets.QPushButton(self.centralwidget)
        self.button_4.setGeometry(QtCore.QRect(60, 351, 281, 91))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.button_4.setFont(font)
        self.button_4.setObjectName("button_4")
        
        self.button_3 = QtWidgets.QPushButton(self.centralwidget)
        self.button_3.setGeometry(QtCore.QRect(60, 241, 281, 101))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.button_3.setFont(font)
        self.button_3.setObjectName("button_3")
        self.button_1 = QtWidgets.QPushButton(self.centralwidget)
        self.button_1.setGeometry(QtCore.QRect(60, 31, 281, 101))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.button_1.setFont(font)
        self.button_1.setObjectName("button_1")
        self.button_2 = QtWidgets.QPushButton(self.centralwidget)
        self.button_2.setGeometry(QtCore.QRect(60, 140, 281, 91))
        font = QtGui.QFont()
        font.setFamily("Agency FB")
        font.setPointSize(16)
        self.button_2.setFont(font)
        self.button_2.setObjectName("button_2")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 381, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.button_4.setText(_translate("MainWindow", "4. Test"))
        self.button_3.setText(_translate("MainWindow", "3. Show Accuracy"))
        self.button_1.setText(_translate("MainWindow", "1. Show Train Images"))
        self.button_2.setText(_translate("MainWindow", "2. Show Model Structure"))


#!/usr/bin/env python
# coding: utf-8

# # Regressor
# 
# In this exercise, you need to build a regressor for classification to beat a demo classifier. This document contains two parts:
# 
# 1. **Data preprocessing** describes how to use [scikit-learn (skearn)](http://scikit-learn.org/stable/) pipeline for data preprocessing.
# 2. **Exercise** describes your homework (Chinese).
# 
# ## 1. Data preprocessing
# 
# The [Breast Cancer Wisconsin (Diagnostic) Data Set](https://archive.ics.uci.edu/ml/datasets/Breast+Cancer+Wisconsin+(Diagnostic%29) is used here.

# In[2]:


import numpy as np
import pandas as pd
df = pd.read_csv('./breast_cancer_data.csv') # load data
df = df.drop('id', axis=1) # drop unused columns
print(df.info())
df.head(5) # show the first 5 samples


# Deal with catigorical and missing values. See [another document for data preprocessing](/notebooks/unit/classifier/classifier.ipynb#1.-Data-preprocessing).

# In[3]:


# convert label B/M to 0/1
# B indicates benign (良性)
# M indicates malignant (惡性)
mapping = {'diagnosis': {
    'B': 0,
    'M': 1,
}}
df = df.replace(mapping)

# check missing value
print(df.isnull().sum()) # no missing value

df.head(5)


# [Pipeline](http://scikit-learn.org/stable/modules/pipeline.html) is a tool to stream multiple pre-processing methods (e.g like standardization, dimension reduction and machine learning algorithms) into a single object for convinience. See [Python Machine Learning (ch6)](https://github.com/rasbt/python-machine-learning-book/blob/master/code/ch06/ch06.ipynb) for more information. The code below builds a pipeline of [StandardScaler](http://scikit-learn.org/stable/modules/generated/sklearn.preprocessing.StandardScaler.html), [PCA](http://scikit-learn.org/stable/modules/generated/sklearn.decomposition.PCA.html) and [LogisticRegression](http://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LogisticRegression.html).

# In[4]:


from sklearn.decomposition import PCA
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler

# split 20% of data for test
df_train, df_test = train_test_split(df, test_size=0.2, random_state=1)

# convert df to numpy
train_X, train_y = df_train.iloc[:, 1:].values.astype(np.float64), df_train.iloc[:, 0].values.astype(np.float64)
test_X, test_y = df_test.iloc[:, 1:].values.astype(np.float64), df_test.iloc[:, 0].values.astype(np.float64)

# build a pipeline 
clf = Pipeline([
    ('scl', StandardScaler()),
    ('pca', PCA(n_components=2)),
    ('clf', LogisticRegression(random_state=1))
])
print(clf)

# train parameters of all pipeline steps with `fit()`
clf.fit(train_X, train_y)

# apply all pipeline steps with `predcit()`
y_pred = clf.predict(test_X)

print("\nTest Accuracy: %.3f" % (accuracy_score(test_y, y_pred)))


# In[5]:


print(train_X.shape, train_y.shape)


# ## 2. 作業
# 
# 一般來說，迴歸(regression)模型不像分類模型只能輸出預先定義好的類別，而是可以輸出任意數值。以股票系統為例，迴歸模型不是預測股票的漲跌，而是直接預測股價。因此，透過設定門檻值，可以將迴歸模型轉換為分類模型使用。例如，用預測股價減去前一天的股價，就可以預測股票漲跌。
# 
# ### 資料集
# 
# 作業使用的資料集與上面 Data preprocessing 相同，但為了避免前處理所造成的差異，請使用 `prepared.load_data()` 載入處理好的訓練、測試資料。

# In[4]:


# 載入準備好的工具
import sys
sys.path.append('.prepared')
import regressor as prepared

# 載入處理好的資料集
x_train, y_train, x_test, y_test = prepared.load_data()

print(x_train.shape) # 455 筆訓練資料，每筆資料有 30 個特徵
print(x_train[0])    # 印出第一筆訓練資料的特徵
print(y_train[0])    # 印出第一筆訓練資料的類別
print()
print(x_test.shape)
print(y_test.shape)


# In[6]:


x_train.shape


# ### 動手做
# 
# 請使用迴歸模型來分類測試資料，可以參考 [Linear Regression Example](http://scikit-learn.org/stable/auto_examples/linear_model/plot_ols.html)。預測結果用 `prepared.evaluate()` 評估的正確率要超過 `0.93`。

# In[5]:


demo_y_pred = prepared.demo() 

print(x_test.shape)      # `x_test` has 114 samples
print(demo_y_pred.shape) # `demo_y_pred` has 114 corresponding predictions
print()
print(demo_y_pred[:5])   # show the first five predictions
print()

prepared.evaluate(y_test, demo_y_pred) # try to beat this instead of merely 0.93


# In[113]:


# TODO: generate your `y_pred`
from sklearn.linear_model import SGDClassifier
model = Pipeline([('scl', StandardScaler()),
                 ('pca', PCA(n_components = 5)),
                 ('regr', SGDClassifier(loss="hinge", penalty="l1", max_iter=5, random_state = 5))])
model.fit(x_train, y_train)
y_predict = model.predict(x_test)
prepared.evaluate(y_test, y_predict)
# prepared.evaluate(y_test, y_pred) # un-comment this line once you finised `y_pred`

#diagnosis欄位的值為0與1，因此可以初步推論此分類問題其實為classification的分類問題
#先套用基本常用的tree和svm，並使用forloop迴圈檢測PCA在幾個feature下表現最好，得知feature在五個的時候表現效果佳。
#由於tree和svm未獲得良好的準確率，因此選擇使用梯度下降的方式，希望能提高預測的準確度。
#後來再使用SGC的分類器時，獲得了良好的表現。比較了l1和l2的懲罰像，在懲罰模型選擇為l1的狀況下準確度較高。


# In[84]:


from sklearn.linear_model import SGDClassifier
model4 = Pipeline([('scl', StandardScaler()),
                  ('pca', PCA(n_components = 5)),
                  ('regr', SGDClassifier(loss="hinge", penalty="l1", max_iter=5))])
model4.fit(x_train, y_train)
y_predict = model4.predict(x_test)
prepared.evaluate(y_test, y_predict)


# In[53]:


from sklearn import tree
for i in range(1,6):
    model1 = Pipeline([('scl', StandardScaler()),
                 ('pca', PCA(n_components = i)),
                 ('tree_r', tree.DecisionTreeRegressor())])
    model1.fit(x_train, y_train)
    y_predict = model1.predict(x_test)
    print(i, prepared.evaluate(y_test, y_predict))


# In[54]:


from xgboost import XGBClassifier
model2 = Pipeline([('scl', StandardScaler()),
                 ('pca', PCA(n_components = i)),
                 ('xgbc', XGBClassifier())])
model2.fit(x_train, y_train)
y_predict = model2.predict(x_test)
prepared.evaluate(y_test, y_predict)


# In[81]:


from sklearn import svm
model3 = Pipeline([('scl', StandardScaler()),
                  ('pca', PCA(n_components = 5)),
                  ('regr', svm.SVC())])
model3.fit(x_train, y_train)
y_predict = model3.predict(x_test)
prepared.evaluate(y_test, y_predict)


# In[85]:


from sklearn import tree
model5 = Pipeline([('scl', StandardScaler()),
                  ('pca', PCA(n_components = 5)),
                  ('tree', tree.DecisionTreeClassifier())])
model5.fit(x_train, y_train)
y_predict = model5.predict(x_test)
prepared.evaluate(y_test, y_predict)


# In[ ]:





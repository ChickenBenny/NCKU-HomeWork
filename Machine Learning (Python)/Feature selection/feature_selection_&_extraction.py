#!/usr/bin/env python
# coding: utf-8

# # Feature Selection & Extraction
# 
# How much information you provide for model really matters. In Machine Learning, we often have to deal with the [curse of dimensionality](https://en.wikipedia.org/wiki/Curse_of_dimensionality) issue. For example, the following image shows a practical model which delivers worse performance as the dimension increases. Feature selection and extraction are two common methods to solve this issue.
# 
# ![optimal dimension](http://scikit-learn.org/stable/_images/sphx_glr_plot_rfe_with_cross_validation_001.png)
# 
# ## Sequential Feature Selection
# 
# According to the [Wikipedia](https://en.wikipedia.org/wiki/Feature_selection):
# 
# > In machine learning and statistics, feature selection, also known as variable selection, attribute selection or variable subset selection, is the process of selecting a subset of relevant features (variables, predictors) for use in model construction. Feature selection techniques are used for four reasons:
# 
# > * simplification of models to make them easier to interpret by researchers/users,
# > * shorter training times,
# > * to avoid the curse of dimensionality,
# > * enhanced generalization by reducing overfitting (formally, reduction of variance)
# 
# For example, if you have a 20D dataset and you want to visualize it in a 2D plot. You can use feature selection to pick two features with the highest importance. Another practical benefit is that, with less features, you can train your model in less time. Following are two common methods for feature selection: **backward selection** and **forward selection**. You can check [other methods available on sklearn](http://scikit-learn.org/stable/modules/feature_selection.html).
# 
# ### Backward selection
# 
# In backward selection, we starts from all features and remove them one-by-one. Following is a backwrod selection example on a 20D dataset:
#     
# 1. We create 20 19D-datasets by removing each feature indiviudially and use them to generate 20 models.
#  
# ```
# ( fea_02, fea_03, fea_04, fea_05, .... fea_20 ) -> acc_01
# ( fea_01, fea_03, fea_04, fea_05, .... fea_20 ) -> acc_02
#   ....
# ( fea_01, fea_02, fea_03, fea_04, .... fea_19 ) -> acc_20
# ```
#        
# 2. Eliminate the feature corresponding to the model with the highest performance, since the deletion of it is "least" important.
#     
# ```
# feature_index_we_dont_want = argmax( [acc_01, acc_02, ..., acc_20] )
# del features[ feature_index_we_dont_want ]
# ```
#         
# 3. Repeat above steps.
# 
# 
# ### Forward selection
# 
# In comparison with backward selection, forward selection starts from an empty list and add features one-by-one. Each time we add a feature which contributes to performance most.
#     
# 1. We create 20 1D-datasets by adding each feature indiviudially and use them to generate 20 models.
# 
# ```
# ( fea_01 ) -> acc_01
# ( fea_02 ) -> acc_02
#   ....
# ( fea_20 ) -> acc_20
# ```
# 
# 2. Add the feature corresponding to the model with the highest performance, since the addition of it is "most" important.
# 
# ```
# feature_index_we_want = argmmax( [acc_01, acc_02, ..., acc_20] )
# features_we_want.append( feature_index_we_want )
# ```
# 
# 3. Repeat above steps.
#     
# ## Feature selection using SelectFromModel¶
# > The features are considered unimportant and removed, if the corresponding **coef_** or **feature_importances_** values are below the provided threshold parameter.
# 
# > Note: Apart from specifying the threshold numerically, there are built-in heuristics for finding a threshold using a string argument. Available heuristics are “mean”, “median” and float multiples of these like “0.1*mean”.
# 
# ### L1-based feature selection
# > Linear models penalized with the L1 norm have sparse solutions: many of their estimated coefficients are zero. When the goal is to reduce the dimensionality of the data to use with another classifier, they can be used along with [feature_selection.SelectFromModel](http://scikit-learn.org/stable/modules/generated/sklearn.feature_selection.SelectFromModel.html#sklearn.feature_selection.SelectFromModel) to select the non-zero coefficients. 
# 

# In[1]:


from sklearn.svm import LinearSVC
from sklearn.datasets import load_iris
from sklearn.feature_selection import SelectFromModel
iris = load_iris()
X, y = iris.data, iris.target
print(X.shape)
lsvc = LinearSVC(C=0.01, penalty="l1", dual=False).fit(X, y)
model = SelectFromModel(lsvc, prefit=True)
X_new = model.transform(X)


# ### Tree-based feature selection
# > Tree-based estimators (see the [sklearn.tree](http://scikit-learn.org/stable/modules/classes.html#module-sklearn.tree) module and forest of trees in the [sklearn.ensemble](http://scikit-learn.org/stable/modules/classes.html#module-sklearn.ensemble) module) can be used to compute feature importances, which in turn can be used to discard irrelevant features.

# In[2]:


from sklearn.ensemble import ExtraTreesClassifier
from sklearn.datasets import load_iris
from sklearn.feature_selection import SelectFromModel
iris = load_iris()
X, y = iris.data, iris.target
print(X.shape)

clf = ExtraTreesClassifier()
clf = clf.fit(X, y)
clf.feature_importances_  

model = SelectFromModel(clf, prefit=True)
X_new = model.transform(X)
print(X_new.shape)


# ## Feature Extraction
# 
# According to the [Wikipedia](https://en.wikipedia.org/wiki/Feature_extraction):
# 
# > In machine learning, pattern recognition and in image processing, feature extraction starts from an initial set of measured data and builds derived values (features) intended to be informative and non-redundant, facilitating the subsequent learning and generalization steps, and in some cases leading to better human interpretations. Feature extraction is a dimensionality reduction process, where an initial set of raw variables is reduced to more manageable groups (features) for processing, while still accurately and completely describing the original data set.
# 
# In comparison with feature selection, feature extraction may create new features of which a new feature could be a linear combination of several existing ones. The most famous feature extraction algorithm is [Principal Component Analysis](https://en.wikipedia.org/wiki/Principal_component_analysis). You may see [other feature extraction algorithms](https://www.sciencedirect.com/science/article/pii/0031320371900033). The code below shows a PCA example with sklearn: 

# In[3]:


from sklearn.decomposition import PCA
from sklearn.datasets.samples_generator import make_blobs
import numpy as np

original_x, y = make_blobs(n_samples=500, centers=3, n_features=20)
pca = PCA(n_components=2)
pca.fit(original_x)
reduced_x = pca.transform(original_x)
print("original shape is ", original_x.shape, ", the shape after extraction is ", reduced_x.shape)


# ## Using k-fold cross validation to assess model performance
# 
# ### The holdout method
# ![image.png](./holdout.png)
# ### K-fold cross-validation
# ![image.png](./img.png)

# In[1]:


import sys
sys.path.append('.prepared')
import demo as prepared


# ## Exercise
# 
# Fill in the TODO segements in the following code cell, which uses backward selection to filter out 18 features and leave 2 features.  You can use accuracy of either 10-fold corss-validation or train-test to select features.

# In[50]:


from sklearn.datasets.samples_generator import make_blobs
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score
import numpy as np

n_features = 20
x, y = make_blobs(n_samples=500, centers=3, n_features=n_features, random_state=3, cluster_std=5)
classifier = GaussianNB() # in order to save time and computation power, please fix the model to GNB

print('Select by accuracy of cross validation (10 fold)')
prepared.select_by_cv(classifier, x, y, 2)

print()
print('Select by accuracy on testing data')
train_x, train_y, test_x, test_y = x[:400], y[:400], x[400:], y[400:]
prepared.select_by_test_accuracy(classifier, train_x, train_y, test_x, test_y, 2)

# you should implement the function like Recursive Feature Elimination in sklearn
# http://scikit-learn.org/stable/auto_examples/feature_selection/plot_rfe_with_cross_validation.html

print('-----------------------------------------------------------------------------------------------------')
# external loop to remove feature once at a time
#先做select by accuracy of cross validation的feature selection
feature_selection = train_x  #複製一份train_x拿來刪除column，避免影響原始資料
feature_index = np.arange(20).reshape(1, 20) #與刪除的時候同步，這樣才能知道刪除的是哪一個feature
for n_remove_fea in range(0, n_features - 2):
    score_compare = [] #先創出一個拿來計分用的list
    # internal loop to compare the performance of each feature
    for i in range(0, n_features - n_remove_fea):
        tmp_x = np.delete(feature_selection, i, axis = 1)
        scores = cross_val_score(classifier, tmp_x, train_y, cv = 10).mean()
        score_compare.append(scores)
        # TODO: delete the feature you are testing, hint: np.delete
        #pass  comment this line after filling in the TODO segments
    feature_selection = np.delete(feature_selection, np.argmax(score_compare), axis = 1) 
    #將剛剛分數最高的feature刪除，表示少了那個feature，training的效果變成最好
    feature_index = np.delete(feature_index, np.argmax(score_compare), axis = 1)
    #同步刪除feature裡面的index，以免進行下一次迭代的時候不知道刪除的是哪個feature
print(f'Homework : Select by accuracy of cross validation (10 fold)')
print(f'Homework : Remain features {feature_index}')


feature_selection = train_x  #複製一份train_x拿來刪除column，避免影響原始資料
feature_index = np.arange(20).reshape(1, 20) #與刪除的時候同步，這樣才能知道刪除的是哪一個feature
tmp_test = test_x


for n_remove_fea in range(0, n_features - 2):
    score_compare = [] #先創出一個拿來計分用的list
    # internal loop to compare the performance of each feature
    
    for i in range(0, n_features - n_remove_fea):
        tmp_train_x = np.delete(feature_selection, i, axis = 1)
        classifier.fit(tmp_train_x, train_y)
        
        tmp_test_x = np.delete(tmp_test, i, axis = 1)
        y_predict = classifier.predict(tmp_test_x)
        
        scores = accuracy_score(test_y, y_predict)
        score_compare.append(scores)
        # TODO: delete the feature you are testing, hint: np.delete
        #pass  comment this line after filling in the TODO segments
    feature_selection = np.delete(feature_selection, np.argmax(score_compare), axis = 1) 
    tmp_test = np.delete(tmp_test, np.argmax(score_compare), axis = 1)
    #將剛剛分數最高的feature刪除，表示少了那個feature，training的效果變成最好
    feature_index = np.delete(feature_index, np.argmax(score_compare), axis = 1)
    #同步刪除feature裡面的index，以免進行下一次迭代的時候不知道刪除的是哪個feature
print(f'Homework : Select by accuracy on testing data')
print(f'Homework : Remain features {feature_index}')


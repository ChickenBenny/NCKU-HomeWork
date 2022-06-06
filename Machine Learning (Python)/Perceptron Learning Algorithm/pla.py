#!/usr/bin/env python
# coding: utf-8

# # Perceptron Learning Algorithm (PLA) 演算法
# 
# 利用準備好的工具，實作 PLA 演算法，演算法細節可以參考林軒田老師的[機器學習基石](https://www.youtube.com/watch?v=WlpF1Phkv28&list=PLXVfgk9fNX2I7tB6oIINGBmW50rrmFTqf&index=6)影片。
# 
# # 二維 PLA 展示

# In[3]:


# 載入準備好的工具
import sys
sys.path.append('.prepared')
import pla as prepared


# In[4]:


# 重置預先準備好的 PLA 示範模型
prepared.reset()


# In[20]:


# 更新該 PLA 模型
prepared.update()

# 繪製該 PLA 模型
prepared.plot()

# 執行多次觀察 PLA 模型迭代的過程，收斂後可以執行上面程式區段執行重置模型


# # 動手做
# 
# 完成下面程式區段的 `pla()`，並用其取代 `prepared.demo()`。注意由上往下尋找預測錯誤的資料，更新之後從下一筆繼續尋找，答案才會跟 `prepared.demo()` 完全一致。

# In[25]:


import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

def pla():
    # TODO: start coding here... 
    # the first thing is to read `pla.dat`
    train_data = './pla.dat'
    pla_data = pd.read_csv(train_data, header = None, sep =' ')
    pla_data = pla_data.values
    w = np.zeros(5)
    error = 1
    iterator = 0
    while error:
        error = 0
        for i in range(len(pla_data)):
            x = np.concatenate((np.array([1.]), np.array(pla_data[i][:-1])))
            y = np.dot(w, x)
            label = np.array(pla_data[i][-1])
            if np.sign(y) != np.sign(label):
                iterator += 1
                error = 1
                w += label * x
        if error == 1:
            continue
        else:
            break
    print('#',iterator, w)
    return(w)

if True: # TODO: change `False` to `True` once you finish `pla()`
    pla()
else:
    prepared.demo()


# In[ ]:





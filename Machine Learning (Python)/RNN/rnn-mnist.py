#!/usr/bin/env python
# coding: utf-8

# ## Recurrent Neural Network - RNN
# - Can deal with sequence data
# - Variants: LSTM, GRU
# > [Suggested Readings for beginner](http://colah.github.io/posts/2015-08-Understanding-LSTMs/)
# ![42741-b9a16a53d58ca2b9.png](attachment:42741-b9a16a53d58ca2b9.png)

# In[1]:


from keras.layers import LSTM
from keras.optimizers import Adam
from keras.layers import Dense, Activation
from keras.models import Sequential
from keras.datasets import mnist
from keras.utils import np_utils
import matplotlib.pyplot as plt 
import numpy as np


# In[2]:


(x_train, y_train), (x_test, y_test) = mnist.load_data()
nor_x_train = x_train
nor_y_train = y_train
nor_x_test = x_test
nor_y_test = y_test

## Reshape nor_x_train
n_input = 28
n_step = 28

rnn_x_train = nor_x_train.reshape(-1, n_step, n_input) # We will input 28 * 28 to RNN by 28 pixel at first step, 
rnn_x_test = nor_x_test.reshape(-1, n_step, n_input)   # and next 28 at second step, ... until 28th step, 
                                                       # then we are done with one input sample(image).
vec_y_train = np_utils.to_categorical(nor_y_train, num_classes = 10)
vec_y_test = np_utils.to_categorical(nor_y_test, num_classes = 10)


# In[3]:


n_hidden = 128
learning_rate = 0.001
training_iters = 5 #20
batch_size = 128


model = Sequential()
model.add(LSTM(n_hidden,
               batch_input_shape=(None, n_step, n_input),
               unroll=True))

model.add(Dense(10))
model.add(Activation('softmax'))
model.summary()


# In[4]:


adam = Adam(lr=learning_rate)
model.compile(optimizer=adam,
              loss='categorical_crossentropy',
              metrics=['accuracy'])

model.fit(rnn_x_train, vec_y_train,
          batch_size=batch_size,
          epochs=training_iters,
          verbose=1,
          validation_split=0.2)


# In[5]:


scores = model.evaluate(rnn_x_test, vec_y_test, verbose=0)
print('LSTM test score:', scores[0])
print('LSTM test accuracy:', scores[1])


# In[6]:


nor_x_test_reshape = x_test


# In[7]:


rnn_pred_index = 5
rnn_pred = model.predict_on_batch(nor_x_test_reshape[rnn_pred_index].reshape(-1, 28, 28))
plt.imshow(x_test[rnn_pred_index], cmap="gray")
print("Label is {}.".format(np.argmax(rnn_pred)))


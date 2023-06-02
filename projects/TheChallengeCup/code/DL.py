import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import math
import sys
import matplotlib.pyplot as plt
from math import sqrt
from matplotlib import pyplot
import pandas as pd
from numpy import concatenate
from sklearn.preprocessing import MinMaxScaler
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score
from keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation
from keras.optimizers import adam_v2
from numpy import exp
from keras.models import Sequential
from keras.layers import Dense
from keras.callbacks import EarlyStopping
from sklearn.model_selection import train_test_split
from keras.models import load_model
from sklearn import metrics
from keras.utils.vis_utils import plot_model

def getSrcData():
    file_name = "../data/data1.xlsx"

    data = pd.read_excel(file_name)

    return data

def splitData(data):
    global sampleout, scaler
    samplein = np.mat([
        data["date"].values,
        data["D_encoded"].values,
        data["R_encoded"].values,
    ])
    sampleout = np.mat([
        data['快递运输数量(件) (Express delivery quantity (PCS))']

    ])

    return samplein, sampleout


def plot():
    # loss曲线
    pyplot.plot(history.history['loss'], label='train')
    pyplot.plot(history.history['val_loss'], label='test')
    pyplot.title('Model loss')
    pyplot.ylabel('Loss')
    pyplot.xlabel('Epoch')
    pyplot.legend()
    pyplot.show()
    # 预测
    yhat = model.predict(test_x)

    # 预测y 逆标准化
    inv_yhat = scaler_y.inverse_transform(yhat)
    # inv_yhat = inv_yhat[:, -1]

    # 原始y逆标准化
    inv_y = scaler_y.inverse_transform(test_y)
    # inv_y = inv_y[:, -1]

    # r_2 = r2_score(inv_y, inv_yhat)
    # print('Test r_2: %.3f' % r_2)
    # # 计算MAE
    # mae = mean_absolute_error(inv_y, inv_yhat)
    # print('Test MAE: %.3f' % mae)
    # # 计算RMSE
    # rmse = sqrt(mean_squared_error(inv_y, inv_yhat))
    # print('Test RMSE: %.3f' % rmse)
    # # plt.plot(inv_y)
    # # plt.plot(inv_yhat)
    # # plt.show()

    print('Mean Absolute Error:', metrics.mean_absolute_error(inv_y, inv_yhat))
    print('Mean Squared Error:', metrics.mean_squared_error(inv_y, inv_yhat))
    print('Root Mean Squared Error:',
          np.sqrt(metrics.mean_squared_error(inv_y, inv_yhat)))
    print("RMSE", metrics.mean_squared_error(inv_y, inv_yhat) ** 0.5)
    print("R2", 1 - metrics.mean_squared_error(inv_y, inv_yhat) / np.var(inv_y))

    inv_y = inv_y.T
    inv_yhat = inv_yhat.T
    plt.figure(2)
    # 绘制误差曲线
    plt.plot(inv_y[0][:50], label='train PCS')
    plt.plot(inv_yhat[0][:50], label='validation PCS')
    # 添加标题和标签
    plt.title('Training and Validation Errors (Just top fifty)')
    plt.xlabel('Epoch')
    plt.ylabel('Error')
    # 添加图例和网格线
    plt.legend()
    plt.grid()
    # 展示图像
    plt.show()

    # 绘制误差曲线
    plt.plot(inv_y[0], label='train PCS')
    plt.plot(inv_yhat[0], label='validation PCS')
    # 添加标题和标签
    plt.title('Training and Validation Errors')
    plt.xlabel('Epoch')
    plt.ylabel('Error')
    # 添加图例和网格线
    plt.legend()
    plt.grid()
    # 展示图像
    plt.show()

    # plt.subplot(1, 1, 1)
    #
    # plt.plot(inv_y[0],
    #          color="blue",
    #          linewidth=1.5,
    #          linestyle="-",
    #          label=u"real PCS")
    #
    # plt.plot(inv_yhat[0],
    #          color="orange",
    #          linewidth=1.5,
    #          linestyle="--",
    #          label=u"predict PCS")
    #
    # plt.legend(loc='upper left')





    # 展示第 2 张图；
    plt.show()


if __name__ == "__main__":
    global sampleoutminmax, networkPredict
    # 如果需要使用训练好的模型
    #model = load_model('../model/my_model.h5')
    # 获取原始数据
    data = getSrcData()
    # 分开模型输入输出
    sampleinnorm, sampleoutnorm = splitData(data)
    # 分割训练集与测试集
    train_x, test_x, train_y, test_y = train_test_split(sampleinnorm.T, sampleoutnorm.T, test_size=0.2)
    # 标准化神经网络参数
    scaler_x = MinMaxScaler(feature_range=(0, 1))
    scaler_y = MinMaxScaler(feature_range=(0, 1))
    train_x = scaler_x.fit_transform(train_x)
    test_x = scaler_x.fit_transform(test_x)
    train_y = scaler_y.fit_transform(train_y)
    test_y = scaler_y.fit_transform(test_y)

    # 设置神经网络训练结构
    N = 256  # 设置隐藏层神经元数
    model = Sequential()
    input = train_x.shape[1]
    model.add(Dense(N, input_shape=(input,)))
    model.add(Activation('PReLU'))
    model.add(Dropout(0.1))
    model.add(Dense(N))
    model.add(Activation('PReLU'))
    model.add(Dropout(0.2))
    model.add(Dense(N))
    model.add(Activation('PReLU'))
    model.add(Dropout(0.2))

    ouput = train_y.shape[1]
    model.add(Dense(ouput))



    # 设置神经网络训练参数
    # 使用高效的ADAM优化算法以及优化的最小均方误差损失函数
    model.compile(loss='mean_squared_error', optimizer=adam_v2.Adam())
    early_stopping = EarlyStopping(monitor='val_loss', patience=50, verbose=2)
    history = model.fit(train_x, train_y, epochs=1000, batch_size=32,
                        validation_data=(test_x, test_y), verbose=2,
                        shuffle=False, callbacks=[early_stopping])
    # 画loss图
    plot()
    # 设置需要预测的数据
    test = pd.read_excel("../data/D2R.xlsx")
    test_data_273 = np.mat([
        [],
        [],
        [],
    ]).T
    test_data_274 = np.mat([
        [],
        [],
        [],
    ]).T
    for index, row in test.iterrows():
        date = 273
        D = ord(row['Delivering']) - 65
        R = ord(row['Receiving']) - 65
        new_element = np.array([date, D, R])
        test_data_273 = np.append(test_data_273, [new_element], axis=0)
    for index, row in test.iterrows():
        date = 274
        D = ord(row['Delivering']) - 65
        R = ord(row['Receiving']) - 65
        new_element = np.array([date, D, R])
        test_data_274 = np.append(test_data_274, [new_element], axis=0)


    test_data_273 = scaler_x.fit_transform(test_data_273)
    y_pred_273 = model.predict(test_data_273)
    inv_y_pred_273 = scaler_y.inverse_transform(y_pred_273)
    print(inv_y_pred_273.T)
    print(np.sum(inv_y_pred_273))


    test_data_274 = scaler_x.fit_transform(test_data_274)
    y_pred_274 = model.predict(test_data_274)
    inv_y_pred_274 = scaler_y.inverse_transform(y_pred_274)
    print(inv_y_pred_274.T)
    print(np.sum(inv_y_pred_274))



    # 打印网络结构图
    # plot_model(model, to_file="../picture/model.png", show_shapes=True)
    # 打印模型权重





    # model.save(r"C:\Users\huhu\Desktop\2022华数杯\model\model2.h5", overwrite=True)
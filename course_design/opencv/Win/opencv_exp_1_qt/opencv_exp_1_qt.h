#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_opencv_exp_1_qt.h"
#include <QLabel>
#include <QPixmap>
#include <QSlider>
#include <opencv2/opencv.hpp>

class opencv_exp_1_qt : public QMainWindow
{
    Q_OBJECT

public:
    opencv_exp_1_qt(QWidget *parent = nullptr);
    ~opencv_exp_1_qt();

private:
    Ui::opencv_exp_1_qtClass ui;
};

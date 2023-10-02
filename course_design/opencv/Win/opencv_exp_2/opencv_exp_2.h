#pragma once

#include <opencv2/opencv.hpp>

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "ui_opencv_exp_2.h"

class opencv_exp_2 : public QMainWindow
{
    Q_OBJECT

public:
    opencv_exp_2(QWidget *parent = nullptr);
    ~opencv_exp_2();

private:
    Ui::opencv_exp_2Class ui;
    cv::Mat image;
};

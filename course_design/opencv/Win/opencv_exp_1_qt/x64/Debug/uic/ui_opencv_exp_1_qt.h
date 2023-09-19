/********************************************************************************
** Form generated from reading UI file 'opencv_exp_1_qt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCV_EXP_1_QT_H
#define UI_OPENCV_EXP_1_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_opencv_exp_1_qtClass
{
public:
    QWidget *centralWidget;
    QLabel *image_label;
    QGroupBox *groupBox;
    QSlider *brightness_slider;
    QGroupBox *groupBox_2;
    QSlider *blur_slider;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *opencv_exp_1_qtClass)
    {
        if (opencv_exp_1_qtClass->objectName().isEmpty())
            opencv_exp_1_qtClass->setObjectName(QString::fromUtf8("opencv_exp_1_qtClass"));
        opencv_exp_1_qtClass->resize(600, 400);
        centralWidget = new QWidget(opencv_exp_1_qtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        image_label = new QLabel(centralWidget);
        image_label->setObjectName(QString::fromUtf8("image_label"));
        image_label->setGeometry(QRect(30, 10, 301, 321));
        image_label->setFrameShape(QFrame::Box);
        image_label->setLineWidth(3);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(370, 10, 191, 51));
        brightness_slider = new QSlider(groupBox);
        brightness_slider->setObjectName(QString::fromUtf8("brightness_slider"));
        brightness_slider->setGeometry(QRect(10, 20, 171, 22));
        brightness_slider->setOrientation(Qt::Horizontal);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 70, 191, 51));
        blur_slider = new QSlider(groupBox_2);
        blur_slider->setObjectName(QString::fromUtf8("blur_slider"));
        blur_slider->setGeometry(QRect(10, 20, 171, 22));
        blur_slider->setOrientation(Qt::Horizontal);
        opencv_exp_1_qtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(opencv_exp_1_qtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        opencv_exp_1_qtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(opencv_exp_1_qtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        opencv_exp_1_qtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(opencv_exp_1_qtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        opencv_exp_1_qtClass->setStatusBar(statusBar);

        retranslateUi(opencv_exp_1_qtClass);

        QMetaObject::connectSlotsByName(opencv_exp_1_qtClass);
    } // setupUi

    void retranslateUi(QMainWindow *opencv_exp_1_qtClass)
    {
        opencv_exp_1_qtClass->setWindowTitle(QCoreApplication::translate("opencv_exp_1_qtClass", "OPENCV-\347\224\250\346\210\267\344\272\244\344\272\222\347\252\227\345\217\243(with QT)", nullptr));
        image_label->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("opencv_exp_1_qtClass", "\344\272\256\345\272\246", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("opencv_exp_1_qtClass", "\346\250\241\347\263\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class opencv_exp_1_qtClass: public Ui_opencv_exp_1_qtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCV_EXP_1_QT_H

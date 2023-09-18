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
    QSlider *brightnessSlider;
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
        image_label->setGeometry(QRect(10, 10, 361, 321));
        brightnessSlider = new QSlider(centralWidget);
        brightnessSlider->setObjectName(QString::fromUtf8("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(430, 40, 160, 22));
        brightnessSlider->setOrientation(Qt::Horizontal);
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
        opencv_exp_1_qtClass->setWindowTitle(QCoreApplication::translate("opencv_exp_1_qtClass", "opencv_exp_1_qt", nullptr));
        image_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class opencv_exp_1_qtClass: public Ui_opencv_exp_1_qtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCV_EXP_1_QT_H

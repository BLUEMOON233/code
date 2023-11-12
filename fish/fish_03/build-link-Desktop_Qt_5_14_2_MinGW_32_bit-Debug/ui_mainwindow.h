/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *PB_led;
    QPushButton *PB_beep;
    QPushButton *PB_ii2c;
    QStackedWidget *stackedWidget;
    QWidget *page_0;
    QPushButton *PB_ret;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PB_led = new QPushButton(centralwidget);
        PB_led->setObjectName(QString::fromUtf8("PB_led"));
        PB_led->setGeometry(QRect(10, 20, 151, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        PB_led->setFont(font);
        PB_beep = new QPushButton(centralwidget);
        PB_beep->setObjectName(QString::fromUtf8("PB_beep"));
        PB_beep->setGeometry(QRect(170, 20, 141, 51));
        PB_beep->setFont(font);
        PB_ii2c = new QPushButton(centralwidget);
        PB_ii2c->setObjectName(QString::fromUtf8("PB_ii2c"));
        PB_ii2c->setGeometry(QRect(320, 20, 321, 51));
        PB_ii2c->setFont(font);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 80, 761, 501));
        page_0 = new QWidget();
        page_0->setObjectName(QString::fromUtf8("page_0"));
        stackedWidget->addWidget(page_0);
        PB_ret = new QPushButton(centralwidget);
        PB_ret->setObjectName(QString::fromUtf8("PB_ret"));
        PB_ret->setGeometry(QRect(650, 20, 141, 51));
        PB_ret->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\270\273\347\250\213\345\272\217", nullptr));
        PB_led->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        PB_beep->setText(QCoreApplication::translate("MainWindow", "BEEP", nullptr));
        PB_ii2c->setText(QCoreApplication::translate("MainWindow", "ii2c_ap3216c_sensor", nullptr));
        PB_ret->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

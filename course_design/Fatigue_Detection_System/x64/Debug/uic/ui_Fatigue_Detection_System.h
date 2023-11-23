/********************************************************************************
** Form generated from reading UI file 'Fatigue_Detection_System.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FATIGUE_DETECTION_SYSTEM_H
#define UI_FATIGUE_DETECTION_SYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fatigue_Detection_SystemClass
{
public:
    QWidget *centralWidget;
    QPushButton *PB_getFilePath;
    QLabel *LB_ori;
    QPushButton *PB_playVideo;
    QLabel *LB_face;
    QLabel *LB_mouth;
    QLabel *LB_eye;
    QLabel *word_1;
    QLabel *word_2;
    QLabel *LB_bps;
    QLabel *LB_yawn;
    QSlider *slider;
    QLabel *word_3;
    QLabel *LB_blinkcnt;

    void setupUi(QMainWindow *Fatigue_Detection_SystemClass)
    {
        if (Fatigue_Detection_SystemClass->objectName().isEmpty())
            Fatigue_Detection_SystemClass->setObjectName(QString::fromUtf8("Fatigue_Detection_SystemClass"));
        Fatigue_Detection_SystemClass->resize(1920, 1080);
        Fatigue_Detection_SystemClass->setMinimumSize(QSize(1920, 1080));
        Fatigue_Detection_SystemClass->setMaximumSize(QSize(1920, 1080));
        centralWidget = new QWidget(Fatigue_Detection_SystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PB_getFilePath = new QPushButton(centralWidget);
        PB_getFilePath->setObjectName(QString::fromUtf8("PB_getFilePath"));
        PB_getFilePath->setGeometry(QRect(30, 40, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        PB_getFilePath->setFont(font);
        LB_ori = new QLabel(centralWidget);
        LB_ori->setObjectName(QString::fromUtf8("LB_ori"));
        LB_ori->setGeometry(QRect(40, 100, 441, 701));
        LB_ori->setFrameShape(QFrame::Panel);
        LB_ori->setFrameShadow(QFrame::Sunken);
        LB_ori->setLineWidth(2);
        LB_ori->setMidLineWidth(9);
        PB_playVideo = new QPushButton(centralWidget);
        PB_playVideo->setObjectName(QString::fromUtf8("PB_playVideo"));
        PB_playVideo->setGeometry(QRect(140, 40, 101, 41));
        PB_playVideo->setFont(font);
        LB_face = new QLabel(centralWidget);
        LB_face->setObjectName(QString::fromUtf8("LB_face"));
        LB_face->setGeometry(QRect(510, 150, 400, 400));
        LB_face->setFrameShape(QFrame::Panel);
        LB_face->setFrameShadow(QFrame::Sunken);
        LB_face->setLineWidth(2);
        LB_face->setMidLineWidth(9);
        LB_mouth = new QLabel(centralWidget);
        LB_mouth->setObjectName(QString::fromUtf8("LB_mouth"));
        LB_mouth->setGeometry(QRect(930, 150, 400, 400));
        LB_mouth->setFrameShape(QFrame::Panel);
        LB_mouth->setFrameShadow(QFrame::Sunken);
        LB_mouth->setLineWidth(2);
        LB_mouth->setMidLineWidth(9);
        LB_eye = new QLabel(centralWidget);
        LB_eye->setObjectName(QString::fromUtf8("LB_eye"));
        LB_eye->setGeometry(QRect(1350, 150, 400, 400));
        LB_eye->setFrameShape(QFrame::Panel);
        LB_eye->setFrameShadow(QFrame::Sunken);
        LB_eye->setLineWidth(2);
        LB_eye->setMidLineWidth(9);
        word_1 = new QLabel(centralWidget);
        word_1->setObjectName(QString::fromUtf8("word_1"));
        word_1->setGeometry(QRect(500, 580, 261, 61));
        QFont font1;
        font1.setPointSize(20);
        word_1->setFont(font1);
        word_2 = new QLabel(centralWidget);
        word_2->setObjectName(QString::fromUtf8("word_2"));
        word_2->setGeometry(QRect(500, 640, 241, 61));
        word_2->setFont(font1);
        LB_bps = new QLabel(centralWidget);
        LB_bps->setObjectName(QString::fromUtf8("LB_bps"));
        LB_bps->setGeometry(QRect(760, 580, 101, 61));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        LB_bps->setFont(font2);
        LB_yawn = new QLabel(centralWidget);
        LB_yawn->setObjectName(QString::fromUtf8("LB_yawn"));
        LB_yawn->setGeometry(QRect(760, 640, 131, 61));
        LB_yawn->setFont(font2);
        slider = new QSlider(centralWidget);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setGeometry(QRect(90, 920, 1091, 21));
        slider->setOrientation(Qt::Horizontal);
        word_3 = new QLabel(centralWidget);
        word_3->setObjectName(QString::fromUtf8("word_3"));
        word_3->setGeometry(QRect(510, 700, 241, 61));
        word_3->setFont(font1);
        LB_blinkcnt = new QLabel(centralWidget);
        LB_blinkcnt->setObjectName(QString::fromUtf8("LB_blinkcnt"));
        LB_blinkcnt->setGeometry(QRect(760, 700, 101, 61));
        LB_blinkcnt->setFont(font2);
        Fatigue_Detection_SystemClass->setCentralWidget(centralWidget);

        retranslateUi(Fatigue_Detection_SystemClass);

        QMetaObject::connectSlotsByName(Fatigue_Detection_SystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *Fatigue_Detection_SystemClass)
    {
        Fatigue_Detection_SystemClass->setWindowTitle(QCoreApplication::translate("Fatigue_Detection_SystemClass", "Fatigue_Detection_System", nullptr));
        PB_getFilePath->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        LB_ori->setText(QString());
        PB_playVideo->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "\346\222\255\346\224\276\350\247\206\351\242\221", nullptr));
        LB_face->setText(QString());
        LB_mouth->setText(QString());
        LB_eye->setText(QString());
        word_1->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "\347\234\250\347\234\274\351\242\221\347\216\207\357\274\210\346\254\241/\347\247\222\357\274\211\357\274\232", nullptr));
        word_2->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "\346\230\257\345\220\246\346\211\223\345\223\210\346\254\240\357\274\232", nullptr));
        LB_bps->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "0.000", nullptr));
        LB_yawn->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "\346\262\241\346\211\223\346\262\241\346\211\223", nullptr));
        word_3->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "\347\234\250\347\234\274\346\214\201\347\273\255\346\227\266\351\227\264\357\274\232", nullptr));
        LB_blinkcnt->setText(QCoreApplication::translate("Fatigue_Detection_SystemClass", "0.000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fatigue_Detection_SystemClass: public Ui_Fatigue_Detection_SystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FATIGUE_DETECTION_SYSTEM_H

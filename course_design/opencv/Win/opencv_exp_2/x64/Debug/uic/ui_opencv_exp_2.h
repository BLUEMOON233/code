/********************************************************************************
** Form generated from reading UI file 'opencv_exp_2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCV_EXP_2_H
#define UI_OPENCV_EXP_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_opencv_exp_2Class
{
public:
    QWidget *centralWidget;
    QLabel *LB_ori;
    QLabel *LB_aft;
    QLabel *label;
    QLabel *label_2;
    QPushButton *PB_read;
    QLabel *LB_pix_ori;
    QLabel *LB_pix_aft;
    QLineEdit *LE_dx;
    QLineEdit *LE_dy;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *PB_trans;
    QLabel *label_5;
    QLineEdit *LE_scale_factor;
    QPushButton *PB_scale;
    QLabel *label_6;
    QLineEdit *LE_spin;
    QPushButton *PB_spin;
    QPushButton *PB_fix;

    void setupUi(QMainWindow *opencv_exp_2Class)
    {
        if (opencv_exp_2Class->objectName().isEmpty())
            opencv_exp_2Class->setObjectName(QString::fromUtf8("opencv_exp_2Class"));
        opencv_exp_2Class->resize(1280, 720);
        opencv_exp_2Class->setMinimumSize(QSize(1280, 720));
        opencv_exp_2Class->setMaximumSize(QSize(1280, 720));
        centralWidget = new QWidget(opencv_exp_2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LB_ori = new QLabel(centralWidget);
        LB_ori->setObjectName(QString::fromUtf8("LB_ori"));
        LB_ori->setGeometry(QRect(20, 50, 580, 500));
        LB_ori->setFrameShape(QFrame::Box);
        LB_ori->setFrameShadow(QFrame::Raised);
        LB_ori->setLineWidth(10);
        LB_aft = new QLabel(centralWidget);
        LB_aft->setObjectName(QString::fromUtf8("LB_aft"));
        LB_aft->setGeometry(QRect(680, 50, 580, 500));
        LB_aft->setFrameShape(QFrame::Box);
        LB_aft->setFrameShadow(QFrame::Raised);
        LB_aft->setLineWidth(10);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 121, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(680, 20, 121, 21));
        label_2->setFont(font);
        PB_read = new QPushButton(centralWidget);
        PB_read->setObjectName(QString::fromUtf8("PB_read"));
        PB_read->setGeometry(QRect(20, 560, 111, 71));
        PB_read->setFont(font);
        LB_pix_ori = new QLabel(centralWidget);
        LB_pix_ori->setObjectName(QString::fromUtf8("LB_pix_ori"));
        LB_pix_ori->setGeometry(QRect(350, 10, 171, 31));
        QFont font1;
        font1.setPointSize(14);
        LB_pix_ori->setFont(font1);
        LB_pix_ori->setAutoFillBackground(true);
        LB_pix_ori->setFrameShape(QFrame::Panel);
        LB_pix_aft = new QLabel(centralWidget);
        LB_pix_aft->setObjectName(QString::fromUtf8("LB_pix_aft"));
        LB_pix_aft->setGeometry(QRect(1080, 10, 171, 31));
        LB_pix_aft->setFont(font1);
        LB_pix_aft->setAutoFillBackground(true);
        LB_pix_aft->setFrameShape(QFrame::Panel);
        LE_dx = new QLineEdit(centralWidget);
        LE_dx->setObjectName(QString::fromUtf8("LE_dx"));
        LE_dx->setGeometry(QRect(240, 560, 81, 31));
        LE_dx->setFont(font1);
        LE_dy = new QLineEdit(centralWidget);
        LE_dy->setObjectName(QString::fromUtf8("LE_dy"));
        LE_dy->setGeometry(QRect(240, 600, 81, 31));
        LE_dy->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 570, 91, 21));
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 610, 91, 21));
        label_4->setFont(font);
        PB_trans = new QPushButton(centralWidget);
        PB_trans->setObjectName(QString::fromUtf8("PB_trans"));
        PB_trans->setGeometry(QRect(330, 560, 111, 71));
        PB_trans->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(450, 570, 91, 21));
        label_5->setFont(font);
        LE_scale_factor = new QLineEdit(centralWidget);
        LE_scale_factor->setObjectName(QString::fromUtf8("LE_scale_factor"));
        LE_scale_factor->setGeometry(QRect(550, 560, 81, 31));
        LE_scale_factor->setFont(font1);
        PB_scale = new QPushButton(centralWidget);
        PB_scale->setObjectName(QString::fromUtf8("PB_scale"));
        PB_scale->setGeometry(QRect(640, 560, 111, 71));
        PB_scale->setFont(font);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(760, 570, 91, 21));
        label_6->setFont(font);
        LE_spin = new QLineEdit(centralWidget);
        LE_spin->setObjectName(QString::fromUtf8("LE_spin"));
        LE_spin->setGeometry(QRect(860, 560, 81, 31));
        LE_spin->setFont(font1);
        PB_spin = new QPushButton(centralWidget);
        PB_spin->setObjectName(QString::fromUtf8("PB_spin"));
        PB_spin->setGeometry(QRect(950, 560, 111, 71));
        PB_spin->setFont(font);
        PB_fix = new QPushButton(centralWidget);
        PB_fix->setObjectName(QString::fromUtf8("PB_fix"));
        PB_fix->setGeometry(QRect(1080, 560, 111, 71));
        PB_fix->setFont(font);
        opencv_exp_2Class->setCentralWidget(centralWidget);

        retranslateUi(opencv_exp_2Class);

        QMetaObject::connectSlotsByName(opencv_exp_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *opencv_exp_2Class)
    {
        opencv_exp_2Class->setWindowTitle(QCoreApplication::translate("opencv_exp_2Class", "\345\256\236\351\252\2142", nullptr));
        LB_ori->setText(QString());
        LB_aft->setText(QString());
        label->setText(QCoreApplication::translate("opencv_exp_2Class", "\345\216\237\345\247\213\345\233\276\345\203\217", nullptr));
        label_2->setText(QCoreApplication::translate("opencv_exp_2Class", "\345\244\204\347\220\206\345\220\216\345\233\276\345\203\217", nullptr));
        PB_read->setText(QCoreApplication::translate("opencv_exp_2Class", "\350\257\273\345\217\226\345\233\276\347\211\207", nullptr));
        LB_pix_ori->setText(QString());
        LB_pix_aft->setText(QString());
        LE_dx->setText(QCoreApplication::translate("opencv_exp_2Class", "0", nullptr));
        LE_dy->setText(QCoreApplication::translate("opencv_exp_2Class", "0", nullptr));
        label_3->setText(QCoreApplication::translate("opencv_exp_2Class", "X\345\201\217\347\247\273\351\207\217:", nullptr));
        label_4->setText(QCoreApplication::translate("opencv_exp_2Class", "Y\345\201\217\347\247\273\351\207\217:", nullptr));
        PB_trans->setText(QCoreApplication::translate("opencv_exp_2Class", "\345\271\263\347\247\273\345\233\276\347\211\207", nullptr));
        label_5->setText(QCoreApplication::translate("opencv_exp_2Class", "\347\274\251\346\224\276\345\233\240\345\255\220\357\274\232", nullptr));
        LE_scale_factor->setText(QCoreApplication::translate("opencv_exp_2Class", "1.0", nullptr));
        PB_scale->setText(QCoreApplication::translate("opencv_exp_2Class", "\347\274\251\346\224\276\345\233\276\347\211\207", nullptr));
        label_6->setText(QCoreApplication::translate("opencv_exp_2Class", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
        LE_spin->setText(QCoreApplication::translate("opencv_exp_2Class", "0.0", nullptr));
        PB_spin->setText(QCoreApplication::translate("opencv_exp_2Class", "\346\227\213\350\275\254\345\233\276\347\211\207", nullptr));
        PB_fix->setText(QCoreApplication::translate("opencv_exp_2Class", "\346\240\241\346\255\243\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class opencv_exp_2Class: public Ui_opencv_exp_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCV_EXP_2_H

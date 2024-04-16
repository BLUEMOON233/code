/********************************************************************************
** Form generated from reading UI file 'exp_2_Client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXP_2_CLIENT_H
#define UI_EXP_2_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_exp_2_ClientClass
{
public:
    QWidget *centralWidget;
    QLineEdit *LE_adderss;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *LE_localPort;
    QTextBrowser *TB_message;
    QLineEdit *LE_message;
    QPushButton *PB_send;
    QPushButton *PB_connect;
    QLineEdit *LE_targetPort;
    QLabel *label_3;

    void setupUi(QMainWindow *exp_2_ClientClass)
    {
        if (exp_2_ClientClass->objectName().isEmpty())
            exp_2_ClientClass->setObjectName(QString::fromUtf8("exp_2_ClientClass"));
        exp_2_ClientClass->resize(600, 400);
        centralWidget = new QWidget(exp_2_ClientClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LE_adderss = new QLineEdit(centralWidget);
        LE_adderss->setObjectName(QString::fromUtf8("LE_adderss"));
        LE_adderss->setGeometry(QRect(120, 10, 241, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        LE_adderss->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 71, 31));
        label->setFont(font);
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 50, 81, 31));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Sunken);
        LE_localPort = new QLineEdit(centralWidget);
        LE_localPort->setObjectName(QString::fromUtf8("LE_localPort"));
        LE_localPort->setGeometry(QRect(120, 50, 91, 31));
        LE_localPort->setFont(font);
        TB_message = new QTextBrowser(centralWidget);
        TB_message->setObjectName(QString::fromUtf8("TB_message"));
        TB_message->setGeometry(QRect(30, 90, 541, 251));
        TB_message->setFont(font);
        LE_message = new QLineEdit(centralWidget);
        LE_message->setObjectName(QString::fromUtf8("LE_message"));
        LE_message->setGeometry(QRect(30, 350, 431, 31));
        LE_message->setFont(font);
        PB_send = new QPushButton(centralWidget);
        PB_send->setObjectName(QString::fromUtf8("PB_send"));
        PB_send->setGeometry(QRect(470, 350, 101, 31));
        QFont font1;
        font1.setPointSize(12);
        PB_send->setFont(font1);
        PB_connect = new QPushButton(centralWidget);
        PB_connect->setObjectName(QString::fromUtf8("PB_connect"));
        PB_connect->setGeometry(QRect(220, 50, 101, 31));
        PB_connect->setFont(font1);
        LE_targetPort = new QLineEdit(centralWidget);
        LE_targetPort->setObjectName(QString::fromUtf8("LE_targetPort"));
        LE_targetPort->setGeometry(QRect(470, 10, 91, 31));
        LE_targetPort->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(370, 10, 81, 31));
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Sunken);
        exp_2_ClientClass->setCentralWidget(centralWidget);

        retranslateUi(exp_2_ClientClass);

        QMetaObject::connectSlotsByName(exp_2_ClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *exp_2_ClientClass)
    {
        exp_2_ClientClass->setWindowTitle(QCoreApplication::translate("exp_2_ClientClass", "exp_2_Client", nullptr));
        LE_adderss->setText(QCoreApplication::translate("exp_2_ClientClass", "127.0.0.1", nullptr));
        label->setText(QCoreApplication::translate("exp_2_ClientClass", "IP\345\234\260\345\235\200", nullptr));
        label_2->setText(QCoreApplication::translate("exp_2_ClientClass", "\346\234\254\345\234\260\347\253\257\345\217\243", nullptr));
        LE_localPort->setText(QString());
        LE_message->setText(QString());
        PB_send->setText(QCoreApplication::translate("exp_2_ClientClass", "\345\217\221\351\200\201", nullptr));
        PB_connect->setText(QCoreApplication::translate("exp_2_ClientClass", "\350\277\236\346\216\245", nullptr));
        LE_targetPort->setText(QString());
        label_3->setText(QCoreApplication::translate("exp_2_ClientClass", "\347\233\256\346\240\207\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exp_2_ClientClass: public Ui_exp_2_ClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXP_2_CLIENT_H

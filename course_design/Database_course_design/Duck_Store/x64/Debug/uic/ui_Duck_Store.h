/********************************************************************************
** Form generated from reading UI file 'Duck_Store.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUCK_STORE_H
#define UI_DUCK_STORE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Duck_StoreClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *LE_pwd;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *LE_Name;
    QSpacerItem *verticalSpacer_3;
    QLabel *Login_pwd;
    QLabel *Login_Name;
    QSpacerItem *verticalSpacer;
    QPushButton *PB_Login;

    void setupUi(QMainWindow *Duck_StoreClass)
    {
        if (Duck_StoreClass->objectName().isEmpty())
            Duck_StoreClass->setObjectName(QString::fromUtf8("Duck_StoreClass"));
        Duck_StoreClass->resize(600, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Duck_Store/image/duck.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Duck_StoreClass->setWindowIcon(icon);
        centralWidget = new QWidget(Duck_StoreClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 70, 421, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        LE_pwd = new QLineEdit(gridLayoutWidget);
        LE_pwd->setObjectName(QString::fromUtf8("LE_pwd"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LE_pwd->sizePolicy().hasHeightForWidth());
        LE_pwd->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(18);
        LE_pwd->setFont(font);
        LE_pwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(LE_pwd, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        LE_Name = new QLineEdit(gridLayoutWidget);
        LE_Name->setObjectName(QString::fromUtf8("LE_Name"));
        sizePolicy.setHeightForWidth(LE_Name->sizePolicy().hasHeightForWidth());
        LE_Name->setSizePolicy(sizePolicy);
        LE_Name->setFont(font);

        gridLayout->addWidget(LE_Name, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);

        Login_pwd = new QLabel(gridLayoutWidget);
        Login_pwd->setObjectName(QString::fromUtf8("Login_pwd"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        Login_pwd->setFont(font1);

        gridLayout->addWidget(Login_pwd, 3, 0, 1, 1);

        Login_Name = new QLabel(gridLayoutWidget);
        Login_Name->setObjectName(QString::fromUtf8("Login_Name"));
        Login_Name->setFont(font1);
        Login_Name->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(Login_Name, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        PB_Login = new QPushButton(centralWidget);
        PB_Login->setObjectName(QString::fromUtf8("PB_Login"));
        PB_Login->setGeometry(QRect(230, 270, 121, 61));
        PB_Login->setFont(font1);
        PB_Login->setAutoDefault(false);
        PB_Login->setFlat(false);
        Duck_StoreClass->setCentralWidget(centralWidget);

        retranslateUi(Duck_StoreClass);

        PB_Login->setDefault(false);


        QMetaObject::connectSlotsByName(Duck_StoreClass);
    } // setupUi

    void retranslateUi(QMainWindow *Duck_StoreClass)
    {
        Duck_StoreClass->setWindowTitle(QCoreApplication::translate("Duck_StoreClass", "Duck_Store", nullptr));
        LE_pwd->setText(QString());
        LE_Name->setText(QString());
        Login_pwd->setText(QCoreApplication::translate("Duck_StoreClass", "\345\257\206\347\240\201\357\274\232", nullptr));
        Login_Name->setText(QCoreApplication::translate("Duck_StoreClass", "\350\264\246\345\217\267\357\274\232", nullptr));
        PB_Login->setText(QCoreApplication::translate("Duck_StoreClass", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Duck_StoreClass: public Ui_Duck_StoreClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUCK_STORE_H

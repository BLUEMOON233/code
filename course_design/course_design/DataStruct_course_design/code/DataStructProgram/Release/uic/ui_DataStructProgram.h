/********************************************************************************
** Form generated from reading UI file 'DataStructProgram.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASTRUCTPROGRAM_H
#define UI_DATASTRUCTPROGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataStructProgramClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *mainPB1;
    QPushButton *mainPB2;
    QPushButton *mainPB3;
    QPushButton *mainPB4;
    QPushButton *mainPB5;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QTextEdit *textEdit;
    QWidget *page2;
    QPushButton *P2_PBstartDiver;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *P2_LEname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *P2_LEclassNum;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *P2_LEstuNum;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *P2_PBopenFile;
    QTableWidget *tableWidget;
    QWidget *page3;
    QWidget *page4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataStructProgramClass)
    {
        if (DataStructProgramClass->objectName().isEmpty())
            DataStructProgramClass->setObjectName(QString::fromUtf8("DataStructProgramClass"));
        DataStructProgramClass->resize(1080, 720);
        DataStructProgramClass->setMinimumSize(QSize(1080, 720));
        DataStructProgramClass->setMaximumSize(QSize(1080, 720));
        centralWidget = new QWidget(DataStructProgramClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 761, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mainPB1 = new QPushButton(horizontalLayoutWidget);
        mainPB1->setObjectName(QString::fromUtf8("mainPB1"));

        horizontalLayout->addWidget(mainPB1);

        mainPB2 = new QPushButton(horizontalLayoutWidget);
        mainPB2->setObjectName(QString::fromUtf8("mainPB2"));

        horizontalLayout->addWidget(mainPB2);

        mainPB3 = new QPushButton(horizontalLayoutWidget);
        mainPB3->setObjectName(QString::fromUtf8("mainPB3"));

        horizontalLayout->addWidget(mainPB3);

        mainPB4 = new QPushButton(horizontalLayoutWidget);
        mainPB4->setObjectName(QString::fromUtf8("mainPB4"));

        horizontalLayout->addWidget(mainPB4);

        mainPB5 = new QPushButton(horizontalLayoutWidget);
        mainPB5->setObjectName(QString::fromUtf8("mainPB5"));

        horizontalLayout->addWidget(mainPB5);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 80, 1041, 671));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        textEdit = new QTextEdit(page1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(120, 110, 731, 211));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        P2_PBstartDiver = new QPushButton(page2);
        P2_PBstartDiver->setObjectName(QString::fromUtf8("P2_PBstartDiver"));
        P2_PBstartDiver->setGeometry(QRect(550, 40, 151, 71));
        verticalLayoutWidget = new QWidget(page2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 20, 461, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        P2_LEname = new QLineEdit(verticalLayoutWidget);
        P2_LEname->setObjectName(QString::fromUtf8("P2_LEname"));

        horizontalLayout_3->addWidget(P2_LEname);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        P2_LEclassNum = new QLineEdit(verticalLayoutWidget);
        P2_LEclassNum->setObjectName(QString::fromUtf8("P2_LEclassNum"));

        horizontalLayout_2->addWidget(P2_LEclassNum);

        horizontalSpacer_2 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        P2_LEstuNum = new QLineEdit(verticalLayoutWidget);
        P2_LEstuNum->setObjectName(QString::fromUtf8("P2_LEstuNum"));

        horizontalLayout_2->addWidget(P2_LEstuNum);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        P2_PBopenFile = new QPushButton(verticalLayoutWidget);
        P2_PBopenFile->setObjectName(QString::fromUtf8("P2_PBopenFile"));

        horizontalLayout_4->addWidget(P2_PBopenFile);


        horizontalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(page2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 150, 681, 441));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        stackedWidget->addWidget(page4);
        DataStructProgramClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(DataStructProgramClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DataStructProgramClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DataStructProgramClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DataStructProgramClass->setStatusBar(statusBar);

        retranslateUi(DataStructProgramClass);

        QMetaObject::connectSlotsByName(DataStructProgramClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataStructProgramClass)
    {
        DataStructProgramClass->setWindowTitle(QCoreApplication::translate("DataStructProgramClass", "DataStructProgram", nullptr));
        mainPB1->setText(QCoreApplication::translate("DataStructProgramClass", "\344\270\273\347\225\214\351\235\242", nullptr));
        mainPB2->setText(QCoreApplication::translate("DataStructProgramClass", "\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        mainPB3->setText(QCoreApplication::translate("DataStructProgramClass", "\346\225\260\346\215\256\346\237\245\347\234\213", nullptr));
        mainPB4->setText(QCoreApplication::translate("DataStructProgramClass", "\346\225\260\346\215\256\345\210\206\346\236\220", nullptr));
        mainPB5->setText(QCoreApplication::translate("DataStructProgramClass", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        textEdit->setHtml(QCoreApplication::translate("DataStructProgramClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:28pt;\">\345\244\247\347\261\273\345\210\206\346\265\201\347\263\273\347\273\237</span></p></body></html>", nullptr));
        P2_PBstartDiver->setText(QCoreApplication::translate("DataStructProgramClass", "\345\274\200\345\247\213\345\210\206\346\265\201", nullptr));
        label->setText(QCoreApplication::translate("DataStructProgramClass", "\344\270\223\344\270\232\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("DataStructProgramClass", "\347\217\255\347\272\247\346\225\260\351\207\217\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("DataStructProgramClass", "\347\217\255\347\272\247\344\272\272\346\225\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("DataStructProgramClass", "\344\270\223\344\270\232\346\212\245\345\220\215\346\225\260\346\215\256\357\274\232", nullptr));
        P2_PBopenFile->setText(QCoreApplication::translate("DataStructProgramClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataStructProgramClass: public Ui_DataStructProgramClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASTRUCTPROGRAM_H

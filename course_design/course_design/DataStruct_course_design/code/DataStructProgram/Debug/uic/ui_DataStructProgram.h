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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
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
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QPushButton *P2_PBopenFile;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *P2_LEclassNum;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *P2_LEstuNum;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QPushButton *P2_PBclearDiver;
    QFrame *line;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *P2_LE_IDQuery;
    QPushButton *P2_PBQuery;
    QGroupBox *groupBox_2;
    QPushButton *P2_PBModify;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QLineEdit *P2_LEclassModify;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QLineEdit *P2_LEmajorModify;
    QWidget *page3;
    QTableWidget *P3_tableWidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *P3_LElimitedMajor;
    QLabel *label_6;
    QLineEdit *P3_LElimitedClass;
    QLabel *label_10;
    QLineEdit *P3_LElimitedRank;
    QLabel *label_9;
    QLineEdit *P3_LElimitedID;
    QLabel *label_7;
    QPushButton *P3_PBstartFilt;
    QWidget *page4;
    QTableWidget *P4_tableWidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLineEdit *P4_LEclass;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLineEdit *P4_LEmajor;
    QPushButton *P4_PBanalyse;
    QTextEdit *textEdit_2;
    QPushButton *systemOpenFile;
    QPushButton *systemSaveFile;
    QStackedWidget *systemState;
    QWidget *page;
    QLabel *systemIsTrue;
    QWidget *page_2;
    QLabel *systemIsFalse;
    QLabel *label_5;
    QFrame *line_2;
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
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 731, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mainPB1 = new QPushButton(horizontalLayoutWidget);
        mainPB1->setObjectName(QString::fromUtf8("mainPB1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainPB1->sizePolicy().hasHeightForWidth());
        mainPB1->setSizePolicy(sizePolicy);
        mainPB1->setMinimumSize(QSize(131, 50));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        mainPB1->setFont(font);

        horizontalLayout->addWidget(mainPB1);

        mainPB2 = new QPushButton(horizontalLayoutWidget);
        mainPB2->setObjectName(QString::fromUtf8("mainPB2"));
        sizePolicy.setHeightForWidth(mainPB2->sizePolicy().hasHeightForWidth());
        mainPB2->setSizePolicy(sizePolicy);
        mainPB2->setMinimumSize(QSize(131, 50));
        mainPB2->setFont(font);

        horizontalLayout->addWidget(mainPB2);

        mainPB3 = new QPushButton(horizontalLayoutWidget);
        mainPB3->setObjectName(QString::fromUtf8("mainPB3"));
        sizePolicy.setHeightForWidth(mainPB3->sizePolicy().hasHeightForWidth());
        mainPB3->setSizePolicy(sizePolicy);
        mainPB3->setMinimumSize(QSize(131, 50));
        mainPB3->setFont(font);

        horizontalLayout->addWidget(mainPB3);

        mainPB4 = new QPushButton(horizontalLayoutWidget);
        mainPB4->setObjectName(QString::fromUtf8("mainPB4"));
        sizePolicy.setHeightForWidth(mainPB4->sizePolicy().hasHeightForWidth());
        mainPB4->setSizePolicy(sizePolicy);
        mainPB4->setMinimumSize(QSize(131, 50));
        mainPB4->setFont(font);

        horizontalLayout->addWidget(mainPB4);

        mainPB5 = new QPushButton(horizontalLayoutWidget);
        mainPB5->setObjectName(QString::fromUtf8("mainPB5"));
        sizePolicy.setHeightForWidth(mainPB5->sizePolicy().hasHeightForWidth());
        mainPB5->setSizePolicy(sizePolicy);
        mainPB5->setMinimumSize(QSize(131, 50));
        mainPB5->setFont(font);

        horizontalLayout->addWidget(mainPB5);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 80, 1041, 671));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        stackedWidget->setFont(font1);
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        textEdit = new QTextEdit(page1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 40, 941, 531));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        P2_PBstartDiver = new QPushButton(page2);
        P2_PBstartDiver->setObjectName(QString::fromUtf8("P2_PBstartDiver"));
        P2_PBstartDiver->setGeometry(QRect(580, 20, 141, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        P2_PBstartDiver->setFont(font2);
        verticalLayoutWidget = new QWidget(page2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 0, 531, 131));
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(P2_LEname->sizePolicy().hasHeightForWidth());
        P2_LEname->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(P2_LEname);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        P2_PBopenFile = new QPushButton(verticalLayoutWidget);
        P2_PBopenFile->setObjectName(QString::fromUtf8("P2_PBopenFile"));
        P2_PBopenFile->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(P2_PBopenFile);

        horizontalSpacer_4 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        horizontalLayout_3->addLayout(horizontalLayout_4);


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

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(page2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 150, 711, 441));
        P2_PBclearDiver = new QPushButton(page2);
        P2_PBclearDiver->setObjectName(QString::fromUtf8("P2_PBclearDiver"));
        P2_PBclearDiver->setGeometry(QRect(580, 80, 141, 51));
        P2_PBclearDiver->setFont(font2);
        line = new QFrame(page2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(770, 0, 20, 601));
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(3);
        line->setFrameShape(QFrame::VLine);
        groupBox = new QGroupBox(page2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(800, 20, 231, 161));
        horizontalLayoutWidget_5 = new QWidget(groupBox);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(20, 20, 181, 61));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(horizontalLayoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_8->addWidget(label_13);

        P2_LE_IDQuery = new QLineEdit(horizontalLayoutWidget_5);
        P2_LE_IDQuery->setObjectName(QString::fromUtf8("P2_LE_IDQuery"));

        horizontalLayout_8->addWidget(P2_LE_IDQuery);

        P2_PBQuery = new QPushButton(groupBox);
        P2_PBQuery->setObjectName(QString::fromUtf8("P2_PBQuery"));
        P2_PBQuery->setGeometry(QRect(20, 100, 181, 41));
        P2_PBQuery->setFont(font2);
        groupBox_2 = new QGroupBox(page2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(800, 190, 231, 291));
        P2_PBModify = new QPushButton(groupBox_2);
        P2_PBModify->setObjectName(QString::fromUtf8("P2_PBModify"));
        P2_PBModify->setGeometry(QRect(20, 230, 181, 41));
        P2_PBModify->setFont(font2);
        horizontalLayoutWidget_7 = new QWidget(groupBox_2);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(20, 130, 201, 80));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(horizontalLayoutWidget_7);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_10->addWidget(label_15);

        P2_LEclassModify = new QLineEdit(horizontalLayoutWidget_7);
        P2_LEclassModify->setObjectName(QString::fromUtf8("P2_LEclassModify"));

        horizontalLayout_10->addWidget(P2_LEclassModify);

        horizontalLayoutWidget_6 = new QWidget(groupBox_2);
        horizontalLayoutWidget_6->setObjectName(QString::fromUtf8("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(20, 30, 201, 80));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);

        P2_LEmajorModify = new QLineEdit(horizontalLayoutWidget_6);
        P2_LEmajorModify->setObjectName(QString::fromUtf8("P2_LEmajorModify"));

        horizontalLayout_9->addWidget(P2_LEmajorModify);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        P3_tableWidget = new QTableWidget(page3);
        P3_tableWidget->setObjectName(QString::fromUtf8("P3_tableWidget"));
        P3_tableWidget->setGeometry(QRect(20, 70, 981, 521));
        horizontalLayoutWidget_2 = new QWidget(page3);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 10, 631, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(horizontalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        P3_LElimitedMajor = new QLineEdit(horizontalLayoutWidget_2);
        P3_LElimitedMajor->setObjectName(QString::fromUtf8("P3_LElimitedMajor"));

        horizontalLayout_5->addWidget(P3_LElimitedMajor);

        label_6 = new QLabel(horizontalLayoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        P3_LElimitedClass = new QLineEdit(horizontalLayoutWidget_2);
        P3_LElimitedClass->setObjectName(QString::fromUtf8("P3_LElimitedClass"));

        horizontalLayout_5->addWidget(P3_LElimitedClass);

        label_10 = new QLabel(horizontalLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        P3_LElimitedRank = new QLineEdit(horizontalLayoutWidget_2);
        P3_LElimitedRank->setObjectName(QString::fromUtf8("P3_LElimitedRank"));

        horizontalLayout_5->addWidget(P3_LElimitedRank);

        label_9 = new QLabel(horizontalLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        P3_LElimitedID = new QLineEdit(horizontalLayoutWidget_2);
        P3_LElimitedID->setObjectName(QString::fromUtf8("P3_LElimitedID"));

        horizontalLayout_5->addWidget(P3_LElimitedID);

        label_7 = new QLabel(horizontalLayoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        P3_PBstartFilt = new QPushButton(page3);
        P3_PBstartFilt->setObjectName(QString::fromUtf8("P3_PBstartFilt"));
        P3_PBstartFilt->setGeometry(QRect(830, 10, 141, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        P3_PBstartFilt->setFont(font3);
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        P4_tableWidget = new QTableWidget(page4);
        P4_tableWidget->setObjectName(QString::fromUtf8("P4_tableWidget"));
        P4_tableWidget->setGeometry(QRect(70, 110, 881, 461));
        horizontalLayoutWidget_3 = new QWidget(page4);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(70, 20, 431, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(horizontalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_6->addWidget(label_11);

        P4_LEclass = new QLineEdit(horizontalLayoutWidget_3);
        P4_LEclass->setObjectName(QString::fromUtf8("P4_LEclass"));

        horizontalLayout_6->addWidget(P4_LEclass);

        horizontalLayoutWidget_4 = new QWidget(page4);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(70, 50, 431, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(horizontalLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        P4_LEmajor = new QLineEdit(horizontalLayoutWidget_4);
        P4_LEmajor->setObjectName(QString::fromUtf8("P4_LEmajor"));

        horizontalLayout_7->addWidget(P4_LEmajor);

        P4_PBanalyse = new QPushButton(page4);
        P4_PBanalyse->setObjectName(QString::fromUtf8("P4_PBanalyse"));
        P4_PBanalyse->setGeometry(QRect(560, 20, 161, 61));
        P4_PBanalyse->setFont(font3);
        textEdit_2 = new QTextEdit(page4);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(760, 20, 191, 61));
        stackedWidget->addWidget(page4);
        systemOpenFile = new QPushButton(centralWidget);
        systemOpenFile->setObjectName(QString::fromUtf8("systemOpenFile"));
        systemOpenFile->setGeometry(QRect(780, 20, 111, 23));
        systemSaveFile = new QPushButton(centralWidget);
        systemSaveFile->setObjectName(QString::fromUtf8("systemSaveFile"));
        systemSaveFile->setGeometry(QRect(780, 50, 111, 23));
        systemState = new QStackedWidget(centralWidget);
        systemState->setObjectName(QString::fromUtf8("systemState"));
        systemState->setGeometry(QRect(1000, 10, 61, 61));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        systemIsTrue = new QLabel(page);
        systemIsTrue->setObjectName(QString::fromUtf8("systemIsTrue"));
        systemIsTrue->setGeometry(QRect(20, 20, 31, 31));
        systemIsTrue->setPixmap(QPixmap(QString::fromUtf8(":/DataStructProgram/false.png")));
        systemIsTrue->setScaledContents(true);
        systemState->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        systemIsFalse = new QLabel(page_2);
        systemIsFalse->setObjectName(QString::fromUtf8("systemIsFalse"));
        systemIsFalse->setGeometry(QRect(20, 20, 31, 31));
        systemIsFalse->setPixmap(QPixmap(QString::fromUtf8(":/DataStructProgram/true.png")));
        systemIsFalse->setScaledContents(true);
        systemState->addWidget(page_2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(920, 30, 101, 41));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 70, 1081, 16));
        line_2->setFrameShadow(QFrame::Raised);
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        DataStructProgramClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DataStructProgramClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DataStructProgramClass->setStatusBar(statusBar);

        retranslateUi(DataStructProgramClass);

        stackedWidget->setCurrentIndex(1);
        systemState->setCurrentIndex(0);


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
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:36pt; font-weight:600;\">\350\256\241\347\256\227\346\234\272\344\270\223\344\270\232\345\244\247\347\261\273\345\210\206\346\265\201\350\275\257\344\273\266\350\256\276\350\256\241</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\347\273\204\351\225\277\357\274\232\345\210\230\346\226\207\350\266\212</span></"
                        "p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\347\273\204\345\221\230\357\274\232\347\216\213\345\255\220\345\215\223\357\274\214\350\202\226\350\212\267\351\246\250\357\274\214\345\255\231\347\277\224\357\274\214\345\272\267\346\227\255</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\256\213\344\275\223'; font-size:18pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt; font-weight:600;\">\347\225\214\351\235\242\344\273\213\347\273\215\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0"
                        "px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\344\270\273\347\225\214\351\235\242\357\274\232\344\273\213\347\273\215\350\275\257\344\273\266\345\212\237\350\203\275</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\346\225\260\346\215\256\345\244\204\347\220\206\357\274\232\345\257\274\345\205\245\345\216\237\345\247\213\346\225\260\346\215\256\343\200\201\344\277\256\346\224\271\345\210\206\346\265\201\345\220\216\346\225\260\346\215\256</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\346\225\260\346\215\256\346\237\245\347\234\213\357\274\232\345\210\206\346\265\201\345\220\216\346\225\260\346\215\256\346\246\202\350\247\210"
                        "</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\351\200\200\345\207\272\347\263\273\347\273\237\357\274\232\351\200\200\345\207\272\347\263\273\347\273\237</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\345\210\206\346\265\201\347\212\266\346\200\201\357\274\232\346\230\276\347\244\272\345\275\223\345\211\215\350\275\257\344\273\266\346\230\257\345\220\246\345\255\230\345\234\250\345\210\206\346\265\201\345\220\216\346\225\260\346\215\256</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\346\211\223\345\274\200\346\226\207\344\273\266"
                        "\357\274\232\345\257\274\345\205\245\345\210\206\346\265\201\345\220\216\347\232\204\346\225\260\346\215\256\346\226\207\344\273\266</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\344\277\235\345\255\230\346\226\207\344\273\266\357\274\232\345\275\223\350\275\257\344\273\266\344\270\255\345\255\230\345\234\250\345\210\206\346\265\201\345\220\216\346\225\260\346\215\256\346\227\266\344\277\235\345\255\230\344\270\272\346\225\260\346\215\256\346\226\207\344\273\266</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\256\213\344\275\223'; font-size:18pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344"
                        "\275\223'; font-size:18pt; font-weight:600;\">\347\211\271\345\210\253\351\270\243\350\260\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\346\205\225\346\231\250\350\200\201\345\270\210\345\257\271\344\272\216\346\234\254\350\257\276\347\250\213\350\256\276\350\256\241\347\232\204\346\224\257\346\214\201\344\270\216\347\255\224\347\226\221\350\247\243\346\203\221</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\256\213\344\275\223'; font-size:18pt;\"><br /></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">\347\274\226\345\206\231\346\227\266\351\227\264\357"
                        "\274\232</span></p>\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:18pt;\">2022/12/18</span></p></body></html>", nullptr));
        P2_PBstartDiver->setText(QCoreApplication::translate("DataStructProgramClass", "\345\274\200\345\247\213\345\255\246\347\224\237\345\210\206\346\265\201", nullptr));
        label->setText(QCoreApplication::translate("DataStructProgramClass", "\344\270\223\344\270\232\345\220\215\347\247\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("DataStructProgramClass", "\344\270\223\344\270\232\346\212\245\345\220\215\346\225\260\346\215\256\357\274\232", nullptr));
        P2_PBopenFile->setText(QCoreApplication::translate("DataStructProgramClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("DataStructProgramClass", "\347\217\255\347\272\247\346\225\260\351\207\217\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("DataStructProgramClass", "\347\217\255\347\272\247\344\272\272\346\225\260\357\274\232", nullptr));
        P2_PBclearDiver->setText(QCoreApplication::translate("DataStructProgramClass", "\346\270\205\347\251\272\345\275\223\345\211\215\345\210\206\346\265\201", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DataStructProgramClass", "\346\237\245\350\257\242", nullptr));
        label_13->setText(QCoreApplication::translate("DataStructProgramClass", "\345\255\246\345\217\267\357\274\232", nullptr));
        P2_PBQuery->setText(QCoreApplication::translate("DataStructProgramClass", "\346\237\245\350\257\242", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DataStructProgramClass", "\344\277\256\346\224\271", nullptr));
        P2_PBModify->setText(QCoreApplication::translate("DataStructProgramClass", "\344\277\256\346\224\271", nullptr));
        label_15->setText(QCoreApplication::translate("DataStructProgramClass", "\347\217\255\347\272\247\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("DataStructProgramClass", "\344\270\223\344\270\232\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("DataStructProgramClass", "\344\270\223\344\270\232\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("DataStructProgramClass", "\347\217\255\347\272\247\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("DataStructProgramClass", "\346\216\222\345\220\215\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("DataStructProgramClass", "\345\255\246\345\217\267\357\274\232", nullptr));
        label_7->setText(QString());
        P3_PBstartFilt->setText(QCoreApplication::translate("DataStructProgramClass", "\347\255\233\351\200\211", nullptr));
        label_11->setText(QCoreApplication::translate("DataStructProgramClass", "\350\276\223\345\205\245\347\217\255\347\272\247\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("DataStructProgramClass", "\350\276\223\345\205\245\344\270\223\344\270\232\357\274\232", nullptr));
        P4_PBanalyse->setText(QCoreApplication::translate("DataStructProgramClass", "\345\210\206\346\236\220", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("DataStructProgramClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\237\245\350\257\242\346\240\274\345\274\217\351\234\200\345\260\206\347\217\255\347\272\247\346\210\226\344\270\223\344\270\232\345\220\215\347\247\260\346\214\211\347\205\247\342\200\230;\342\200\231\345\210\206\351\232\224\345\274\200</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\276\213\357\274\232\344\270\223\344\270\2321;\344\270\223\344\270\2322;\344\270\223\344\270\2323;\344\270\223\344\270\2324</p></body></html>", nullptr));
        systemOpenFile->setText(QCoreApplication::translate("DataStructProgramClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        systemSaveFile->setText(QCoreApplication::translate("DataStructProgramClass", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        systemIsTrue->setText(QString());
        systemIsFalse->setText(QString());
        label_5->setText(QCoreApplication::translate("DataStructProgramClass", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\345\210\206\346\265\201\347\212\266\346\200\201</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataStructProgramClass: public Ui_DataStructProgramClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASTRUCTPROGRAM_H

/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *Menu;
    QSpacerItem *verticalSpacer;
    QPushButton *PB_MainPage;
    QSpacerItem *verticalSpacer_2;
    QPushButton *PB_Merchandise;
    QSpacerItem *verticalSpacer_3;
    QPushButton *PB_Inventory;
    QSpacerItem *verticalSpacer_4;
    QPushButton *PB_Purchase;
    QSpacerItem *verticalSpacer_5;
    QPushButton *PB_Sell;
    QSpacerItem *verticalSpacer_6;
    QPushButton *PB_Supplier;
    QSpacerItem *verticalSpacer_8;
    QPushButton *PB_Staff;
    QSpacerItem *verticalSpacer_7;
    QPushButton *PB_Income;
    QSpacerItem *verticalSpacer_9;
    QStackedWidget *stackedWidget;
    QWidget *Page_Main;
    QLabel *label_5;
    QLabel *label;
    QWidget *Page_Merchandise;
    QTableWidget *TB_Mer;
    QPushButton *PB_Add_Mer;
    QPushButton *PB_Mdf_Mer;
    QGroupBox *groupBox;
    QLineEdit *LE_Que_Mer;
    QPushButton *PB_Que_Mer;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QPushButton *PB_Sel_Mer;
    QLabel *label_8;
    QComboBox *CB_merchandise;
    QWidget *Page_Inventory;
    QTableWidget *TB_Inventory;
    QLabel *label_3;
    QPushButton *PB_Inv_ID;
    QPushButton *PB_Inv_Type;
    QPushButton *PB_Inv_Name;
    QPushButton *PB_Inv_Inv;
    QPushButton *PB_Inv_Output;
    QWidget *Page_Purchase;
    QTableWidget *TB_Purchase;
    QPushButton *PB_Add_Purchase;
    QPushButton *PB_Del_Purchase;
    QPushButton *PB_Out_Purchase;
    QWidget *Page_Sell;
    QTableWidget *TB_Sell;
    QPushButton *PB_Add_Sell;
    QPushButton *PB_Del_Sell;
    QPushButton *PB_Out_Sell;
    QWidget *Page_Supplier;
    QTableWidget *TB_Supplier;
    QPushButton *PB_Add_Supplier;
    QPushButton *PB_Mdf_Supplier;
    QPushButton *PB_Del_Supplier;
    QPushButton *PB_Out_Supplier;
    QWidget *Page_Staff;
    QTableWidget *TB_Staff;
    QPushButton *PB_Add_Staff;
    QPushButton *PB_Del_Staff;
    QPushButton *PB_Mdf_Staff;
    QWidget *Page_NoPermission;
    QLabel *label_4;
    QLabel *label_6;
    QWidget *Page_Income;
    QTableWidget *TB_Income;
    QGroupBox *groupBox_2;
    QLineEdit *LE_Inc_Year;
    QLabel *label_7;
    QPushButton *PB_Que_Inc;
    QPushButton *PB_Out_Inc;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1500, 1000);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Duck_Store/image/duck.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 160, 981));
        Menu = new QVBoxLayout(verticalLayoutWidget);
        Menu->setSpacing(6);
        Menu->setContentsMargins(11, 11, 11, 11);
        Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer);

        PB_MainPage = new QPushButton(verticalLayoutWidget);
        PB_MainPage->setObjectName(QString::fromUtf8("PB_MainPage"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PB_MainPage->sizePolicy().hasHeightForWidth());
        PB_MainPage->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        PB_MainPage->setFont(font);

        Menu->addWidget(PB_MainPage);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_2);

        PB_Merchandise = new QPushButton(verticalLayoutWidget);
        PB_Merchandise->setObjectName(QString::fromUtf8("PB_Merchandise"));
        sizePolicy.setHeightForWidth(PB_Merchandise->sizePolicy().hasHeightForWidth());
        PB_Merchandise->setSizePolicy(sizePolicy);
        PB_Merchandise->setFont(font);

        Menu->addWidget(PB_Merchandise);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_3);

        PB_Inventory = new QPushButton(verticalLayoutWidget);
        PB_Inventory->setObjectName(QString::fromUtf8("PB_Inventory"));
        sizePolicy.setHeightForWidth(PB_Inventory->sizePolicy().hasHeightForWidth());
        PB_Inventory->setSizePolicy(sizePolicy);
        PB_Inventory->setFont(font);

        Menu->addWidget(PB_Inventory);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_4);

        PB_Purchase = new QPushButton(verticalLayoutWidget);
        PB_Purchase->setObjectName(QString::fromUtf8("PB_Purchase"));
        sizePolicy.setHeightForWidth(PB_Purchase->sizePolicy().hasHeightForWidth());
        PB_Purchase->setSizePolicy(sizePolicy);
        PB_Purchase->setFont(font);

        Menu->addWidget(PB_Purchase);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_5);

        PB_Sell = new QPushButton(verticalLayoutWidget);
        PB_Sell->setObjectName(QString::fromUtf8("PB_Sell"));
        sizePolicy.setHeightForWidth(PB_Sell->sizePolicy().hasHeightForWidth());
        PB_Sell->setSizePolicy(sizePolicy);
        PB_Sell->setFont(font);

        Menu->addWidget(PB_Sell);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_6);

        PB_Supplier = new QPushButton(verticalLayoutWidget);
        PB_Supplier->setObjectName(QString::fromUtf8("PB_Supplier"));
        sizePolicy.setHeightForWidth(PB_Supplier->sizePolicy().hasHeightForWidth());
        PB_Supplier->setSizePolicy(sizePolicy);
        PB_Supplier->setFont(font);

        Menu->addWidget(PB_Supplier);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_8);

        PB_Staff = new QPushButton(verticalLayoutWidget);
        PB_Staff->setObjectName(QString::fromUtf8("PB_Staff"));
        sizePolicy.setHeightForWidth(PB_Staff->sizePolicy().hasHeightForWidth());
        PB_Staff->setSizePolicy(sizePolicy);
        PB_Staff->setFont(font);

        Menu->addWidget(PB_Staff);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_7);

        PB_Income = new QPushButton(verticalLayoutWidget);
        PB_Income->setObjectName(QString::fromUtf8("PB_Income"));
        sizePolicy.setHeightForWidth(PB_Income->sizePolicy().hasHeightForWidth());
        PB_Income->setSizePolicy(sizePolicy);
        PB_Income->setFont(font);

        Menu->addWidget(PB_Income);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Menu->addItem(verticalSpacer_9);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(170, 10, 1321, 981));
        Page_Main = new QWidget();
        Page_Main->setObjectName(QString::fromUtf8("Page_Main"));
        label_5 = new QLabel(Page_Main);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, -50, 1291, 971));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/Duck_Store/image/MainPage.png")));
        label_5->setScaledContents(true);
        label = new QLabel(Page_Main);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 830, 661, 141));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(24);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        stackedWidget->addWidget(Page_Main);
        Page_Merchandise = new QWidget();
        Page_Merchandise->setObjectName(QString::fromUtf8("Page_Merchandise"));
        QFont font2;
        font2.setPointSize(18);
        Page_Merchandise->setFont(font2);
        TB_Mer = new QTableWidget(Page_Merchandise);
        TB_Mer->setObjectName(QString::fromUtf8("TB_Mer"));
        TB_Mer->setGeometry(QRect(10, 70, 1301, 901));
        TB_Mer->setFont(font2);
        PB_Add_Mer = new QPushButton(Page_Merchandise);
        PB_Add_Mer->setObjectName(QString::fromUtf8("PB_Add_Mer"));
        PB_Add_Mer->setGeometry(QRect(1000, 0, 131, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(18);
        PB_Add_Mer->setFont(font3);
        PB_Mdf_Mer = new QPushButton(Page_Merchandise);
        PB_Mdf_Mer->setObjectName(QString::fromUtf8("PB_Mdf_Mer"));
        PB_Mdf_Mer->setGeometry(QRect(1140, 0, 131, 61));
        PB_Mdf_Mer->setFont(font3);
        groupBox = new QGroupBox(Page_Merchandise);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 361, 61));
        LE_Que_Mer = new QLineEdit(groupBox);
        LE_Que_Mer->setObjectName(QString::fromUtf8("LE_Que_Mer"));
        LE_Que_Mer->setGeometry(QRect(100, 20, 113, 31));
        PB_Que_Mer = new QPushButton(groupBox);
        PB_Que_Mer->setObjectName(QString::fromUtf8("PB_Que_Mer"));
        PB_Que_Mer->setGeometry(QRect(220, 0, 131, 61));
        PB_Que_Mer->setFont(font3);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 91, 31));
        label_2->setFont(font3);
        groupBox_3 = new QGroupBox(Page_Merchandise);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(380, 0, 341, 61));
        PB_Sel_Mer = new QPushButton(groupBox_3);
        PB_Sel_Mer->setObjectName(QString::fromUtf8("PB_Sel_Mer"));
        PB_Sel_Mer->setGeometry(QRect(200, 0, 131, 61));
        PB_Sel_Mer->setFont(font3);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 91, 31));
        label_8->setFont(font3);
        CB_merchandise = new QComboBox(groupBox_3);
        CB_merchandise->addItem(QString());
        CB_merchandise->addItem(QString());
        CB_merchandise->addItem(QString());
        CB_merchandise->setObjectName(QString::fromUtf8("CB_merchandise"));
        CB_merchandise->setGeometry(QRect(80, 20, 101, 31));
        stackedWidget->addWidget(Page_Merchandise);
        Page_Inventory = new QWidget();
        Page_Inventory->setObjectName(QString::fromUtf8("Page_Inventory"));
        TB_Inventory = new QTableWidget(Page_Inventory);
        TB_Inventory->setObjectName(QString::fromUtf8("TB_Inventory"));
        TB_Inventory->setGeometry(QRect(10, 70, 1301, 901));
        TB_Inventory->setFont(font2);
        label_3 = new QLabel(Page_Inventory);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1000, 10, 301, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font4.setPointSize(30);
        font4.setBold(true);
        font4.setWeight(75);
        label_3->setFont(font4);
        PB_Inv_ID = new QPushButton(Page_Inventory);
        PB_Inv_ID->setObjectName(QString::fromUtf8("PB_Inv_ID"));
        PB_Inv_ID->setGeometry(QRect(10, 0, 131, 61));
        PB_Inv_ID->setFont(font3);
        PB_Inv_Type = new QPushButton(Page_Inventory);
        PB_Inv_Type->setObjectName(QString::fromUtf8("PB_Inv_Type"));
        PB_Inv_Type->setGeometry(QRect(150, 0, 131, 61));
        PB_Inv_Type->setFont(font3);
        PB_Inv_Name = new QPushButton(Page_Inventory);
        PB_Inv_Name->setObjectName(QString::fromUtf8("PB_Inv_Name"));
        PB_Inv_Name->setGeometry(QRect(290, 0, 131, 61));
        PB_Inv_Name->setFont(font3);
        PB_Inv_Inv = new QPushButton(Page_Inventory);
        PB_Inv_Inv->setObjectName(QString::fromUtf8("PB_Inv_Inv"));
        PB_Inv_Inv->setGeometry(QRect(430, 0, 131, 61));
        PB_Inv_Inv->setFont(font3);
        PB_Inv_Output = new QPushButton(Page_Inventory);
        PB_Inv_Output->setObjectName(QString::fromUtf8("PB_Inv_Output"));
        PB_Inv_Output->setGeometry(QRect(570, 0, 131, 61));
        PB_Inv_Output->setFont(font3);
        stackedWidget->addWidget(Page_Inventory);
        Page_Purchase = new QWidget();
        Page_Purchase->setObjectName(QString::fromUtf8("Page_Purchase"));
        TB_Purchase = new QTableWidget(Page_Purchase);
        TB_Purchase->setObjectName(QString::fromUtf8("TB_Purchase"));
        TB_Purchase->setGeometry(QRect(10, 70, 1301, 901));
        TB_Purchase->setFont(font2);
        PB_Add_Purchase = new QPushButton(Page_Purchase);
        PB_Add_Purchase->setObjectName(QString::fromUtf8("PB_Add_Purchase"));
        PB_Add_Purchase->setGeometry(QRect(10, 0, 171, 61));
        PB_Add_Purchase->setFont(font3);
        PB_Del_Purchase = new QPushButton(Page_Purchase);
        PB_Del_Purchase->setObjectName(QString::fromUtf8("PB_Del_Purchase"));
        PB_Del_Purchase->setGeometry(QRect(190, 0, 171, 61));
        PB_Del_Purchase->setFont(font3);
        PB_Out_Purchase = new QPushButton(Page_Purchase);
        PB_Out_Purchase->setObjectName(QString::fromUtf8("PB_Out_Purchase"));
        PB_Out_Purchase->setGeometry(QRect(370, 0, 171, 61));
        PB_Out_Purchase->setFont(font3);
        stackedWidget->addWidget(Page_Purchase);
        Page_Sell = new QWidget();
        Page_Sell->setObjectName(QString::fromUtf8("Page_Sell"));
        TB_Sell = new QTableWidget(Page_Sell);
        TB_Sell->setObjectName(QString::fromUtf8("TB_Sell"));
        TB_Sell->setGeometry(QRect(10, 70, 1301, 901));
        TB_Sell->setFont(font2);
        PB_Add_Sell = new QPushButton(Page_Sell);
        PB_Add_Sell->setObjectName(QString::fromUtf8("PB_Add_Sell"));
        PB_Add_Sell->setGeometry(QRect(10, 0, 171, 61));
        PB_Add_Sell->setFont(font3);
        PB_Del_Sell = new QPushButton(Page_Sell);
        PB_Del_Sell->setObjectName(QString::fromUtf8("PB_Del_Sell"));
        PB_Del_Sell->setGeometry(QRect(190, 0, 171, 61));
        PB_Del_Sell->setFont(font3);
        PB_Out_Sell = new QPushButton(Page_Sell);
        PB_Out_Sell->setObjectName(QString::fromUtf8("PB_Out_Sell"));
        PB_Out_Sell->setGeometry(QRect(370, 0, 171, 61));
        PB_Out_Sell->setFont(font3);
        stackedWidget->addWidget(Page_Sell);
        Page_Supplier = new QWidget();
        Page_Supplier->setObjectName(QString::fromUtf8("Page_Supplier"));
        TB_Supplier = new QTableWidget(Page_Supplier);
        TB_Supplier->setObjectName(QString::fromUtf8("TB_Supplier"));
        TB_Supplier->setGeometry(QRect(10, 70, 1301, 901));
        TB_Supplier->setFont(font2);
        PB_Add_Supplier = new QPushButton(Page_Supplier);
        PB_Add_Supplier->setObjectName(QString::fromUtf8("PB_Add_Supplier"));
        PB_Add_Supplier->setGeometry(QRect(10, 0, 171, 61));
        PB_Add_Supplier->setFont(font3);
        PB_Mdf_Supplier = new QPushButton(Page_Supplier);
        PB_Mdf_Supplier->setObjectName(QString::fromUtf8("PB_Mdf_Supplier"));
        PB_Mdf_Supplier->setGeometry(QRect(190, 0, 171, 61));
        PB_Mdf_Supplier->setFont(font3);
        PB_Del_Supplier = new QPushButton(Page_Supplier);
        PB_Del_Supplier->setObjectName(QString::fromUtf8("PB_Del_Supplier"));
        PB_Del_Supplier->setGeometry(QRect(370, 0, 171, 61));
        PB_Del_Supplier->setFont(font3);
        PB_Out_Supplier = new QPushButton(Page_Supplier);
        PB_Out_Supplier->setObjectName(QString::fromUtf8("PB_Out_Supplier"));
        PB_Out_Supplier->setGeometry(QRect(550, 0, 171, 61));
        PB_Out_Supplier->setFont(font3);
        stackedWidget->addWidget(Page_Supplier);
        Page_Staff = new QWidget();
        Page_Staff->setObjectName(QString::fromUtf8("Page_Staff"));
        TB_Staff = new QTableWidget(Page_Staff);
        TB_Staff->setObjectName(QString::fromUtf8("TB_Staff"));
        TB_Staff->setGeometry(QRect(10, 70, 1301, 901));
        TB_Staff->setFont(font2);
        PB_Add_Staff = new QPushButton(Page_Staff);
        PB_Add_Staff->setObjectName(QString::fromUtf8("PB_Add_Staff"));
        PB_Add_Staff->setGeometry(QRect(10, 0, 121, 61));
        PB_Add_Staff->setFont(font3);
        PB_Del_Staff = new QPushButton(Page_Staff);
        PB_Del_Staff->setObjectName(QString::fromUtf8("PB_Del_Staff"));
        PB_Del_Staff->setGeometry(QRect(270, 0, 121, 61));
        PB_Del_Staff->setFont(font3);
        PB_Mdf_Staff = new QPushButton(Page_Staff);
        PB_Mdf_Staff->setObjectName(QString::fromUtf8("PB_Mdf_Staff"));
        PB_Mdf_Staff->setGeometry(QRect(140, 0, 121, 61));
        PB_Mdf_Staff->setFont(font3);
        stackedWidget->addWidget(Page_Staff);
        Page_NoPermission = new QWidget();
        Page_NoPermission->setObjectName(QString::fromUtf8("Page_NoPermission"));
        label_4 = new QLabel(Page_NoPermission);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 540, 881, 171));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Consolas"));
        font5.setPointSize(72);
        font5.setBold(true);
        font5.setWeight(75);
        label_4->setFont(font5);
        label_6 = new QLabel(Page_NoPermission);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(410, 150, 431, 391));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/Duck_Store/image/NoPermission.png")));
        label_6->setScaledContents(true);
        stackedWidget->addWidget(Page_NoPermission);
        Page_Income = new QWidget();
        Page_Income->setObjectName(QString::fromUtf8("Page_Income"));
        TB_Income = new QTableWidget(Page_Income);
        TB_Income->setObjectName(QString::fromUtf8("TB_Income"));
        TB_Income->setGeometry(QRect(10, 60, 1301, 911));
        QFont font6;
        font6.setPointSize(18);
        font6.setKerning(true);
        TB_Income->setFont(font6);
        groupBox_2 = new QGroupBox(Page_Income);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 371, 51));
        LE_Inc_Year = new QLineEdit(groupBox_2);
        LE_Inc_Year->setObjectName(QString::fromUtf8("LE_Inc_Year"));
        LE_Inc_Year->setGeometry(QRect(90, 10, 113, 31));
        LE_Inc_Year->setFont(font3);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 61, 31));
        label_7->setFont(font3);
        PB_Que_Inc = new QPushButton(groupBox_2);
        PB_Que_Inc->setObjectName(QString::fromUtf8("PB_Que_Inc"));
        PB_Que_Inc->setGeometry(QRect(230, 0, 131, 51));
        PB_Que_Inc->setFont(font3);
        PB_Out_Inc = new QPushButton(Page_Income);
        PB_Out_Inc->setObjectName(QString::fromUtf8("PB_Out_Inc"));
        PB_Out_Inc->setGeometry(QRect(380, 0, 131, 51));
        PB_Out_Inc->setFont(font3);
        stackedWidget->addWidget(Page_Income);
        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        stackedWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "\351\270\255\351\270\255\344\276\277\345\210\251\345\272\227\345\220\216\345\217\260\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        PB_MainPage->setText(QCoreApplication::translate("MainWindowClass", "\351\246\226\351\241\265", nullptr));
        PB_Merchandise->setText(QCoreApplication::translate("MainWindowClass", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        PB_Inventory->setText(QCoreApplication::translate("MainWindowClass", "\345\272\223\345\255\230\347\256\241\347\220\206", nullptr));
        PB_Purchase->setText(QCoreApplication::translate("MainWindowClass", "\351\207\207\350\264\255\347\256\241\347\220\206", nullptr));
        PB_Sell->setText(QCoreApplication::translate("MainWindowClass", "\345\207\272\345\224\256\347\256\241\347\220\206", nullptr));
        PB_Supplier->setText(QCoreApplication::translate("MainWindowClass", "\344\276\233\345\272\224\347\256\241\347\220\206", nullptr));
        PB_Staff->setText(QCoreApplication::translate("MainWindowClass", "\344\272\272\345\221\230\347\256\241\347\220\206", nullptr));
        PB_Income->setText(QCoreApplication::translate("MainWindowClass", "\346\224\266\346\224\257\347\256\241\347\220\206", nullptr));
        label_5->setText(QString());
        label->setText(QCoreApplication::translate("MainWindowClass", "<html><head/><body><p>\350\256\276\350\256\241\346\210\220\345\221\230\357\274\232<span style=\" font-weight:400;\">\345\210\230\346\226\207\350\266\212\343\200\201\347\216\213\345\255\220\345\215\223\343\200\201\346\235\216\346\254\243\350\223\211\343\200\201\350\256\270 \347\235\277</span></p><p>\346\214\207\345\257\274\350\200\201\345\270\210\357\274\232<span style=\" font-weight:400;\">\346\235\216\346\231\223\350\216\211</span></p></body></html>", nullptr));
        PB_Add_Mer->setText(QCoreApplication::translate("MainWindowClass", "\346\267\273\345\212\240\345\225\206\345\223\201", nullptr));
        PB_Mdf_Mer->setText(QCoreApplication::translate("MainWindowClass", "\344\277\256\346\224\271\345\225\206\345\223\201", nullptr));
        groupBox->setTitle(QString());
        PB_Que_Mer->setText(QCoreApplication::translate("MainWindowClass", "\346\237\245\350\257\242\345\225\206\345\223\201", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindowClass", "\345\225\206\345\223\201\345\220\215\357\274\232", nullptr));
        groupBox_3->setTitle(QString());
        PB_Sel_Mer->setText(QCoreApplication::translate("MainWindowClass", "\347\255\233\351\200\211\347\261\273\345\236\213", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindowClass", "\347\261\273\345\236\213\357\274\232", nullptr));
        CB_merchandise->setItemText(0, QCoreApplication::translate("MainWindowClass", "\351\243\237\345\223\201\347\261\273", nullptr));
        CB_merchandise->setItemText(1, QCoreApplication::translate("MainWindowClass", "\351\245\256\345\223\201\347\261\273", nullptr));
        CB_merchandise->setItemText(2, QCoreApplication::translate("MainWindowClass", "\346\227\245\347\224\250\347\261\273", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindowClass", "\351\270\255\351\270\255\344\276\277\345\210\251\345\272\227\345\272\223\345\255\230", nullptr));
        PB_Inv_ID->setText(QCoreApplication::translate("MainWindowClass", "ID\346\216\222\345\272\217", nullptr));
        PB_Inv_Type->setText(QCoreApplication::translate("MainWindowClass", "\347\261\273\345\236\213\346\216\222\345\272\217", nullptr));
        PB_Inv_Name->setText(QCoreApplication::translate("MainWindowClass", "\345\220\215\347\247\260\346\216\222\345\272\217", nullptr));
        PB_Inv_Inv->setText(QCoreApplication::translate("MainWindowClass", "\345\272\223\345\255\230\346\216\222\345\272\217", nullptr));
        PB_Inv_Output->setText(QCoreApplication::translate("MainWindowClass", "\345\257\274\345\207\272\345\272\223\345\255\230", nullptr));
        PB_Add_Purchase->setText(QCoreApplication::translate("MainWindowClass", "\345\242\236\345\212\240\351\207\207\350\264\255\350\256\260\345\275\225", nullptr));
        PB_Del_Purchase->setText(QCoreApplication::translate("MainWindowClass", "\345\210\240\351\231\244\351\207\207\350\264\255\350\256\260\345\275\225", nullptr));
        PB_Out_Purchase->setText(QCoreApplication::translate("MainWindowClass", "\345\257\274\345\207\272\351\207\207\350\264\255\350\256\260\345\275\225", nullptr));
        PB_Add_Sell->setText(QCoreApplication::translate("MainWindowClass", "\346\226\260\345\242\236\345\207\272\345\224\256\350\256\260\345\275\225", nullptr));
        PB_Del_Sell->setText(QCoreApplication::translate("MainWindowClass", "\345\210\240\351\231\244\345\207\272\345\224\256\350\256\260\345\275\225", nullptr));
        PB_Out_Sell->setText(QCoreApplication::translate("MainWindowClass", "\345\257\274\345\207\272\345\207\272\345\224\256\350\256\260\345\275\225", nullptr));
        PB_Add_Supplier->setText(QCoreApplication::translate("MainWindowClass", "\345\242\236\345\212\240\344\276\233\345\272\224\345\225\206", nullptr));
        PB_Mdf_Supplier->setText(QCoreApplication::translate("MainWindowClass", "\344\277\256\346\224\271\344\276\233\345\272\224\345\225\206", nullptr));
        PB_Del_Supplier->setText(QCoreApplication::translate("MainWindowClass", "\345\210\240\351\231\244\344\276\233\345\272\224\345\225\206", nullptr));
        PB_Out_Supplier->setText(QCoreApplication::translate("MainWindowClass", "\345\257\274\345\207\272\344\276\233\345\272\224\345\225\206", nullptr));
        PB_Add_Staff->setText(QCoreApplication::translate("MainWindowClass", "\346\226\260\345\242\236\345\221\230\345\267\245", nullptr));
        PB_Del_Staff->setText(QCoreApplication::translate("MainWindowClass", "\345\210\240\351\231\244\345\221\230\345\267\245", nullptr));
        PB_Mdf_Staff->setText(QCoreApplication::translate("MainWindowClass", "\344\277\256\346\224\271\345\221\230\345\267\245", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowClass", "No Permission!!!", nullptr));
        label_6->setText(QString());
        groupBox_2->setTitle(QString());
        label_7->setText(QCoreApplication::translate("MainWindowClass", "\345\271\264\344\273\275\357\274\232", nullptr));
        PB_Que_Inc->setText(QCoreApplication::translate("MainWindowClass", "\346\237\245\350\257\242\346\224\266\346\224\257", nullptr));
        PB_Out_Inc->setText(QCoreApplication::translate("MainWindowClass", "\345\257\274\345\207\272\346\212\245\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

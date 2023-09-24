/********************************************************************************
** Form generated from reading UI file 'Production_System_with_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTION_SYSTEM_WITH_GUI_H
#define UI_PRODUCTION_SYSTEM_WITH_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Production_System_with_GUIClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *PB_sel_fact;
    QPushButton *PB_start;
    QPushButton *PB_add_rule;
    QTableWidget *TB_rules;
    QLabel *label;
    QTableWidget *TB_facts;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTableWidget *TB_facts_selected;
    QTableWidget *TB_process;

    void setupUi(QMainWindow *Production_System_with_GUIClass)
    {
        if (Production_System_with_GUIClass->objectName().isEmpty())
            Production_System_with_GUIClass->setObjectName(QString::fromUtf8("Production_System_with_GUIClass"));
        Production_System_with_GUIClass->resize(1080, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Production_System_with_GUIClass->sizePolicy().hasHeightForWidth());
        Production_System_with_GUIClass->setSizePolicy(sizePolicy);
        Production_System_with_GUIClass->setMinimumSize(QSize(1080, 720));
        Production_System_with_GUIClass->setMaximumSize(QSize(1080, 720));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/liuwy/Desktop/\345\217\257\350\276\276\351\270\255\345\274\202\350\211\262.png"), QSize(), QIcon::Normal, QIcon::Off);
        Production_System_with_GUIClass->setWindowIcon(icon);
        centralWidget = new QWidget(Production_System_with_GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(930, 10, 131, 491));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 111, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        PB_sel_fact = new QPushButton(verticalLayoutWidget);
        PB_sel_fact->setObjectName(QString::fromUtf8("PB_sel_fact"));

        verticalLayout->addWidget(PB_sel_fact);

        PB_start = new QPushButton(verticalLayoutWidget);
        PB_start->setObjectName(QString::fromUtf8("PB_start"));

        verticalLayout->addWidget(PB_start);

        PB_add_rule = new QPushButton(verticalLayoutWidget);
        PB_add_rule->setObjectName(QString::fromUtf8("PB_add_rule"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PB_add_rule->sizePolicy().hasHeightForWidth());
        PB_add_rule->setSizePolicy(sizePolicy1);
        PB_add_rule->setMinimumSize(QSize(0, 0));
        PB_add_rule->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(PB_add_rule);

        TB_rules = new QTableWidget(centralWidget);
        TB_rules->setObjectName(QString::fromUtf8("TB_rules"));
        TB_rules->setGeometry(QRect(30, 30, 431, 491));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 91, 16));
        TB_facts = new QTableWidget(centralWidget);
        TB_facts->setObjectName(QString::fromUtf8("TB_facts"));
        TB_facts->setGeometry(QRect(480, 30, 431, 251));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 10, 91, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 530, 91, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 290, 91, 16));
        TB_facts_selected = new QTableWidget(centralWidget);
        TB_facts_selected->setObjectName(QString::fromUtf8("TB_facts_selected"));
        TB_facts_selected->setGeometry(QRect(480, 310, 431, 211));
        TB_process = new QTableWidget(centralWidget);
        TB_process->setObjectName(QString::fromUtf8("TB_process"));
        TB_process->setGeometry(QRect(30, 550, 431, 151));
        Production_System_with_GUIClass->setCentralWidget(centralWidget);

        retranslateUi(Production_System_with_GUIClass);

        QMetaObject::connectSlotsByName(Production_System_with_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Production_System_with_GUIClass)
    {
        Production_System_with_GUIClass->setWindowTitle(QCoreApplication::translate("Production_System_with_GUIClass", "\344\270\223\345\256\266\346\216\250\347\220\206\347\263\273\347\273\237", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Production_System_with_GUIClass", "\346\223\215\344\275\234", nullptr));
        PB_sel_fact->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\351\200\211\346\213\251\344\272\213\345\256\236", nullptr));
        PB_start->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\345\274\200\345\247\213\346\216\250\347\220\206", nullptr));
        PB_add_rule->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\346\267\273\345\212\240\350\247\204\345\210\231", nullptr));
        label->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\347\216\260\346\234\211\350\247\204\345\210\231\345\272\223\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\347\216\260\346\234\211\344\272\213\345\256\236\345\272\223\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\346\216\250\345\257\274\350\277\207\347\250\213\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\351\200\211\346\213\251\344\272\213\345\256\236\345\272\223\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Production_System_with_GUIClass: public Ui_Production_System_with_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTION_SYSTEM_WITH_GUI_H

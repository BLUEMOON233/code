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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Production_System_with_GUIClass
{
public:
    QWidget *centralWidget;
    QTableWidget *TB_rules;
    QLabel *label;
    QTableWidget *TB_facts;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTableWidget *TB_facts_selected;
    QTableWidget *TB_process;
    QPushButton *PB_start;
    QPushButton *PB_add_rule;
    QPushButton *PB_clear_fact_sel;
    QPushButton *PB_clear_process;
    QLabel *label_5;
    QLabel *LB_result;

    void setupUi(QMainWindow *Production_System_with_GUIClass)
    {
        if (Production_System_with_GUIClass->objectName().isEmpty())
            Production_System_with_GUIClass->setObjectName(QString::fromUtf8("Production_System_with_GUIClass"));
        Production_System_with_GUIClass->resize(1620, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Production_System_with_GUIClass->sizePolicy().hasHeightForWidth());
        Production_System_with_GUIClass->setSizePolicy(sizePolicy);
        Production_System_with_GUIClass->setMinimumSize(QSize(1620, 1080));
        Production_System_with_GUIClass->setMaximumSize(QSize(1620, 1080));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/liuwy/Desktop/\345\217\257\350\276\276\351\270\255\345\274\202\350\211\262.png"), QSize(), QIcon::Normal, QIcon::Off);
        Production_System_with_GUIClass->setWindowIcon(icon);
        centralWidget = new QWidget(Production_System_with_GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TB_rules = new QTableWidget(centralWidget);
        TB_rules->setObjectName(QString::fromUtf8("TB_rules"));
        TB_rules->setGeometry(QRect(30, 60, 651, 881));
        QFont font;
        font.setPointSize(14);
        TB_rules->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 161, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        TB_facts = new QTableWidget(centralWidget);
        TB_facts->setObjectName(QString::fromUtf8("TB_facts"));
        TB_facts->setGeometry(QRect(700, 60, 450, 481));
        QFont font2;
        font2.setPointSize(12);
        TB_facts->setFont(font2);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(700, 20, 161, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(700, 560, 161, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1160, 20, 161, 31));
        label_4->setFont(font1);
        TB_facts_selected = new QTableWidget(centralWidget);
        TB_facts_selected->setObjectName(QString::fromUtf8("TB_facts_selected"));
        TB_facts_selected->setGeometry(QRect(1160, 60, 450, 481));
        TB_facts_selected->setFont(font2);
        TB_process = new QTableWidget(centralWidget);
        TB_process->setObjectName(QString::fromUtf8("TB_process"));
        TB_process->setGeometry(QRect(700, 600, 911, 341));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        TB_process->setFont(font3);
        PB_start = new QPushButton(centralWidget);
        PB_start->setObjectName(QString::fromUtf8("PB_start"));
        PB_start->setGeometry(QRect(50, 960, 151, 71));
        PB_start->setFont(font1);
        PB_add_rule = new QPushButton(centralWidget);
        PB_add_rule->setObjectName(QString::fromUtf8("PB_add_rule"));
        PB_add_rule->setGeometry(QRect(220, 960, 151, 71));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PB_add_rule->sizePolicy().hasHeightForWidth());
        PB_add_rule->setSizePolicy(sizePolicy1);
        PB_add_rule->setMinimumSize(QSize(0, 0));
        PB_add_rule->setBaseSize(QSize(0, 0));
        PB_add_rule->setFont(font1);
        PB_clear_fact_sel = new QPushButton(centralWidget);
        PB_clear_fact_sel->setObjectName(QString::fromUtf8("PB_clear_fact_sel"));
        PB_clear_fact_sel->setGeometry(QRect(1420, 960, 171, 71));
        sizePolicy1.setHeightForWidth(PB_clear_fact_sel->sizePolicy().hasHeightForWidth());
        PB_clear_fact_sel->setSizePolicy(sizePolicy1);
        PB_clear_fact_sel->setMinimumSize(QSize(0, 0));
        PB_clear_fact_sel->setBaseSize(QSize(0, 0));
        PB_clear_fact_sel->setFont(font1);
        PB_clear_process = new QPushButton(centralWidget);
        PB_clear_process->setObjectName(QString::fromUtf8("PB_clear_process"));
        PB_clear_process->setGeometry(QRect(1200, 960, 201, 71));
        sizePolicy1.setHeightForWidth(PB_clear_process->sizePolicy().hasHeightForWidth());
        PB_clear_process->setSizePolicy(sizePolicy1);
        PB_clear_process->setMinimumSize(QSize(0, 0));
        PB_clear_process->setBaseSize(QSize(0, 0));
        PB_clear_process->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(700, 960, 151, 31));
        label_5->setFont(font1);
        LB_result = new QLabel(centralWidget);
        LB_result->setObjectName(QString::fromUtf8("LB_result"));
        LB_result->setGeometry(QRect(840, 950, 341, 51));
        QFont font4;
        font4.setPointSize(20);
        LB_result->setFont(font4);
        LB_result->setLayoutDirection(Qt::LeftToRight);
        LB_result->setStyleSheet(QString::fromUtf8("background-color: white;"));
        Production_System_with_GUIClass->setCentralWidget(centralWidget);

        retranslateUi(Production_System_with_GUIClass);

        QMetaObject::connectSlotsByName(Production_System_with_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Production_System_with_GUIClass)
    {
        Production_System_with_GUIClass->setWindowTitle(QCoreApplication::translate("Production_System_with_GUIClass", "\344\270\223\345\256\266\346\216\250\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\347\216\260\346\234\211\350\247\204\345\210\231\345\272\223\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\347\216\260\346\234\211\344\272\213\345\256\236\345\272\223\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\346\216\250\345\257\274\350\277\207\347\250\213\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\351\200\211\346\213\251\344\272\213\345\256\236\345\272\223\357\274\232", nullptr));
        PB_start->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\345\274\200\345\247\213\346\216\250\347\220\206", nullptr));
        PB_add_rule->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\346\267\273\345\212\240\350\247\204\345\210\231", nullptr));
        PB_clear_fact_sel->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\346\270\205\347\251\272\344\272\213\344\273\266\345\272\223", nullptr));
        PB_clear_process->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\346\270\205\347\251\272\346\216\250\345\257\274\350\277\207\347\250\213", nullptr));
        label_5->setText(QCoreApplication::translate("Production_System_with_GUIClass", "\346\216\250\345\257\274\347\273\223\346\236\234\357\274\232", nullptr));
        LB_result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Production_System_with_GUIClass: public Ui_Production_System_with_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTION_SYSTEM_WITH_GUI_H

/********************************************************************************
** Form generated from reading UI file 'DialogButtonBottom.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGBUTTONBOTTOM_H
#define UI_DIALOGBUTTONBOTTOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QSpinBox *SB_num;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *RB_group;
    QRadioButton *RB_and;
    QRadioButton *RB_or;
    QPushButton *PB_add;
    QPushButton *PB_cancel;
    QTableWidget *TB_rule_added;
    QCheckBox *CB_result;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(569, 394);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(430, 20, 120, 221));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 290, 81, 31));
        SB_num = new QSpinBox(groupBox);
        SB_num->setObjectName(QString::fromUtf8("SB_num"));
        SB_num->setGeometry(QRect(10, 60, 101, 31));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        SB_num->setFont(font1);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 81, 41));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 81, 41));
        label_2->setFont(font2);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 130, 102, 81));
        RB_group = new QVBoxLayout(layoutWidget);
        RB_group->setObjectName(QString::fromUtf8("RB_group"));
        RB_group->setContentsMargins(0, 0, 0, 0);
        RB_and = new QRadioButton(layoutWidget);
        RB_and->setObjectName(QString::fromUtf8("RB_and"));
        RB_and->setFont(font2);

        RB_group->addWidget(RB_and);

        RB_or = new QRadioButton(layoutWidget);
        RB_or->setObjectName(QString::fromUtf8("RB_or"));
        RB_or->setFont(font2);

        RB_group->addWidget(RB_or);

        PB_add = new QPushButton(Dialog);
        PB_add->setObjectName(QString::fromUtf8("PB_add"));
        PB_add->setGeometry(QRect(440, 290, 101, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        PB_add->setFont(font3);
        PB_cancel = new QPushButton(Dialog);
        PB_cancel->setObjectName(QString::fromUtf8("PB_cancel"));
        PB_cancel->setGeometry(QRect(440, 340, 101, 41));
        PB_cancel->setFont(font3);
        TB_rule_added = new QTableWidget(Dialog);
        TB_rule_added->setObjectName(QString::fromUtf8("TB_rule_added"));
        TB_rule_added->setGeometry(QRect(10, 10, 411, 371));
        QFont font4;
        font4.setPointSize(14);
        TB_rule_added->setFont(font4);
        CB_result = new QCheckBox(Dialog);
        CB_result->setObjectName(QString::fromUtf8("CB_result"));
        CB_result->setGeometry(QRect(430, 250, 121, 31));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        CB_result->setFont(font5);

        retranslateUi(Dialog);
        QObject::connect(PB_cancel, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\346\226\260\345\242\236\350\247\204\345\210\231", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\345\217\202\346\225\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\345\211\215\344\273\266\346\225\260\351\207\217", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "\351\200\273\350\276\221", nullptr));
        RB_and->setText(QCoreApplication::translate("Dialog", "\344\270\216", nullptr));
        RB_or->setText(QCoreApplication::translate("Dialog", "\346\210\226", nullptr));
        PB_add->setText(QCoreApplication::translate("Dialog", "\346\267\273\345\212\240", nullptr));
        PB_cancel->setText(QCoreApplication::translate("Dialog", "\345\217\226\346\266\210", nullptr));
        CB_result->setText(QCoreApplication::translate("Dialog", "\347\273\223\350\256\272\344\270\272\347\233\256\346\240\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGBUTTONBOTTOM_H

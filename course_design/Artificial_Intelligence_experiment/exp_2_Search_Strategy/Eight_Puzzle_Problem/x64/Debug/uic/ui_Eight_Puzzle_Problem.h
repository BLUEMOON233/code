/********************************************************************************
** Form generated from reading UI file 'Eight_Puzzle_Problem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EIGHT_PUZZLE_PROBLEM_H
#define UI_EIGHT_PUZZLE_PROBLEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Eight_Puzzle_ProblemClass
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *Eight_Puzzle_ProblemClass)
    {
        if (Eight_Puzzle_ProblemClass->objectName().isEmpty())
            Eight_Puzzle_ProblemClass->setObjectName(QString::fromUtf8("Eight_Puzzle_ProblemClass"));
        Eight_Puzzle_ProblemClass->resize(600, 400);
        centralWidget = new QWidget(Eight_Puzzle_ProblemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Eight_Puzzle_ProblemClass->setCentralWidget(centralWidget);

        retranslateUi(Eight_Puzzle_ProblemClass);

        QMetaObject::connectSlotsByName(Eight_Puzzle_ProblemClass);
    } // setupUi

    void retranslateUi(QMainWindow *Eight_Puzzle_ProblemClass)
    {
        Eight_Puzzle_ProblemClass->setWindowTitle(QCoreApplication::translate("Eight_Puzzle_ProblemClass", "Eight_Puzzle_Problem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Eight_Puzzle_ProblemClass: public Ui_Eight_Puzzle_ProblemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EIGHT_PUZZLE_PROBLEM_H

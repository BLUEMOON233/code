#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "subwindows.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFile file;

private slots:
    void showProject1Dialog()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void showProject2Dialog()
    {
         ui->stackedWidget->setCurrentIndex(2);
    }

    void showProject3Dialog()
    {
         ui->stackedWidget->setCurrentIndex(3);
    }

    void returnProject()
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
};

#endif // MAINWINDOW_H

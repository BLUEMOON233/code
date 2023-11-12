#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow1 *subWindow1 = new MainWindow1();
    MainWindow2 *subWindow2 = new MainWindow2();
    MainWindow3 *subWindow3 = new MainWindow3();
    ui->stackedWidget->addWidget(subWindow1);
    ui->stackedWidget->addWidget(subWindow2);
    ui->stackedWidget->addWidget(subWindow3);

    // 连接按钮的点击信号与槽函数
    connect(ui->PB_led, &QPushButton::clicked, this, &MainWindow::showProject1Dialog);
    connect(ui->PB_beep, &QPushButton::clicked, this, &MainWindow::showProject2Dialog);
    connect(ui->PB_ii2c, &QPushButton::clicked, this, &MainWindow::showProject3Dialog);
    connect(ui->PB_ret, &QPushButton::clicked, this, &MainWindow::returnProject);
}

MainWindow::~MainWindow()
{
    delete ui;
}


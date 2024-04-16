#pragma once

#include <QtWidgets/QMainWindow>
#include <QUdpSocket>
#include <QDateTime>
#include "ui_exp_2_Client.h"

class exp_2_Client : public QMainWindow
{
    Q_OBJECT

public:
    exp_2_Client(QWidget *parent = nullptr);
    ~exp_2_Client();

private:
    Ui::exp_2_ClientClass ui;
    QUdpSocket* udpSocket = nullptr;
};

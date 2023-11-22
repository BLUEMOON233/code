#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Fatigue_Detection_System.h"
#include "Fatigue_Detection.h"
#include <QFileDialog>
#include <QTimer>

class Fatigue_Detection_System : public QMainWindow
{
    Q_OBJECT

public:
    Fatigue_Detection_System(QWidget *parent = nullptr);
    ~Fatigue_Detection_System();

private:
    Ui::Fatigue_Detection_SystemClass ui;
    QTimer* timer;
    Fatigue_Detection* fatigue_detection;
    int index_frame = 0;
    const double tar_fps = 10;

private slots:
    void update_frame();
};

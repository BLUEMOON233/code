#ifndef SUBWINDOWS_H
#define SUBWINDOWS_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QFile>
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>
#include <QRect>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "arcgraph.h"
#include "glowtext.h"
#include "ap3216c.h"
#include "headview/headview.h"

class MainWindow1 : public QWidget
{
    Q_OBJECT

public:
    MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private:
    /* 按钮 */
    QPushButton *pushButton;

    /* 文件 */
    QFile file;

    /* 设置lED的状态 */
    void setLedState();

    /* 获取lED的状态 */
    bool getLedState();

private slots:
    void pushButtonClicked();
};

class MainWindow2 : public QWidget
{
    Q_OBJECT

public:
    MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();

private:
    /* 按钮 */
    QPushButton *pushButton;

    /* 文件 */
    QFile file;

    /* 设置BEEP的状态 */
    void setBeepState();

    /* 获取BEEP的状态 */
    bool getBeepState();

private slots:
    /* 槽函数 */
    void pushButtonClicked();
};


class ArcGraph;
class GlowText;
class Ap3216c;
class HeadView;

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow3(QWidget *parent = nullptr);
    ~MainWindow3();

private:
    ArcGraph *arcGraph[3];
    GlowText *glowText[3];

    QVBoxLayout *vBoxLayout;
    QHBoxLayout *hBoxLayout[5];

    GlowText *test;

    /* 容器作用，用于布局 */
    QWidget *widget[6];

    /* 标签文本 */
    QLabel *label[3];

    /* ii2传感器类 */
    Ap3216c *ap3216c;

    /* 视图表头 */
    HeadView *headView;

private slots:
    /* 获取ap3216传感器数据 */
    void getAp3216cData();
};

#endif // SUBWINDOWS_H

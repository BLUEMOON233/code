#include "subwindows.h"


MainWindow1::MainWindow1(QWidget *parent)
    : QWidget(parent)
{
    /* 获取屏幕的分辨率，Qt官方建议使用这
     * 种方法获取屏幕分辨率，防上多屏设备导致对应不上
     * 注意，这是获取整个桌面系统的分辨率
     */
    QList <QScreen *> list_screen =  QGuiApplication::screens();

    /* 如果是ARM平台，直接设置大小为屏幕的大小 */
#if __arm__
    /* 重设大小 */
    this->resize(list_screen.at(0)->geometry().width(),
                 list_screen.at(0)->geometry().height());
    /* 默认是出厂系统的LED心跳的触发方式,想要控制LED，
     * 需要改变LED的触发方式，改为none，即无 */
    system("echo none > /sys/class/leds/sys-led/trigger");
#else
    /* 否则则设置主窗体大小为800x480 */
    this->resize(800, 480);
#endif

    pushButton = new QPushButton(this);

    /* 居中显示 */
    pushButton->setMinimumSize(200, 50);
    pushButton->setGeometry((this->width() - pushButton->width()) /2 ,
                            (this->height() - pushButton->height()) /2,
                            pushButton->width(),
                            pushButton->height()
                            );
    /* 开发板的LED控制接口 */
    file.setFileName("/sys/devices/platform/leds/leds/sys-led/brightness");

    if (!file.exists())
        /* 设置按钮的初始化文本 */
        pushButton->setText("未获取到LED设备！");

    /* 获取LED的状态 */
    getLedState();

    /* 信号槽连接 */
    connect(pushButton, SIGNAL(clicked()),
            this, SLOT(pushButtonClicked()));
}

MainWindow1::~MainWindow1()
{
}

void MainWindow1::setLedState()
{
    /* 在设置LED状态时先读取 */
    bool state = getLedState();

    /* 如果文件不存在，则返回 */
    if (!file.exists())
        return;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QByteArray buf[2] = {"0", "1"};

    /* 写0或1 */
    if (state)
        file.write(buf[0]);
    else
        file.write(buf[1]);

    /* 关闭文件 */
    file.close();

    /*重新获取LED的状态 */
    getLedState();
}

bool MainWindow1::getLedState()
{
    /* 如果文件不存在，则返回 */
    if (!file.exists())
        return false;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QTextStream in(&file);

    /* 读取文件所有数据 */
    QString buf = in.readLine();

    /* 打印出读出的值 */
    qDebug()<<"buf: "<<buf<<endl;
    file.close();
    if (buf == "1") {
        pushButton->setText("LED点亮");
        return true;
    } else {
        pushButton->setText("LED熄灭");
        return false;
    }
}

void MainWindow1::pushButtonClicked()
{
    /* 设置LED的状态 */
    setLedState();
}




MainWindow2::MainWindow2(QWidget *parent)
    : QWidget(parent)
{
    /* 获取屏幕的分辨率，Qt官方建议使用这
     * 种方法获取屏幕分辨率，防上多屏设备导致对应不上
     * 注意，这是获取整个桌面系统的分辨率
     */
    QList <QScreen *> list_screen =  QGuiApplication::screens();

    /* 如果是ARM平台，直接设置大小为屏幕的大小 */
#if __arm__
    /* 重设大小 */
    this->resize(list_screen.at(0)->geometry().width(),
                 list_screen.at(0)->geometry().height());
#else
    /* 否则则设置主窗体大小为800x480 */
    this->resize(800, 480);
#endif

    pushButton = new QPushButton(this);

    /* 居中显示 */
    pushButton->setMinimumSize(200, 50);
    pushButton->setGeometry((this->width() - pushButton->width()) /2 ,
                            (this->height() - pushButton->height()) /2,
                            pushButton->width(),
                            pushButton->height()
                            );
    /* 开发板的蜂鸣器控制接口 */
    file.setFileName("/sys/devices/platform/leds/leds/beep/brightness");

    if (!file.exists())
        /* 设置按钮的初始化文本 */
        pushButton->setText("未获取到BEEP设备！");

    /* 获取BEEP的状态 */
    getBeepState();

    /* 信号槽连接 */
    connect(pushButton, SIGNAL(clicked()),
            this, SLOT(pushButtonClicked()));
}


MainWindow2::~MainWindow2()
{
}

void MainWindow2::setBeepState()
{
    /* 在设置BEEP状态时先读取 */
    bool state = getBeepState();

    /* 如果文件不存在，则返回 */
    if (!file.exists())
        return;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QByteArray buf[2] = {"0", "1"};

    if (state)
        file.write(buf[0]);
    else
        file.write(buf[1]);

    file.close();

    getBeepState();
}

bool MainWindow2::getBeepState()
{
    /* 如果文件不存在，则返回 */
    if (!file.exists())
        return false;

    if(!file.open(QIODevice::ReadWrite))
        qDebug()<<file.errorString();

    QTextStream in(&file);

    /* 读取文件所有数据 */
    QString buf = in.readLine();

    /* 打印出读出的值 */
    qDebug()<<"buf: "<<buf<<endl;
    file.close();
    if (buf == "1") {
        pushButton->setText("BEEP开");
        return true;
    } else {
        pushButton->setText("BEEP关");
        return false;
    }
}

void MainWindow2::pushButtonClicked()
{
    /* 设置蜂鸣器的状态 */
    setBeepState();
}

MainWindow3::MainWindow3(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800, 480);
    this->setStyleSheet("background:#011753");

    for (int i = 0; i < 6; i++)
        widget[i] = new QWidget();

    for (int i = 0; i < 3; i++)
        arcGraph[i] = new ArcGraph();

    for (int i = 0; i < 5; i++)
        hBoxLayout[i] = new QHBoxLayout();

    headView = new HeadView();

    QFont font;
    font.setPixelSize(18);

    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::white);

    QStringList list;
    list<<"环境光强度："<<"接近距离："<<"红外强度：";
    for (int i = 0; i < 3; i++) {
        label[i] = new QLabel();
        glowText[i] = new GlowText();
        glowText[i]->setMinimumWidth(30);
        label[i]->setText(list[i]);
        label[i]->setFont(font);
        label[i]->setPalette(pal);
        label[i]->adjustSize();
    }

    vBoxLayout = new QVBoxLayout();

    /* 垂直布局，将主窗体为上下两部分，方便布局 */
    vBoxLayout->addWidget(headView);
    vBoxLayout->addWidget(widget[1]);
    vBoxLayout->addWidget(widget[2]);
    widget[0]->setLayout(vBoxLayout);

    /* 主布局设置为widget[0] */
    setCentralWidget(widget[0]);

    /* 设置widget[1]的高度，不会随界面的大小而变化 */
    widget[2]->setFixedHeight(150);

    /* 三个蓝色科技感弧形图布局，采用水平布局 */
    hBoxLayout[0]->addWidget(arcGraph[0]);
    hBoxLayout[0]->addWidget(arcGraph[1]);
    hBoxLayout[0]->addWidget(arcGraph[2]);
    widget[1]->setLayout(hBoxLayout[0]);

    /* 数据文字容器水平布局, */
    hBoxLayout[1]->addWidget(widget[3]);
    hBoxLayout[1]->addWidget(widget[4]);
    hBoxLayout[1]->addWidget(widget[5]);
    hBoxLayout[1]->setContentsMargins(0, 40, 0, 0);

    widget[2]->setLayout(hBoxLayout[1]);

    /* als布局 */
    hBoxLayout[2]->addWidget(label[0]);
    hBoxLayout[2]->addWidget(glowText[0]);
    hBoxLayout[2]->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    widget[3]->setLayout(hBoxLayout[2]);

    /* ps布局 */
    hBoxLayout[3]->addWidget(label[1]);
    hBoxLayout[3]->addWidget(glowText[1]);
    hBoxLayout[3]->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    widget[4]->setLayout(hBoxLayout[3]);

    /* ir布局 */
    hBoxLayout[4]->addWidget(label[2]);
    hBoxLayout[4]->addWidget(glowText[2]);
    hBoxLayout[4]->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    widget[5]->setLayout(hBoxLayout[4]);

    ap3216c = new Ap3216c(this);
    /* 只能在开发板上开启获取数据，Ubuntu上是没有ap3216c传感器的 */
#if __arm__
    ap3216c->setCapture(true);
#endif

    connect(ap3216c, SIGNAL(ap3216cDataChanged()),
            this, SLOT(getAp3216cData()));
}

MainWindow3::~MainWindow3()
{
}

void MainWindow3::getAp3216cData()
{
    static QString als = ap3216c->alsData();
    if (als != ap3216c->alsData()) {
        als = ap3216c->alsData();
        arcGraph[0]->setangleLength(als.toUInt() * 360 / 65535);
    }

    static QString ps = ap3216c->psData();
    if (ps != ap3216c->psData()) {
        ps = ap3216c->psData();
        arcGraph[1]->setangleLength(ps.toUInt() * 360 / 1023);
    }

    static QString ir = ap3216c->irData();
    if (ir != ap3216c->irData()) {
        ir = ap3216c->irData();
        arcGraph[2]->setangleLength(ir.toUInt() * 360 / 1023);
    }

    glowText[0]->setTextData(als);
    glowText[1]->setTextData(ps);
    glowText[2]->setTextData(ir);
}

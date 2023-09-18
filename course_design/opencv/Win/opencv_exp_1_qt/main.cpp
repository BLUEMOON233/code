#include "opencv_exp_1_qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    opencv_exp_1_qt w;
    w.show();
    return a.exec();
}

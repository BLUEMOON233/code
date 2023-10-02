#include "opencv_exp_2.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    opencv_exp_2 w;
    w.show();
    return a.exec();
}

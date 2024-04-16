#include "exp_2_Client.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    exp_2_Client w;
    w.show();
    return a.exec();
}

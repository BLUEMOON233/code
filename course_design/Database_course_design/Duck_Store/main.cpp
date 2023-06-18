#include "Duck_Store.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Duck_Store w;
    w.show();
    return a.exec();
}

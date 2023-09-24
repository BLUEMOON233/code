#include "Production_System_with_GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    system("chcp 65001");
    QApplication a(argc, argv);
    Production_System_with_GUI w;
    w.show();
    return a.exec();
}

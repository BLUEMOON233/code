#include "Eight_Puzzle_Problem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Eight_Puzzle_Problem w;
    w.show();
    return a.exec();
}

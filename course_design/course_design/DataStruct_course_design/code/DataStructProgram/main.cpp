#include "DataStructProgram.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	DataStructProgram w;
	w.show();
	return a.exec();
}

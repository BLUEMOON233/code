#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Duck_Store.h"
#include "MainWindow.h"

class Duck_Store : public QMainWindow
{
	Q_OBJECT

public:
	Duck_Store(QWidget* parent = nullptr);
	~Duck_Store();

private:
	Ui::Duck_StoreClass ui;
	DataBase* db = nullptr;
};


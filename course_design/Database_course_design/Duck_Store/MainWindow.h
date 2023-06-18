#pragma once

#include <QMainWindow>
#include <QInputDialog>
#include <QFileDialog>
#include <ActiveQt/QAxObject>
#include <QDebug>
#include <QMessageBox>
#include "ui_MainWindow.h"
#include "DataBase.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent, DataBase* db);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
	DataBase* db;
};
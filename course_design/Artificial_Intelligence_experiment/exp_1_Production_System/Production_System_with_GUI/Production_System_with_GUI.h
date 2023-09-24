#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_Production_System_with_GUI.h"
#include "ui_DialogButtonBottom.h"
#include "ProductionSystem.h"

class Production_System_with_GUI : public QMainWindow
{
	Q_OBJECT

public:
	Production_System_with_GUI(QWidget* parent = nullptr);
	~Production_System_with_GUI();

private:
	void init_ui();

	Ui::Production_System_with_GUIClass ui;
	DataBase* db;
	std::set<std::pair<int, std::string>> fact_selected;
};

class DialogButtonBottom : public QDialog
{
	Q_OBJECT

public:
	explicit DialogButtonBottom(QWidget* parent = nullptr);
	~DialogButtonBottom();

signals:
	void data_ret(const Rule& data);
	

private:
	Ui::Dialog ui;
	
};
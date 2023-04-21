#pragma once
#include<iostream>
#include <QtWidgets/QMainWindow>
#include "DivergenceSystem.h"
#include "ui_DataStructProgram.h"

class DataStructProgram : public QMainWindow
{
	Q_OBJECT

public:
	DataStructProgram(QWidget* parent = Q_NULLPTR);

private:
	Ui::DataStructProgramClass* ui;
	D_S_PretreatSystem DSP;
	D_S_TreatedSystem DSTS;
	D_S_SegmentTree DSST;
};

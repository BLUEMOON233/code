#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_Eight_Puzzle_Problem.h"
#include "Eight_Puzzle.h"
#include "windows.h"

class Eight_Puzzle_Problem : public QMainWindow
{
    Q_OBJECT

public:
    Eight_Puzzle_Problem(QWidget *parent = nullptr);
    ~Eight_Puzzle_Problem();
    void show_state();
	bool DFS();
	bool BFS();
	bool a_star_manhatten();
	bool a_star_Euclidean();
	bool a_star_wrongpos();
	bool DFS_iterative_deepening();
	bool a_star_iterative_deepening();
	bool biBFS();

private:
    Ui::Eight_Puzzle_ProblemClass ui;
    Eight_Puzzle puzzle;
};

#include "Eight_Puzzle_Problem.h"

Eight_Puzzle_Problem::Eight_Puzzle_Problem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    puzzle.BFS();
    for (auto path : puzzle.get_paths()) {
        path.print();
    }
}

Eight_Puzzle_Problem::~Eight_Puzzle_Problem()
{}

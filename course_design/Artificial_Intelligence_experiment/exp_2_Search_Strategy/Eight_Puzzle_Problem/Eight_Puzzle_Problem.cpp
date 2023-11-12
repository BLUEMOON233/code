#include "Eight_Puzzle_Problem.h"

Eight_Puzzle_Problem::Eight_Puzzle_Problem(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	puzzle.set_random_state();
	this->show_state();

	connect(ui.PB_check_solve, &QPushButton::clicked, [=]()mutable {
		bool tar = puzzle.check_target();
		if (tar) {
			QMessageBox::information(NULL, "提示", "该问题可解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		else {
			QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		});

	connect(ui.PB_random, &QPushButton::clicked, [=]()mutable {
		puzzle.set_random_state();
		this->show_state();
		});

	connect(ui.PB_dfs, &QPushButton::clicked, [=]()mutable {
		this->DFS();
		});

	connect(ui.PB_bfs, &QPushButton::clicked, [=]()mutable {
		this->BFS();
		});

	connect(ui.PB_aman, &QPushButton::clicked, [=]()mutable {
		this->a_star_manhatten();
		});

	connect(ui.PB_aeuc, &QPushButton::clicked, [=]()mutable {
		this->a_star_Euclidean();
		});

	connect(ui.PB_awor, &QPushButton::clicked, [=]()mutable {
		this->a_star_wrongpos();
		});

	connect(ui.PB_iddfs, &QPushButton::clicked, [=]()mutable {
		this->DFS_iterative_deepening();
		});

	connect(ui.PB_ida, &QPushButton::clicked, [=]()mutable {
		this->a_star_iterative_deepening();
		});

	connect(ui.PB_bibfs, &QPushButton::clicked, [=]()mutable {
		this->biBFS();
		});

	connect(ui.PB_all_start, &QPushButton::clicked, [=]() {
		bool tar = this->DFS();
		if (!tar) {
			return;
		}
		//this->DFS();
		this->BFS();
		this->a_star_manhatten();
		this->a_star_Euclidean();
		this->a_star_wrongpos();
		this->DFS_iterative_deepening();
		this->a_star_iterative_deepening();
		this->biBFS();
		});
}

Eight_Puzzle_Problem::~Eight_Puzzle_Problem()
{}

void Eight_Puzzle_Problem::show_state() {
	std::string st = puzzle.get_start_state();
	std::string en = puzzle.get_end_state();
	ui.st_0->setText(QString(st[0]));
	ui.st_1->setText(QString(st[1]));
	ui.st_2->setText(QString(st[2]));
	ui.st_3->setText(QString(st[3]));
	ui.st_4->setText(QString(st[4]));
	ui.st_5->setText(QString(st[5]));
	ui.st_6->setText(QString(st[6]));
	ui.st_7->setText(QString(st[7]));
	ui.st_8->setText(QString(st[8]));
	ui.en_0->setText(QString(en[0]));
	ui.en_1->setText(QString(en[1]));
	ui.en_2->setText(QString(en[2]));
	ui.en_3->setText(QString(en[3]));
	ui.en_4->setText(QString(en[4]));
	ui.en_5->setText(QString(en[5]));
	ui.en_6->setText(QString(en[6]));
	ui.en_7->setText(QString(en[7]));
	ui.en_8->setText(QString(en[8]));
}

bool Eight_Puzzle_Problem::DFS() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.DFS();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_dfs_time->setText(QString::number(cost_time));
	ui.LE_dfs_path->setText(QString::number(paths.size()));
	ui.LE_dfs_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_dfs->setText(text);
	return true;
}

bool Eight_Puzzle_Problem::BFS() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.BFS();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_bfs_time->setText(QString::number(cost_time));
	ui.LE_bfs_path->setText(QString::number(paths.size()));
	ui.LE_bfs_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_bfs->setText(text);
	return true;
}


bool Eight_Puzzle_Problem::a_star_manhatten() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.a_star_manhatten();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_aman_time->setText(QString::number(cost_time));
	ui.LE_aman_path->setText(QString::number(paths.size()));
	ui.LE_aman_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_aman->setText(text);
	return true;
}

bool Eight_Puzzle_Problem::a_star_Euclidean() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.a_star_Euclidean();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_aeuc_time->setText(QString::number(cost_time));
	ui.LE_aeuc_path->setText(QString::number(paths.size()));
	ui.LE_aeuc_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_aeuc->setText(text);
	return true;
}

bool Eight_Puzzle_Problem::a_star_wrongpos() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.a_star_wrongpos();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_awor_time->setText(QString::number(cost_time));
	ui.LE_awor_path->setText(QString::number(paths.size()));
	ui.LE_awor_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_awor->setText(text);
	return true;
}

bool Eight_Puzzle_Problem::DFS_iterative_deepening() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.DFS_iterative_deepening();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_iddfs_time->setText(QString::number(cost_time));
	ui.LE_iddfs_path->setText(QString::number(paths.size()));
	ui.LE_iddfs_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_iddfs->setText(text);
	return true;
}

bool Eight_Puzzle_Problem::a_star_iterative_deepening() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.a_star_iterative_deepening();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_ida_time->setText(QString::number(cost_time));
	ui.LE_ida_path->setText(QString::number(paths.size()));
	ui.LE_ida_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_ida->setText(text);
	return true;
}

bool Eight_Puzzle_Problem::biBFS() {
	double cost_time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	bool tar = puzzle.biBFS();
	if (!tar) {
		QMessageBox::information(NULL, "提示", "该问题无解！", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		return false;
	}
	QueryPerformanceCounter(&nEndTime);
	cost_time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cost_time *= 1000;
	std::vector<Node> paths = puzzle.get_paths();
	ui.LE_bibfs_time->setText(QString::number(cost_time));
	ui.LE_bibfs_path->setText(QString::number(paths.size()));
	ui.LE_bibfs_node->setText(QString::number(puzzle.get_node_cnt()));
	QString text = "***********\n";
	for (int i = max(0, int(paths.size()) - 99); i < paths.size(); i++) {
		text += "PATH_";
		text += QString::number(i + 1);
		text += QString::fromStdString(paths[i].toString());
		text += "***********\n";
	}
	ui.TB_bibfs->setText(text);
	return true;
}
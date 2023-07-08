
#include "Duck_Store.h"
#include <QDebug>


Duck_Store::Duck_Store(QWidget* parent)
	: QMainWindow(parent)
{
	db = new DataBase();
	db->DB_init("root", "123456");
	MYSQL_RES* res = nullptr;
	std::pair<int, int> size;
	ui.setupUi(this);
	connect(ui.PB_Login, &QPushButton::clicked, [=]()mutable {
		QString user = ui.LE_Name->text();
		QString pwd = ui.LE_pwd->text();
		db->DB_query_user(res, size);
		int role = 0;
		for (int i = 0; i < size.first; i++) {
			auto row = mysql_fetch_row(res);
			if (user == row[1] && pwd == row[2]) {
				role = row[3][0] - '0';
				break;
			}
		}
		mysql_free_result(res);
		if (role) {
			db->setRole(role);
			this->hide();
			MainWindow* mw = new MainWindow(nullptr, db);
			mw->show();
		}
		else {
			QMessageBox::information(NULL, "提示", "登陆失败!", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		});
}

Duck_Store::~Duck_Store()
{
	db->~DataBase();
}

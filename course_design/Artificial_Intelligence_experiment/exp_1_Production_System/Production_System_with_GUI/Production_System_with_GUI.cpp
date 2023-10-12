#include "Production_System_with_GUI.h"

Production_System_with_GUI::Production_System_with_GUI(QWidget* parent)
	: QMainWindow(parent)
{
	db = new DataBase();
	ui.setupUi(this);
	if (!db->connect_check()) {
		return;
	}
	int hsz = 4;
	//init option:
	ui.TB_rules->verticalHeader()->hide();
	ui.TB_rules->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.TB_facts->verticalHeader()->hide();
	ui.TB_facts->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.TB_facts->setSelectionMode(QAbstractItemView::NoSelection);
	ui.TB_facts->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.TB_facts_selected->verticalHeader()->hide();
	ui.TB_facts_selected->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.TB_facts_selected->setSelectionMode(QAbstractItemView::NoSelection);
	ui.TB_facts_selected->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.TB_process->verticalHeader()->hide();
	ui.TB_process->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	//init GUI:
	init_ui();

	connect(ui.PB_start, &QPushButton::clicked, [=]()mutable {
		db->rules_set_init();
		std::vector<int> sel;
		for (auto [id, fact] : fact_selected) sel.emplace_back(id);
		db->facts_set_select(sel);
		std::pair<bool, std::vector<Rule>> ret = db->inference_engine();
		bool flag = ret.first;
		std::vector<Rule> process = ret.second;
		for (Rule& r : process) fact_selected.insert({ db->get_fact_id(r.result), r.result });

		ui.TB_facts_selected->clear();
		ui.TB_facts_selected->setRowCount(fact_selected.size() / hsz + bool(fact_selected.size() % hsz));
		ui.TB_facts_selected->setColumnCount(hsz << 1);
		ui.TB_facts_selected->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实"));
		int row = 0;
		for (auto it = fact_selected.begin(); it != fact_selected.end(); it++, row++) {
			int i = row / hsz, j = row % hsz;
			ui.TB_facts_selected->setItem(i, j * 2, new QTableWidgetItem(QString::number(it->first)));
			ui.TB_facts_selected->setItem(i, j * 2 + 1, new QTableWidgetItem(QString::fromStdString(it->second)));
		}

		ui.TB_process->setRowCount(process.size());
		ui.TB_process->setColumnCount(2);
		ui.TB_process->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("规则"));
		for (int row = 0; row < process.size(); row++) {
			ui.TB_process->setItem(row, 0, new QTableWidgetItem(QString::number(process[row].id)));
			ui.TB_process->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(process[row].toStr())));
		}
		if (!flag) {
			ui.LB_result->setText(QString::fromUtf8("推理失败!"));
			QMessageBox::information(NULL, "错误", "推理失败!", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		if (ret.second.size()) ui.LB_result->setText(QString::fromStdString(ret.second.back().result));
		else ui.LB_result->setText(QString::fromStdString(fact_selected.rbegin()->second));
		});

	connect(ui.TB_facts, &QTableWidget::itemDoubleClicked, this, [=](QTableWidgetItem* item)mutable {
		QString itemText = item->text();
		bool isNumber = false;
		int intValue = itemText.toInt(&isNumber);
		if (isNumber) fact_selected.insert({ intValue, db->get_id_fact(intValue) });
		else fact_selected.insert({ db->get_fact_id(itemText.toStdString()), itemText.toStdString() });

		ui.TB_facts_selected->clear();
		ui.TB_facts_selected->setRowCount(fact_selected.size() / hsz + bool(fact_selected.size() % hsz));
		ui.TB_facts_selected->setColumnCount(hsz << 1);
		ui.TB_facts_selected->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实"));
		int row = 0;
		for (auto it = fact_selected.begin(); it != fact_selected.end(); it++, row++) {
			int i = row / hsz, j = row % hsz;
			ui.TB_facts_selected->setItem(i, j * 2, new QTableWidgetItem(QString::number(it->first)));
			ui.TB_facts_selected->setItem(i, j * 2 + 1, new QTableWidgetItem(QString::fromStdString(it->second)));
		}
		});

	connect(ui.TB_facts_selected, &QTableWidget::itemDoubleClicked, this, [=](QTableWidgetItem* item)mutable {
		QString itemText = item->text();
		bool isNumber = false;
		int intValue = itemText.toInt(&isNumber);
		if (isNumber) {
			fact_selected.erase({ intValue, db->get_id_fact(intValue) });
		}
		else {
			fact_selected.erase({ db->get_fact_id(itemText.toStdString()), itemText.toStdString() });
		}

		ui.TB_facts_selected->clear();
		ui.TB_facts_selected->setRowCount(fact_selected.size() / hsz + bool(fact_selected.size() % hsz));
		ui.TB_facts_selected->setColumnCount(hsz << 1);
		ui.TB_facts_selected->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实"));
		int row = 0;
		for (auto it = fact_selected.begin(); it != fact_selected.end(); it++, row++) {
			int i = row / hsz, j = row % hsz;
			ui.TB_facts_selected->setItem(i, j * 2, new QTableWidgetItem(QString::number(it->first)));
			ui.TB_facts_selected->setItem(i, j * 2 + 1, new QTableWidgetItem(QString::fromStdString(it->second)));
		}
		});

	connect(ui.PB_add_rule, &QPushButton::clicked, [=]()mutable {
		DialogButtonBottom* dialog = new DialogButtonBottom(this);
		Rule new_rule;
		bool flag = false;
		connect(dialog, &DialogButtonBottom::data_ret, this, [&](Rule data, bool f) {
			new_rule = data;
			flag = f;
			});
		dialog->exec();
		if (new_rule.pre.size() == 0) return;
		std::cout << new_rule.toStr() << '\n';
		db->add_rule(new_rule, flag);
		init_ui();
		});

	connect(ui.PB_clear_process, &QPushButton::clicked, [=]()mutable {
		ui.TB_process->clear();
		ui.TB_process->setRowCount(0);
		ui.TB_process->setColumnCount(0);
		ui.LB_result->setText("");
		});

	connect(ui.PB_clear_fact_sel, &QPushButton::clicked, [=]()mutable {
		fact_selected.clear();
		ui.TB_facts_selected->clear();
		ui.TB_facts_selected->setRowCount(fact_selected.size() / hsz + bool(fact_selected.size() % hsz));
		ui.TB_facts_selected->setColumnCount(hsz << 1);
		ui.TB_facts_selected->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实"));
		int row = 0;
		for (auto it = fact_selected.begin(); it != fact_selected.end(); it++, row++) {
			int i = row / hsz, j = row % hsz;
			ui.TB_facts_selected->setItem(i, j * 2, new QTableWidgetItem(QString::number(it->first)));
			ui.TB_facts_selected->setItem(i, j * 2 + 1, new QTableWidgetItem(QString::fromStdString(it->second)));
		}
		});
}

Production_System_with_GUI::~Production_System_with_GUI() {
	delete db;
}

void Production_System_with_GUI::init_ui() {
	int hsz = 4;
	//rules:
	do {
		std::vector<Rule> rules = db->show_rules();
		ui.TB_rules->setRowCount(rules.size());
		ui.TB_rules->setColumnCount(2);
		ui.TB_rules->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("规则"));
		for (int row = 0; row < rules.size(); row++) {
			ui.TB_rules->setItem(row, 0, new QTableWidgetItem(QString::number(rules[row].id)));
			ui.TB_rules->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(rules[row].toStr())));
		}
	} while (false);
	//facts:
	do {
		std::vector < std::pair<int, std::string>> facts = db->show_facts();
		std::vector < std::pair<int, std::string>> results = db->show_results();
		ui.TB_facts->setRowCount((facts.size() + results.size()) / hsz + bool((facts.size() + results.size()) % hsz));
		ui.TB_facts->setColumnCount(hsz << 1);
		ui.TB_facts->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实")
			<< QString::fromUtf8("ID") << QString::fromUtf8("事实"));
		for (int row = 0; row < facts.size(); row++) {
			int i = row / hsz, j = row % hsz;
			ui.TB_facts->setItem(i, j * 2, new QTableWidgetItem(QString::number(facts[row].first)));
			ui.TB_facts->setItem(i, j * 2 + 1, new QTableWidgetItem(QString::fromStdString(facts[row].second)));
		}
		for (int row = 0; row < results.size(); row++) {
			int i = (row + facts.size()) / hsz, j = (row + facts.size()) % hsz;
			ui.TB_facts->setItem(i, j * 2, new QTableWidgetItem(QString::number(results[row].first + facts.size())));
			ui.TB_facts->setItem(i, j * 2 + 1, new QTableWidgetItem(QString::fromStdString(results[row].second)));
		}
	} while (false);
}

DialogButtonBottom::DialogButtonBottom(QWidget* parent) : QDialog(parent) {
	ui.setupUi(this);
	ui.TB_rule_added->verticalHeader()->hide();
	ui.TB_rule_added->horizontalHeader()->hide();
	ui.TB_rule_added->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.TB_rule_added->setColumnCount(2);
	ui.TB_rule_added->setRowCount(1);

	connect(ui.SB_num, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int value)mutable {
		ui.TB_rule_added->setRowCount(value + 1);
		for (int i = 0; i < value; i++) {
			ui.TB_rule_added->setItem(i, 0, new QTableWidgetItem(QString::fromUtf8("前件")));
			ui.TB_rule_added->setItem(i, 1, new QTableWidgetItem(QString::fromUtf8("")));
		}
		ui.TB_rule_added->setItem(value, 0, new QTableWidgetItem(QString::fromUtf8("结果")));
		ui.TB_rule_added->setItem(value, 1, new QTableWidgetItem(QString::fromUtf8("")));
		});

	connect(ui.PB_add, &QPushButton::clicked, [=]()mutable {
		Rule rule;
		int cnt = ui.SB_num->value();
		if (cnt == 0) return;

		bool pre_vaild = false;

		for (int i = 0; i < cnt; i++) if (!ui.TB_rule_added->item(i, 1)->text().isEmpty()) {
			pre_vaild = true;
			rule.pre.emplace_back(ui.TB_rule_added->item(i, 1)->text().toStdString());
		}
		if (ui.TB_rule_added->item(cnt, 1)->text().isEmpty()) return;
		rule.result = ui.TB_rule_added->item(cnt, 1)->text().toStdString();

		if (!pre_vaild) return;
		if (!ui.RB_and->isChecked() && !ui.RB_or->isChecked()) return;

		if (cnt == 1) {
			rule.logic = "Non";
		}
		else if (ui.RB_and->isChecked()) {
			rule.logic = "And";
		}
		else {
			rule.logic = "Or";
		}
		emit data_ret(rule, ui.CB_result->isChecked());
		this->accept();
		});
}

DialogButtonBottom::~DialogButtonBottom() {
}

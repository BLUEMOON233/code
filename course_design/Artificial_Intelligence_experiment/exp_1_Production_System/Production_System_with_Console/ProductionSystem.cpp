#include"ProductionSystem.h"

std::string Rule::toStr() {
	std::string ret = "";
	if (logic == "Non") {
		ret = pre_1 + " -> " + result;
	}
	else {
		ret += pre_1;
		if (pre_2 != "NULL") {
			ret += ' ' + logic + ' ' + pre_2;
		}
		if (pre_3 != "NULL") {
			ret += ' ' + logic + ' ' + pre_3;
		}
		ret += " -> " + result;
	}
	return ret;
}

DataBase::DataBase() {
	mysql = new MYSQL;
	mysql_init(mysql);
	mysql_set_character_set(mysql, "utf8mb4");

	if (mysql_real_connect(mysql, "localhost", username, password, db_name, port, NULL, 0) == NULL) {
		std::cout << "" << mysql_error(mysql) << '\n';
		std::cout << "连接失败\n";
		exit(-1);
	}
	else {
		std::cout << "数据库连接成功！\n\n";
	}
}

void DataBase::show_facts() {
	mysql_query(mysql, "SELECT * FROM facts");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	std::cout << "现有的事实库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		std::cout << row_data[0] << ' ' << row_data[1] << '\n';
	}
	std::cout << '\n';
}

void DataBase::show_facts_set() {
	mysql_query(mysql, "SELECT * FROM facts_set");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	std::cout << "推理机中事实库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		std::cout << row_data[0] << ' ' << row_data[1] << '\n';
	}
	std::cout << '\n';
}

void DataBase::show_rules() {
	mysql_query(mysql, "SELECT * FROM rules");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	int col = mysql_num_fields(res);
	std::vector<Rule> rules;
	std::cout << "现有的规则库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		rules.emplace_back(Rule{ row_data[1], row_data[2], row_data[3], row_data[4], row_data[5] });
	}
	for (auto rule : rules) {
		std::cout << rule.toStr() << '\n';
	}
	std::cout << '\n';
}

void DataBase::show_rules_set() {
	mysql_query(mysql, "SELECT * FROM rules_set");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	int col = mysql_num_fields(res);
	std::vector<Rule> rules;
	std::cout << "推理机中规则库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		rules.emplace_back(Rule{ row_data[1], row_data[2], row_data[3], row_data[4], row_data[5] });
	}
	for (auto rule : rules) {
		std::cout << rule.toStr() << '\n';
	}
	std::cout << '\n';
}


void DataBase::rules_set_init() {
	mysql_query(mysql, "DELETE FROM rules_set WHERE 1");
	mysql_query(mysql, "INSERT INTO rules_set SELECT* FROM rules");
}

void DataBase::facts_set_select(std::vector<int> sel) {
	mysql_query(mysql, "DELETE FROM facts_set WHERE 1");
	std::string query = "INSERT INTO facts_set SELECT fact FROM facts f WHERE f.Id in (";
	for (int i = 0; i < sel.size(); i++) {
		query += std::to_string(sel[i]);
		if (i != sel.size() - 1) query += ',';
	}
	query += ')';
	mysql_query(mysql, query.c_str());
}
#include"ProductionSystem.h"

std::string Rule::toStr() {
	std::string ret = "";
	if (logic == "Non") {
		ret = pre[0] + " -> " + result;
	}
	else {
		ret += pre[0];
		for (int i = 1; i < pre.size(); i++) if (pre[i] != "NULL") {
			ret += ' ' + logic + ' ' + pre[i];
		}
		ret += " -> " + result;
	}
	return ret;
}

Rule::Rule(MYSQL* mysql, MYSQL_ROW data) {
	id = atoi(data[0]);
	logic = data[1];
	for (int i = 2; i <= 4; i++) pre.emplace_back(data[i]);
	if (std::string(data[5]).substr(0, 5) != "LINK_") {
		result = data[5];
		return;
	}

	std::string query = "SELECT * FROM rules_linklist WHERE Id = ";
	while (std::string(data[5]).substr(0, 5) == "LINK_") {
		std::string ptr = std::string(data[5]).substr(5, strlen(data[5]) - 5).c_str();
		mysql_query(mysql, (query + ptr).c_str());
		MYSQL_RES* res = mysql_store_result(mysql);
		data = mysql_fetch_row(res);
		for (int i = 2; i <= 4; i++) pre.emplace_back(data[i]);
		if (std::string(data[5]).substr(0, 5) != "LINK_") {
			result = data[5];
			return;
		}
	}
}

bool Rule::check(MYSQL* mysql) {
	if (logic != "Or") {
		std::string query = "SELECT * FROM facts_set WHERE fact LIKE ";
		for (int i = 0; i < pre.size(); i++) if (pre[i] != "NULL") {
			mysql_query(mysql, (query + '\"' + pre[i] + '\"').c_str());
			MYSQL_RES* res = mysql_store_result(mysql);
			if (mysql_num_rows(res) == 0) return false;
		}
		return true;
	}
	else {
		std::string query = "SELECT * FROM facts_set WHERE fact LIKE ";
		for (int i = 0; i < pre.size(); i++) if (pre[i] != "NULL") {
			mysql_query(mysql, (query + '\"' + pre[i] + '\"').c_str());
			MYSQL_RES* res = mysql_store_result(mysql);
			if (mysql_num_rows(res) != 0) return true;
		}
		return false;
	}
}

DataBase::DataBase() {
	mysql = new MYSQL;
	mysql_init(mysql);
	mysql_set_character_set(mysql, "utf8mb4");

	if (mysql_real_connect(mysql, "localhost", username, password, db_name, port, NULL, 0) == NULL) {
		std::cout << "" << mysql_error(mysql) << '\n';
		std::cout << "连接失败\n";
		connected = false;
	}
	else {
		std::cout << "数据库连接成功！\n\n";
		connected = true;
	}
}

std::vector<std::pair<int, std::string>> DataBase::show_facts() {
	std::vector<std::pair<int, std::string>> ret;
	mysql_query(mysql, "SELECT * FROM facts");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	std::cout << "现有的事实库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		ret.emplace_back(atoi(row_data[0]), row_data[1]);
		std::cout << row_data[0] << ' ' << row_data[1] << '\n';
	}
	std::cout << '\n';
	return ret;
}

std::vector<std::string> DataBase::show_facts_set() {
	std::vector<std::string> ret;
	mysql_query(mysql, "SELECT * FROM facts_set");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	std::cout << "推理机中事实库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		std::cout << row_data[0] << '\n';
		ret.emplace_back(row_data[0]);
	}
	std::cout << '\n';
	return ret;
}

std::vector<Rule> DataBase::show_rules() {
	mysql_query(mysql, "SELECT * FROM rules");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	int col = mysql_num_fields(res);
	std::vector<Rule> rules;
	std::cout << "现有的规则库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		Rule new_rule(mysql, row_data);
		rules.emplace_back(new_rule);
	}
	for (auto& rule : rules) {
		std::cout << rule.toStr() << '\n';
	}
	std::cout << '\n';
	return rules;
}

std::vector<Rule> DataBase::show_rules_set() {
	mysql_query(mysql, "SELECT * FROM rules_set");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	int col = mysql_num_fields(res);
	std::vector<Rule> rules;
	std::cout << "推理机中规则库内容:\n";
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		Rule new_rule(mysql, row_data);
		rules.emplace_back(new_rule);
	}
	for (auto& rule : rules) {
		std::cout << rule.toStr() << '\n';
	}
	std::cout << '\n';
	return rules;
}

std::vector<std::pair<int, std::string>> DataBase::show_results() {
	std::vector<std::pair<int, std::string>> ret;
	mysql_query(mysql, "SELECT * FROM results");
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		ret.emplace_back(atoi(row_data[0]), row_data[1]);
	}
	return ret;
}

int DataBase::get_fact_id(std::string str) {
	mysql_query(mysql, ("SELECT id FROM facts WHERE fact LIKE \"" + str + '\"').c_str());
	MYSQL_RES* res = mysql_store_result(mysql);
	MYSQL_ROW row_data = mysql_fetch_row(res);
	int sz = 0;
	if (row_data == nullptr) {
		mysql_query(mysql, "SELECT MAX(id) FROM facts");
		res = mysql_store_result(mysql);
		row_data = mysql_fetch_row(res);
		sz = atoi(row_data[0]);
		mysql_query(mysql, ("SELECT id FROM results WHERE result LIKE \"" + str + '\"').c_str());
		res = mysql_store_result(mysql);
		row_data = mysql_fetch_row(res);
	}
	return atoi(row_data[0]) + sz;
}

std::string DataBase::get_id_fact(int id) {
	mysql_query(mysql, ("SELECT fact FROM facts WHERE id = " + std::to_string(id)).c_str());
	MYSQL_RES* res = mysql_store_result(mysql);
	MYSQL_ROW row_data = mysql_fetch_row(res);
	if (row_data == nullptr) {
		mysql_query(mysql, "SELECT MAX(id) FROM facts");
		res = mysql_store_result(mysql);
		row_data = mysql_fetch_row(res);
		int sz = atoi(row_data[0]);
		mysql_query(mysql, ("SELECT result FROM results WHERE id LIKE \"" + std::to_string(id - sz) + '\"').c_str());
		res = mysql_store_result(mysql);
		row_data = mysql_fetch_row(res);
	}
	return row_data[0];
}

void DataBase::rules_set_init() {
	mysql_query(mysql, "DELETE FROM rules_set WHERE 1");
	mysql_query(mysql, "INSERT INTO rules_set SELECT* FROM rules");
}

void DataBase::facts_set_select(std::vector<int> sel) {
	std::string str = "SELECT MAX(id) FROM facts WHERE 1";
	mysql_query(mysql, str.c_str());
	MYSQL_RES* res = mysql_store_result(mysql);
	int id_max = atoi(mysql_fetch_row(res)[0]);

	mysql_query(mysql, "DELETE FROM facts_set WHERE 1");
	std::string query = "INSERT INTO facts_set SELECT fact FROM facts f WHERE f.Id in (";
	std::string query_result = "INSERT INTO facts_set SELECT result FROM results f WHERE f.Id in (";
	bool f1 = false, f2 = false;
	for (int i = 0; i < sel.size(); i++) if (sel[i] <= id_max) {
		if (f1) query += ',';
		query += std::to_string(sel[i]);
		f1 = true;
	}
	else {
		if (f2) query_result += ',';
		query_result += std::to_string(sel[i] - id_max);
		f2 = true;
	}
	query += ')';
	query_result += ')';
	mysql_query(mysql, query.c_str());
	mysql_query(mysql, query_result.c_str());
}


Rule DataBase::select_rule() {
	Rule rule_selected;
	//AND || Non part:
	std::string And_query =
		R"(SELECT DISTINCT rs.* 
		FROM rules_set rs
		INNER JOIN facts_set fs1 ON(fs1.fact = rs.pre_1 OR rs.pre_1 LIKE "NULL")
		INNER JOIN facts_set fs2 ON(fs2.fact = rs.pre_2 OR rs.pre_2 LIKE "NULL")
		INNER JOIN facts_set fs3 ON(fs3.fact = rs.pre_3 OR rs.pre_3 LIKE "NULL")
		WHERE rs.logic = 'And' OR rs.logic = 'Non')";

	mysql_query(mysql, And_query.c_str());
	MYSQL_RES* res = mysql_store_result(mysql);
	int row = mysql_num_rows(res);

	//std::vector<Rule> rules;
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		Rule new_rule(mysql, row_data);

		//rules.emplace_back(new_rule);
		if (new_rule.pre.size() > 3) {
			if (!new_rule.check(mysql)) continue;
		}
		if (new_rule.pre.size() > rule_selected.pre.size()) {
			rule_selected = new_rule;
		}
	}
	if (rule_selected.id) return rule_selected;

	std::string Or_query =
		R"(SELECT rs.*
		FROM rules_set rs
		INNER JOIN facts_set fs ON (
		fs.fact = rs.pre_1 OR
		fs.fact = rs.pre_2 OR
		fs.fact = rs.pre_3
		)
		WHERE rs.logic = "Or")";
	mysql_query(mysql, And_query.c_str());
	res = mysql_store_result(mysql);
	row = mysql_num_rows(res);
	for (int i = 0; i < row; i++) {
		MYSQL_ROW row_data = mysql_fetch_row(res);
		Rule new_rule(mysql, row_data);
		//rules.emplace_back(new_rule);
		if (new_rule.pre.size() > 3) {
			if (!new_rule.check(mysql)) continue;
		}
		if (new_rule.pre.size() > rule_selected.pre.size()) {
			rule_selected = new_rule;
		}
	}
	return rule_selected;
}

void DataBase::delete_rule(Rule rule_selected) {
	std::string query = "DELETE FROM rules_set WHERE id = " + std::to_string(rule_selected.id);
	mysql_query(mysql, query.c_str());
	query = "DELETE FROM rules_set WHERE result = \"" + rule_selected.result + '\"';
	mysql_query(mysql, query.c_str());
}

void DataBase::add_rule(Rule rule, bool flag) {
	std::string get = "SELECT MAX(id) FROM results WHERE 1";
	mysql_query(mysql, get.c_str());
	MYSQL_RES* res = mysql_store_result(mysql);
	int id_new = atoi(mysql_fetch_row(res)[0]) + 1;
	std::string check = "SELECT * FROM results WHERE result LIKE \"" + rule.result + '\"';
	mysql_query(mysql, check.c_str());
	res = mysql_store_result(mysql);
	if (flag && mysql_num_rows(res) == 0) {
		std::string ins = "INSERT INTO results VALUES (" + std::to_string(id_new) + ", \"" + rule.result + "\")";
		std::cout << ins << '\n';
		mysql_query(mysql, ins.c_str());
	}
	get = "SELECT MAX(id) FROM facts WHERE 1";
	mysql_query(mysql, get.c_str());
	res = mysql_store_result(mysql);
	id_new = atoi(mysql_fetch_row(res)[0]) + 1;
	check = "SELECT * FROM facts WHERE fact LIKE \"" + rule.result + '\"';
	mysql_query(mysql, check.c_str());
	res = mysql_store_result(mysql);
	if (!flag && mysql_num_rows(res) == 0) {
		std::string ins = "INSERT INTO facts VALUES (" + std::to_string(id_new) + ", \"" + rule.result + "\")";
		std::cout << ins << '\n';
		mysql_query(mysql, ins.c_str());
	}

	for (int i = 0; i < rule.pre.size(); i++) {
		std::string get = "SELECT MAX(id) FROM facts WHERE 1";
		mysql_query(mysql, get.c_str());
		res = mysql_store_result(mysql);
		id_new = atoi(mysql_fetch_row(res)[0]) + 1;
		std::string check = "SELECT * FROM facts WHERE fact LIKE \"" + rule.pre[i] + '\"';
		mysql_query(mysql, check.c_str());
		res = mysql_store_result(mysql);
		if (mysql_num_rows(res) == 0) {
			std::string ins = "INSERT INTO facts VALUES (" + std::to_string(id_new) + ", \"" + rule.pre[i] + "\")";
			std::cout << ins << '\n';
			mysql_query(mysql, ins.c_str());
		}
	}

	std::string query = "SELECT MAX(id) FROM rules WHERE 1";
	mysql_query(mysql, query.c_str());
	res = mysql_store_result(mysql);
	id_new = atoi(mysql_fetch_row(res)[0]) + 1;
	rule.id = id_new;
	query = "INSERT INTO rules VALUES (" + std::to_string(id_new) + ", \"" + rule.logic + '\"';
	for (int i = 0; i < min(3, rule.pre.size()); i++) {
		query += ", \"" + rule.pre[i] + '\"';
	}
	for (int i = 1; i <= 3 - int(rule.pre.size()); i++) {
		query += ", \"NULL\"";
	}

	if (rule.pre.size() <= 3) {
		query += ", \"" + rule.result + "\")";
		mysql_query(mysql, query.c_str());
		return;
	}
	std::string str = "SELECT MAX(id) FROM rules_linklist WHERE 1";
	mysql_query(mysql, str.c_str());
	res = mysql_store_result(mysql);
	id_new = atoi(mysql_fetch_row(res)[0]) + 1;
	query += ", \"LINK_" + std::to_string(id_new) + "\")";
	mysql_query(mysql, query.c_str());

	int pos = 3;
	while (pos < rule.pre.size()) {
		mysql_query(mysql, str.c_str());
		res = mysql_store_result(mysql);
		id_new = atoi(mysql_fetch_row(res)[0]) + 1;
		query = "INSERT INTO rules_linklist VALUES (" + std::to_string(id_new) + ", \"" + rule.logic + '\"';
		for (int i = pos; i < min(pos + 3, rule.pre.size()); i++) {
			query += ", \"" + rule.pre[i] + '\"';
		}
		for (int i = 1; i <= pos + 3 - int(rule.pre.size()); i++) {
			query += ", \"NULL\"";
		}
		pos += 3;
		if (pos >= rule.pre.size()) {
			query += ", \"" + rule.result + "\")";
			mysql_query(mysql, query.c_str());
			return;
		}
		query += ", \"LINK_" + std::to_string(id_new + 1) + "\")";
		mysql_query(mysql, query.c_str());
	}
}


std::pair<bool, std::vector<Rule>> DataBase::inference_engine() {
	std::vector<Rule> rules_list;
	while (true) {
		std::string check = "SELECT * FROM results, facts_set WHERE result LIKE facts_set.fact";
		mysql_query(mysql, check.c_str());
		MYSQL_RES* res = mysql_store_result(mysql);
		if (mysql_num_rows(res) != 0) return { true, rules_list };
		std::cout << "YES\n";
		Rule rule_selected = select_rule();
		if (rule_selected.id == 0) {
			return { false, rules_list };
		}
		std::cout << rule_selected.toStr() << '\n';

		std::string ins = "INSERT INTO facts_set VALUES (\"" + rule_selected.result + "\")";
		mysql_query(mysql, ins.c_str());

		rules_list.emplace_back(rule_selected);
		delete_rule(rule_selected);
	}
	return { true, rules_list };
}

bool DataBase::connect_check() {
	return connected;
}
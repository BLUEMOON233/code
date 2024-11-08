#pragma once
#include<iostream>
#include<mysql.h>
#include<string>
#include<vector>


struct Rule {
	int id = 0;
	std::string logic = "Non";
	std::vector<std::string> pre;
	std::string result = "NULL";

	Rule() {}
	Rule(MYSQL* mysql, MYSQL_ROW data);
	std::string toStr();
	bool check(MYSQL* mysql);
};

class DataBase {
public:
	DataBase();
	void show_facts();
	void show_rules();
	std::vector<std::string> show_facts_set();
	std::vector<Rule> show_rules_set();
	void rules_set_init();
	void facts_set_select(std::vector<int> sel);
	Rule select_rule();
	void delete_rule(Rule rule_selected);
	bool inference_engine();

private:
	MYSQL* mysql;
	const char* username = "root";
	const char* password = "123456";
	const char* db_name = "Production_System_DB";
	const int port = 3306;
};



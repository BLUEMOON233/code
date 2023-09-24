#pragma once
#include<iostream>
#include<mysql.h>
#include<string>
#include<vector>
#include<set>


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
	std::vector<std::pair<int, std::string>> show_facts();
	std::vector<Rule> show_rules();
	std::vector<std::string> show_facts_set();
	std::vector<Rule> show_rules_set();
	std::vector<std::pair<int, std::string>> show_results();
	int get_fact_id(std::string str);
	std::string get_id_fact(int id);
	void rules_set_init();
	void facts_set_select(std::vector<int> sel);
	Rule select_rule();
	void delete_rule(Rule rule_selected);
	void add_rule(Rule rule);
	std::pair<bool, std::vector<Rule>> inference_engine();

private:
	MYSQL* mysql;
	const char* username = "root";
	const char* password = "123456";
	const char* db_name = "Production_System_DB";
	const int port = 3306;
};

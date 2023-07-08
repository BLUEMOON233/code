#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <WinSock.h> 
#include <Windows.h>
#include <mysql.h>


class DataBase {
public:
	DataBase();
	~DataBase();
	void setRole(int user_role);
	int getRole();
	bool DB_init(std::string DataBase_UserName, std::string DataBase_Password);
	bool DB_query(std::string str, MYSQL_RES*& res, std::pair<int, int>& size);
	//对于商品关系模式的操作：
	bool DB_insert_merchandise(int ID, std::string Type, std::string Name, double Price, double Discount = 1.0);
	bool DB_delete_merchandise(int ID);
	bool DB_modify_merchandise(int ID, std::string Type, std::string Name, double Price, int Number, double Discount);
	bool DB_query_merchandise(MYSQL_RES*& res, std::pair<int, int>& size);
	//对于供应商关系模式的操作：
	bool DB_insert_supplier(int ID, std::string Name, std::string Address, std::string Information);
	bool DB_delete_supplier(int ID);
	bool DB_modify_supplier(int ID, std::string Name, std::string Address, std::string Information);
	bool DB_query_supplier(MYSQL_RES*& res, std::pair<int, int>& size);
	//对于购入关系模式的操作：
	bool DB_insert_purchase(int ID, double Price, int Number, std::string Date, int Supplier_ID, int Merchandise_ID);
	bool DB_modify_purchase(int ID, double Price, int Number, std::string Date, int Supplier_ID, int Merchandise_ID);
	bool DB_delete_purchase(int ID);
	bool DB_query_purchase(MYSQL_RES*& res, std::pair<int, int>& size);
	//对于售货员关系模式的操作：
	bool DB_insert_staff(int ID, std::string Name, std::string Sex, int Age, double Salary, std::string Information);
	bool DB_delete_staff(int ID);
	bool DB_modify_staff(int ID, std::string Name, std::string Sex, int Age, double Salary, std::string Information);
	bool DB_query_staff(MYSQL_RES*& res, std::pair<int, int>& size);
	//对于售出关系模式的操作：
	bool DB_insert_sell(int ID, double Price, int Number, std::string Date, int Staff_ID, int Merchandise_ID);
	bool DB_modify_sell(int ID, double Price, int Number, std::string Date, int Staff_ID, int Merchandise_ID);
	bool DB_delete_sell(int ID);
	bool DB_query_sell(MYSQL_RES*& res, std::pair<int, int>& size);
	//对于用户关系模式的操作：
	bool DB_query_user(MYSQL_RES*& res, std::pair<int, int>& size);
private:
	MYSQL mysql;
	const std::string DataBase_Host = "localhost";
	const std::string DataBase_Name = "duck_store";
	unsigned int DataBase_Port = 3306;
	int role = 0;
};
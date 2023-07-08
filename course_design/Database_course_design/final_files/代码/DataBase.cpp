#include "DataBase.h"


DataBase::DataBase() {}

DataBase::~DataBase() {
	mysql_close(&mysql);
	std::cout << "Database Release Successfully!!!\n";
}

void DataBase::setRole(int user_role) {
	role = user_role;
}

int DataBase::getRole() {
	return role;
}

bool DataBase::DB_init(std::string DataBase_UserName, std::string DataBase_Password) {
	mysql_init(&mysql);
	std::cout << "Connected...\n";
	if (!(mysql_real_connect(&mysql, DataBase_Host.c_str(), DataBase_UserName.c_str(), DataBase_Password.c_str(), DataBase_Name.c_str(), DataBase_Port, NULL, 3306))) {
		std::cout << "Connecting Error To Database:" << mysql_error(&mysql) << '\n';
		return false;
	}
	std::cout << "Connected Successfully!\n";
	return true;
}

bool DataBase::DB_query(std::string str, MYSQL_RES*& res, std::pair<int, int>& size) {
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	res = mysql_store_result(&mysql);
	size = { mysql_num_rows(res), mysql_num_fields(res) };
	return true;
}

bool DataBase::DB_insert_merchandise(int ID, std::string Type, std::string Name, double Price, double Discount) {
	std::string str = "INSERT INTO merchandise VALUES(" + std::to_string(ID) + ",\'" + Type + "\',\'" + Name + "\', 0, " + std::to_string(Price) + ", " + std::to_string(Discount) + ");";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_delete_merchandise(int ID) {
	std::string str = "DELETE FROM merchandise WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_modify_merchandise(int ID, std::string Type, std::string Name, double Price, int Number, double Discount) {
	std::string str = "UPDATE merchandise SET Type = \'" + Type + "\', Name = \'" + Name + "\', Number = " + std::to_string(Number) + ", Price = " + std::to_string(Price) +
		", Discount = " + std::to_string(Discount) + "WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_query_merchandise(MYSQL_RES*& res, std::pair<int, int>& size) {
	std::string str = "SELECT * FROM merchandise;";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	res = mysql_store_result(&mysql);
	size = { mysql_num_rows(res), mysql_num_fields(res) };

	return true;
}

bool DataBase::DB_insert_supplier(int ID, std::string Name, std::string Address, std::string Information) {
	std::string str = "INSERT INTO supplier VALUES(" + std::to_string(ID) + ", \'" + Name + "\', \'" + Address + "\', \'" + Information + "\');";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_delete_supplier(int ID) {
	std::string str = "DELETE FROM supplier WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_modify_supplier(int ID, std::string Name, std::string Address, std::string Information) {
	std::string str = "UPDATE supplier SET Name = \'" + Name + "\', Address = \'" + Address + "\', Information = \'" + Information + "\' WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_query_supplier(MYSQL_RES*& res, std::pair<int, int>& size) {
	std::string str = "SELECT * FROM supplier;";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	res = mysql_store_result(&mysql);
	size = { mysql_num_rows(res), mysql_num_fields(res) };
	return true;
}

bool DataBase::DB_insert_purchase(int ID, double Price, int Number, std::string Date, int Supplier_ID, int Merchandise_ID) {
	std::string str = "INSERT INTO purchase VALUES(" + std::to_string(ID) + ", " + std::to_string(Price) + ", " + std::to_string(Number) + ", \'" + Date + "\', "
		+ std::to_string(Supplier_ID) + ", " + std::to_string(Merchandise_ID) + ");";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_modify_purchase(int ID, double Price, int Number, std::string Date, int Supplier_ID, int Merchandise_ID) {
	std::string str = "UPDATE purchase SET Price = " + std::to_string(Price) + ", Number = " + std::to_string(Number) + ", Date = \'" + Date + "\', Supplier_ID = "
		+ std::to_string(Supplier_ID) + ", Merchandise_ID = " + std::to_string(Merchandise_ID) + " WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_query_purchase(MYSQL_RES*& res, std::pair<int, int>& size) {
	std::string str = "SELECT * FROM purchase;";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	res = mysql_store_result(&mysql);
	size = { mysql_num_rows(res), mysql_num_fields(res) };
	return true;
}

bool DataBase::DB_delete_purchase(int ID) {
	std::string str = "DELETE FROM purchase WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_insert_staff(int ID, std::string Name, std::string Sex, int Age, double Salary, std::string Information) {
	std::string str = "INSERT INTO staff VALUES(" + std::to_string(ID) + ", \'" + Name + "\', \'" + Sex + "\', " + std::to_string(Age) + ", " + std::to_string(Salary)
		+ ", \'" + Information + "\');";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_delete_staff(int ID) {
	std::string str = "DELETE FROM staff WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_modify_staff(int ID, std::string Name, std::string Sex, int Age, double Salary, std::string Information) {
	std::string str = "UPDATE staff SET ID = " + std::to_string(ID) + ", Name = \'" + Name + "\', Sex = \'" + Sex + "\', Age = " + std::to_string(Age) + ", Salary = " +
		std::to_string(Salary) + ", Information = \'" + Information + "\' WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_query_staff(MYSQL_RES*& res, std::pair<int, int>& size) {
	std::string str = "SELECT * FROM staff;";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	res = mysql_store_result(&mysql);
	size = { mysql_num_rows(res), mysql_num_fields(res) };
	return true;
}

bool DataBase::DB_insert_sell(int ID, double Price, int Number, std::string Date, int Staff_ID, int Merchandise_ID) {
	std::string str = "INSERT INTO sell VALUES(" + std::to_string(ID) + ", " + std::to_string(Price) + ", " + std::to_string(Number) + ", \'" + Date + "\', " +
		std::to_string(Staff_ID) + ", " + std::to_string(Merchandise_ID) + ");";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_modify_sell(int ID, double Price, int Number, std::string Date, int Staff_ID, int Merchandise_ID) {
	std::string str = "UPDATE sell SET Price = " + std::to_string(Price) + ", Number = " + std::to_string(Number) + ", Date = \'" + Date + "\', Staff_ID = " +
		std::to_string(Staff_ID) + ", Merchandise_ID = " + std::to_string(Merchandise_ID) + " WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_delete_sell(int ID) {
	std::string str = "DELETE FROM sell WHERE ID = " + std::to_string(ID) + ";";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	return true;
}

bool DataBase::DB_query_sell(MYSQL_RES*& res, std::pair<int, int>& size) {
	std::string str = "SELECT * FROM sell;";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	res = mysql_store_result(&mysql);
	size = { mysql_num_rows(res), mysql_num_fields(res) };
	return true;
}

bool DataBase::DB_query_user(MYSQL_RES*& res, std::pair<int, int>& size) {
	std::string str = "SELECT * FROM user;";
	if (mysql_query(&mysql, str.c_str())) {
		std::cout << "Failed!\n";
		return false;
	}
	res = mysql_store_result(&mysql);
	size = { mysql_num_rows(res), mysql_num_fields(res) };
	return true;
}

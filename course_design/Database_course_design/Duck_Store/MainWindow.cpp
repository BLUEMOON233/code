#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent, DataBase* db)
	: QMainWindow(parent), db(db)
{
	MYSQL_RES* res = nullptr;
	std::pair<int, int> size;

	ui.setupUi(this);
	this->setFixedSize(1500, 1000);
	ui.stackedWidget->setCurrentIndex(0);
	ui.TB_Mer->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.TB_Inventory->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.TB_Purchase->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.TB_Supplier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.TB_Sell->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.TB_Staff->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.TB_Income->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.TB_Income->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	connect(ui.PB_MainPage, &QPushButton::clicked, [=]()mutable {
		ui.stackedWidget->setCurrentIndex(0);
		});
	connect(ui.PB_Merchandise, &QPushButton::clicked, [=]()mutable {
		ui.stackedWidget->setCurrentIndex(1);
		});
	connect(ui.PB_Inventory, &QPushButton::clicked, [=]()mutable {
		ui.stackedWidget->setCurrentIndex(2);
		});
	connect(ui.PB_Purchase, &QPushButton::clicked, [=]()mutable {
		ui.stackedWidget->setCurrentIndex(3);
		});
	connect(ui.PB_Sell, &QPushButton::clicked, [=]()mutable {
		ui.stackedWidget->setCurrentIndex(4);
		});
	connect(ui.PB_Supplier, &QPushButton::clicked, [=]()mutable {
		ui.stackedWidget->setCurrentIndex(5);
		});
	connect(ui.PB_Staff, &QPushButton::clicked, [=]()mutable {
		if (db->getRole() == 1)
			ui.stackedWidget->setCurrentIndex(6);
		else if (db->getRole() == 2)
			ui.stackedWidget->setCurrentIndex(7);
		});
	connect(ui.PB_Income, &QPushButton::clicked, [=]()mutable {
		ui.stackedWidget->setCurrentIndex(8);
		});

	//商品页面：
	connect(ui.PB_Merchandise, &QPushButton::clicked, [=]()mutable {
		db->DB_query_merchandise(res, size);
		ui.TB_Mer->setRowCount(size.first);
		ui.TB_Mer->setColumnCount(size.second);
		ui.TB_Mer->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("价格") << QString::fromUtf8("数目") << QString::fromUtf8("折扣"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Mer->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Add_Mer, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		db->DB_query("SELECT MAX(ID) FROM merchandise;", res, size);
		QString sID = mysql_fetch_row(res)[0];
		mysql_free_result(res);
		QString sType = QInputDialog::getText(this, "类型", "<html style = \"font-size:12pt;\">请输入类型</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sName = QInputDialog::getText(this, "名称", "<html style = \"font-size:12pt;\">请输入名称</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sPrice = QInputDialog::getText(this, "定价", "<html style = \"font-size:12pt;\">请输入定价</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sDiscount = QInputDialog::getText(this, "折扣", "<html style = \"font-size:12pt;\">请输入折扣</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		if (!db->DB_insert_merchandise(sID.toInt() + 1, sType.toStdString(), sName.toStdString(), sPrice.toDouble(), sDiscount.toDouble())) {
			QMessageBox::information(NULL, "提示", "插入失败!", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		db->DB_query_merchandise(res, size);
		ui.TB_Mer->setRowCount(size.first);
		ui.TB_Mer->setColumnCount(size.second);
		ui.TB_Mer->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("价格") << QString::fromUtf8("数目") << QString::fromUtf8("折扣"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Mer->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Mdf_Mer, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		QString sID = QInputDialog::getText(this, "ID", "<html style = \"font-size:12pt;\">需要修改的商品ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sType = QInputDialog::getText(this, "类型", "<html style = \"font-size:12pt;\">请输入修改后类型</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sName = QInputDialog::getText(this, "名称", "<html style = \"font-size:12pt;\">请输入修改后名称</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sNumber = QInputDialog::getText(this, "数量", "<html style = \"font-size:12pt;\">请输入修改后数量</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sPrice = QInputDialog::getText(this, "定价", "<html style = \"font-size:12pt;\">请输入修改后定价</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sDiscount = QInputDialog::getText(this, "折扣", "<html style = \"font-size:12pt;\">请输入修改后折扣</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		db->DB_modify_merchandise(sID.toInt(), sType.toStdString(), sName.toStdString(), sNumber.toInt(), sPrice.toDouble(), sDiscount.toDouble());
		db->DB_query_merchandise(res, size);
		ui.TB_Mer->setRowCount(size.first);
		ui.TB_Mer->setColumnCount(size.second);
		ui.TB_Mer->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("价格") << QString::fromUtf8("数目") << QString::fromUtf8("折扣"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Mer->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Que_Mer, &QPushButton::clicked, [=]()mutable {
		QString str = ui.LE_Que_Mer->text();
		if (str.isEmpty()) db->DB_query_merchandise(res, size);
		else db->DB_query("SELECT * FROM merchandise WHERE Name = \'" + str.toStdString() + "\';", res, size);
		ui.TB_Mer->setRowCount(size.first);
		ui.TB_Mer->setColumnCount(size.second);
		ui.TB_Mer->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("价格") << QString::fromUtf8("数目") << QString::fromUtf8("折扣"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Mer->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Inventory, &QPushButton::clicked, [=]()mutable {
		db->DB_query("SELECT * FROM inventory;", res, size);
		ui.TB_Inventory->setRowCount(size.first);
		ui.TB_Inventory->setColumnCount(size.second);
		ui.TB_Inventory->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("数目"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Inventory->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Inv_ID, &QPushButton::clicked, [=]()mutable {
		db->DB_query("SELECT * FROM inventory ORDER BY ID;", res, size);
		ui.TB_Inventory->setRowCount(size.first);
		ui.TB_Inventory->setColumnCount(size.second);
		ui.TB_Inventory->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("数目"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Inventory->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Inv_Type, &QPushButton::clicked, [=]()mutable {
		db->DB_query("SELECT * FROM inventory ORDER BY Type;", res, size);
		ui.TB_Inventory->setRowCount(size.first);
		ui.TB_Inventory->setColumnCount(size.second);
		ui.TB_Inventory->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("数目"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Inventory->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Inv_Name, &QPushButton::clicked, [=]()mutable {
		db->DB_query("SELECT * FROM inventory ORDER BY Name;", res, size);
		ui.TB_Inventory->setRowCount(size.first);
		ui.TB_Inventory->setColumnCount(size.second);
		ui.TB_Inventory->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("数目"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Inventory->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Inv_Inv, &QPushButton::clicked, [=]()mutable {
		db->DB_query("SELECT * FROM inventory ORDER BY Number;", res, size);
		ui.TB_Inventory->setRowCount(size.first);
		ui.TB_Inventory->setColumnCount(size.second);
		ui.TB_Inventory->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("类型") << QString::fromUtf8("名称") << QString::fromUtf8("数目"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Inventory->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Inv_Output, &QPushButton::clicked, [=]()mutable {
		QString filepath = QFileDialog::getSaveFileName(this, tr("Save"), ".", tr(" (*.xlsx)"));
		if (!filepath.isEmpty()) {
			QAxObject* excel = new QAxObject(this);
			excel->setControl("Excel.Application");
			excel->dynamicCall("SetVisible (bool Visible)", "false");
			excel->setProperty("DisplayAlerts", false);
			QAxObject* workbooks = excel->querySubObject("WorkBooks");
			workbooks->dynamicCall("Add");
			QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
			QAxObject* worksheets = workbook->querySubObject("Sheets");
			QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);
			int rows = ui.TB_Inventory->rowCount();
			int cols = ui.TB_Inventory->columnCount();
			for (int i = 1; i <= cols; i++) {
				QAxObject* Range = worksheet->querySubObject("Cells(int,int)", 1, i);
				Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->horizontalHeaderItem(i - 1)->text()));
				for (int j = 2; j < rows + 2; j++) {
					QAxObject* Range = worksheet->querySubObject("Cells(int,int)", j, i);
					if (ui.TB_Inventory->item(j - 2, i - 1) != NULL) Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->item(j - 2, i - 1)->text()));
					else Range->dynamicCall("SetValue(const QString &)", QVariant(""));
				}
			}
			workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));
			workbook->dynamicCall("Close()");
			excel->dynamicCall("Quit()");
			delete excel;
		}
		});

	connect(ui.PB_Purchase, &QPushButton::clicked, [=]()mutable {
		db->DB_query_purchase(res, size);
		ui.TB_Purchase->setRowCount(size.first);
		ui.TB_Purchase->setColumnCount(size.second);
		ui.TB_Purchase->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("进价") << QString::fromUtf8("数量") << QString::fromUtf8("日期") << QString::fromUtf8("供货商ID") << QString::fromUtf8("商品ID"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Purchase->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Add_Purchase, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		db->DB_query("SELECT MAX(ID) FROM purchase;", res, size);
		QString sID = mysql_fetch_row(res)[0];
		mysql_free_result(res);
		QString sPrice = QInputDialog::getText(this, "进价", "<html style = \"font-size:12pt;\">请输入进价</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sNumber = QInputDialog::getText(this, "数量", "<html style = \"font-size:12pt;\">请输入数量</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sDate = QInputDialog::getText(this, "日期", "<html style = \"font-size:12pt;\">请输入日期</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sSupplier = QInputDialog::getText(this, "供应商ID", "<html style = \"font-size:12pt;\">请输入供应商ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sMerchandise = QInputDialog::getText(this, "商品ID", "<html style = \"font-size:12pt;\">请输入商品ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		if (!db->DB_insert_purchase(sID.toInt() + 1, sPrice.toDouble(), sNumber.toInt(), sDate.toStdString(), sSupplier.toInt(), sMerchandise.toInt())) {
			QMessageBox::information(NULL, "提示", "插入失败!", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		db->DB_query_purchase(res, size);
		ui.TB_Purchase->setRowCount(size.first);
		ui.TB_Purchase->setColumnCount(size.second);
		ui.TB_Purchase->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("进价") << QString::fromUtf8("数量") << QString::fromUtf8("日期") << QString::fromUtf8("供货商ID") << QString::fromUtf8("商品ID"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Purchase->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Del_Purchase, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		QString sID = QInputDialog::getText(this, "ID", "<html style = \"font-size:12pt;\">请输入要删除的订单ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		db->DB_delete_purchase(sID.toInt());
		db->DB_query_purchase(res, size);
		ui.TB_Purchase->setRowCount(size.first);
		ui.TB_Purchase->setColumnCount(size.second);
		ui.TB_Purchase->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("进价") << QString::fromUtf8("数量") << QString::fromUtf8("日期") << QString::fromUtf8("供货商ID") << QString::fromUtf8("商品ID"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Purchase->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Out_Purchase, &QPushButton::clicked, [=]()mutable {
		QString filepath = QFileDialog::getSaveFileName(this, tr("Save"), ".", tr(" (*.xlsx)"));
		if (!filepath.isEmpty()) {
			QAxObject* excel = new QAxObject(this);
			excel->setControl("Excel.Application");
			excel->dynamicCall("SetVisible (bool Visible)", "false");
			excel->setProperty("DisplayAlerts", false);
			QAxObject* workbooks = excel->querySubObject("WorkBooks");
			workbooks->dynamicCall("Add");
			QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
			QAxObject* worksheets = workbook->querySubObject("Sheets");
			QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);
			int rows = ui.TB_Inventory->rowCount();
			int cols = ui.TB_Inventory->columnCount();
			for (int i = 1; i <= cols; i++) {
				QAxObject* Range = worksheet->querySubObject("Cells(int,int)", 1, i);
				Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->horizontalHeaderItem(i - 1)->text()));
				for (int j = 2; j < rows + 2; j++) {
					QAxObject* Range = worksheet->querySubObject("Cells(int,int)", j, i);
					if (ui.TB_Inventory->item(j - 2, i - 1) != NULL) Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->item(j - 2, i - 1)->text()));
					else Range->dynamicCall("SetValue(const QString &)", QVariant(""));
				}
			}
			workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));
			workbook->dynamicCall("Close()");
			excel->dynamicCall("Quit()");
			delete excel;
		}
		});

	connect(ui.PB_Supplier, &QPushButton::clicked, [=]()mutable {
		db->DB_query_supplier(res, size);
		ui.TB_Supplier->setRowCount(size.first);
		ui.TB_Supplier->setColumnCount(size.second);
		ui.TB_Supplier->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("地址") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Supplier->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Add_Supplier, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		db->DB_query("SELECT MAX(ID) FROM supplier;", res, size);
		QString sID = mysql_fetch_row(res)[0];
		mysql_free_result(res);
		QString sName = QInputDialog::getText(this, "姓名", "<html style = \"font-size:12pt;\">请输入姓名</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sAddress = QInputDialog::getText(this, "地址", "<html style = \"font-size:12pt;\">请输入地址</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sInformation = QInputDialog::getText(this, "信息", "<html style = \"font-size:12pt;\">请输入信息</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		if (!db->DB_insert_supplier(sID.toInt() + 1, sName.toStdString(), sAddress.toStdString(), sInformation.toStdString())) {
			QMessageBox::information(NULL, "提示", "插入失败!", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		db->DB_query_supplier(res, size);
		ui.TB_Supplier->setRowCount(size.first);
		ui.TB_Supplier->setColumnCount(size.second);
		ui.TB_Supplier->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("地址") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Supplier->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Del_Supplier, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		QString sID = QInputDialog::getText(this, "ID", "<html style = \"font-size:12pt;\">请输入要删除的订单ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		db->DB_delete_supplier(sID.toInt());
		db->DB_query_supplier(res, size);
		ui.TB_Supplier->setRowCount(size.first);
		ui.TB_Supplier->setColumnCount(size.second);
		ui.TB_Supplier->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("地址") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Supplier->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Mdf_Supplier, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		QString sID = QInputDialog::getText(this, "ID", "<html style = \"font-size:12pt;\">需要修改的供应商ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sName = QInputDialog::getText(this, "姓名", "<html style = \"font-size:12pt;\">请输入修改后姓名</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sAddress = QInputDialog::getText(this, "地址", "<html style = \"font-size:12pt;\">请输入修改后地址</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sInformation = QInputDialog::getText(this, "信息", "<html style = \"font-size:12pt;\">请输入修改后信息</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		db->DB_modify_supplier(sID.toInt(), sName.toStdString(), sAddress.toStdString(), sInformation.toStdString());
		db->DB_query_supplier(res, size);
		ui.TB_Supplier->setRowCount(size.first);
		ui.TB_Supplier->setColumnCount(size.second);
		ui.TB_Supplier->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("地址") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Supplier->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Out_Supplier, &QPushButton::clicked, [=]()mutable {
		QString filepath = QFileDialog::getSaveFileName(this, tr("Save"), ".", tr(" (*.xlsx)"));
		if (!filepath.isEmpty()) {
			QAxObject* excel = new QAxObject(this);
			excel->setControl("Excel.Application");
			excel->dynamicCall("SetVisible (bool Visible)", "false");
			excel->setProperty("DisplayAlerts", false);
			QAxObject* workbooks = excel->querySubObject("WorkBooks");
			workbooks->dynamicCall("Add");
			QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
			QAxObject* worksheets = workbook->querySubObject("Sheets");
			QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);
			int rows = ui.TB_Inventory->rowCount();
			int cols = ui.TB_Inventory->columnCount();
			for (int i = 1; i <= cols; i++) {
				QAxObject* Range = worksheet->querySubObject("Cells(int,int)", 1, i);
				Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->horizontalHeaderItem(i - 1)->text()));
				for (int j = 2; j < rows + 2; j++) {
					QAxObject* Range = worksheet->querySubObject("Cells(int,int)", j, i);
					if (ui.TB_Inventory->item(j - 2, i - 1) != NULL) Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->item(j - 2, i - 1)->text()));
					else Range->dynamicCall("SetValue(const QString &)", QVariant(""));
				}
			}
			workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));
			workbook->dynamicCall("Close()");
			excel->dynamicCall("Quit()");
			delete excel;
		}
		});

	connect(ui.PB_Sell, &QPushButton::clicked, [=]()mutable {
		db->DB_query_sell(res, size);
		ui.TB_Sell->setRowCount(size.first);
		ui.TB_Sell->setColumnCount(size.second);
		ui.TB_Sell->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("价格") << QString::fromUtf8("数量") << QString::fromUtf8("日期") << QString::fromUtf8("员工ID") << QString::fromUtf8("商品ID"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Sell->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Add_Sell, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		db->DB_query("SELECT MAX(ID) FROM sell;", res, size);
		QString sID = mysql_fetch_row(res)[0];
		mysql_free_result(res);
		QString sNumber = QInputDialog::getText(this, "数量", "<html style = \"font-size:12pt;\">输入数量</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sDate = QInputDialog::getText(this, "日期", "<html style = \"font-size:12pt;\">输入日期</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sStaff = QInputDialog::getText(this, "员工ID", "<html style = \"font-size:12pt;\">输入员工ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sMerchandise = QInputDialog::getText(this, "商品ID", "<html style = \"font-size:12pt;\">输入商品ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		if (!db->DB_insert_sell(sID.toInt() + 1, 0, sNumber.toInt(), sDate.toStdString(), sStaff.toInt(), sMerchandise.toInt())) {
			QMessageBox::information(NULL, "提示", "插入失败!", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		db->DB_query_sell(res, size);
		ui.TB_Sell->setRowCount(size.first);
		ui.TB_Sell->setColumnCount(size.second);
		ui.TB_Sell->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("价格") << QString::fromUtf8("数量") << QString::fromUtf8("日期") << QString::fromUtf8("员工ID") << QString::fromUtf8("商品ID"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Sell->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Del_Sell, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		QString sID = QInputDialog::getText(this, "ID", "<html style = \"font-size:12pt;\">请输入要删除的订单ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		db->DB_delete_sell(sID.toInt());
		db->DB_query_sell(res, size);
		ui.TB_Sell->setRowCount(size.first);
		ui.TB_Sell->setColumnCount(size.second);
		ui.TB_Sell->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("价格") << QString::fromUtf8("数量") << QString::fromUtf8("日期") << QString::fromUtf8("员工ID") << QString::fromUtf8("商品ID"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Sell->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Out_Sell, &QPushButton::clicked, [=]()mutable {
		QString filepath = QFileDialog::getSaveFileName(this, tr("Save"), ".", tr(" (*.xlsx)"));
		if (!filepath.isEmpty()) {
			QAxObject* excel = new QAxObject(this);
			excel->setControl("Excel.Application");
			excel->dynamicCall("SetVisible (bool Visible)", "false");
			excel->setProperty("DisplayAlerts", false);
			QAxObject* workbooks = excel->querySubObject("WorkBooks");
			workbooks->dynamicCall("Add");
			QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
			QAxObject* worksheets = workbook->querySubObject("Sheets");
			QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);
			int rows = ui.TB_Inventory->rowCount();
			int cols = ui.TB_Inventory->columnCount();
			for (int i = 1; i <= cols; i++) {
				QAxObject* Range = worksheet->querySubObject("Cells(int,int)", 1, i);
				Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->horizontalHeaderItem(i - 1)->text()));
				for (int j = 2; j < rows + 2; j++) {
					QAxObject* Range = worksheet->querySubObject("Cells(int,int)", j, i);
					if (ui.TB_Inventory->item(j - 2, i - 1) != NULL) Range->dynamicCall("SetValue(const QString &)", QVariant(ui.TB_Inventory->item(j - 2, i - 1)->text()));
					else Range->dynamicCall("SetValue(const QString &)", QVariant(""));
				}
			}
			workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));
			workbook->dynamicCall("Close()");
			excel->dynamicCall("Quit()");
			delete excel;
		}
		});

	connect(ui.PB_Staff, &QPushButton::clicked, [=]()mutable {
		db->DB_query_staff(res, size);
		ui.TB_Staff->setRowCount(size.first);
		ui.TB_Staff->setColumnCount(size.second);
		ui.TB_Staff->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("性别") << QString::fromUtf8("年龄") << QString::fromUtf8("薪资") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Staff->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Add_Staff, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		db->DB_query("SELECT MAX(ID) FROM staff;", res, size);
		QString sID = mysql_fetch_row(res)[0];
		mysql_free_result(res);
		QString sName = QInputDialog::getText(this, "姓名", "<html style = \"font-size:12pt;\">输入姓名</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sSex = QInputDialog::getText(this, "性别", "<html style = \"font-size:12pt;\">输入性别</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sAge = QInputDialog::getText(this, "年龄", "<html style = \"font-size:12pt;\">输入年龄</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sSalary = QInputDialog::getText(this, "薪资", "<html style = \"font-size:12pt;\">输入薪资</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sInformation = QInputDialog::getText(this, "信息", "<html style = \"font-size:12pt;\">输入信息</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		if (!db->DB_insert_staff(sID.toInt() + 1, sName.toStdString(), sSex.toStdString(), sAge.toInt(), sSalary.toDouble(), sInformation.toStdString())) {
			QMessageBox::information(NULL, "提示", "插入失败!", QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
		}
		db->DB_query_staff(res, size);
		ui.TB_Staff->setRowCount(size.first);
		ui.TB_Staff->setColumnCount(size.second);
		ui.TB_Staff->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("性别") << QString::fromUtf8("年龄") << QString::fromUtf8("薪资") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Staff->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});


	connect(ui.PB_Del_Staff, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		QString sID = QInputDialog::getText(this, "ID", "<html style = \"font-size:12pt;\">请输入要删除的员工ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		db->DB_delete_staff(sID.toInt());
		db->DB_query_staff(res, size);
		ui.TB_Staff->setRowCount(size.first);
		ui.TB_Staff->setColumnCount(size.second);
		ui.TB_Staff->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("性别") << QString::fromUtf8("年龄") << QString::fromUtf8("薪资") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Staff->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Mdf_Staff, &QPushButton::clicked, [=]()mutable {
		bool flag = false;
		QString sID = QInputDialog::getText(this, "ID", "<html style = \"font-size:12pt;\">需要修改的员工ID</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sName = QInputDialog::getText(this, "姓名", "<html style = \"font-size:12pt;\">输入修改后姓名</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sSex = QInputDialog::getText(this, "性别", "<html style = \"font-size:12pt;\">输入修改后性别</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sAge = QInputDialog::getText(this, "年龄", "<html style = \"font-size:12pt;\">输入修改后年龄</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sSalary = QInputDialog::getText(this, "薪资", "<html style = \"font-size:12pt;\">输入修改后薪资</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		QString sInformation = QInputDialog::getText(this, "信息", "<html style = \"font-size:12pt;\">输入修改后信息</html>", QLineEdit::Normal, "", &flag); if (!flag) return;
		db->DB_modify_staff(sID.toInt(), sName.toStdString(), sSex.toStdString(), sAge.toInt(), sSalary.toDouble(), sInformation.toStdString());
		db->DB_query_staff(res, size);
		ui.TB_Staff->setRowCount(size.first);
		ui.TB_Staff->setColumnCount(size.second);
		ui.TB_Staff->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("ID") << QString::fromUtf8("姓名") << QString::fromUtf8("性别") << QString::fromUtf8("年龄") << QString::fromUtf8("薪资") << QString::fromUtf8("信息"));
		for (int row = 0; row < size.first; row++) {
			auto rowd = mysql_fetch_row(res);
			for (int col = 0; col < size.second; col++) ui.TB_Staff->setItem(row, col, new QTableWidgetItem(QString::fromUtf8(rowd[col])));
		}
		mysql_free_result(res);
		});

	connect(ui.PB_Income, &QPushButton::clicked, [=]()mutable {
		ui.LE_Inc_Year->setText("2023");
		std::string year = ui.LE_Inc_Year->text().toStdString();
		ui.TB_Income->setRowCount(13);
		ui.TB_Income->setColumnCount(4);
		ui.TB_Income->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("日期") << QString::fromUtf8("收入") << QString::fromUtf8("支出") << QString::fromUtf8("利润"));
		double tot_sel = 0.0, tot_pur = 0.0;
		for (int mon = 1; mon <= 12; mon++) {
			double sum_sel = 0.0, sum_pur = 0.0;
			ui.TB_Income->setItem(mon - 1, 0, new QTableWidgetItem(QString::fromStdString(year + "-" + std::to_string(mon))));
			std::string str = "SELECT sum(price) FROM sell WHERE month(date) = " + std::to_string(mon) + " and year(date) = " + year + ";";
			db->DB_query(str.c_str(), res, size);
			if (size != std::pair<int, int>({ 0, 0 })) {
				QString tmp_sum = mysql_fetch_row(res)[0];
				sum_sel = tmp_sum.toDouble();
			}
			mysql_free_result(res);
			ui.TB_Income->setItem(mon - 1, 1, new QTableWidgetItem(QString::number(sum_sel)));
			str = "SELECT sum(price) FROM purchase WHERE month(date) = " + std::to_string(mon) + " and year(date) = " + year + ";";
			db->DB_query(str.c_str(), res, size);
			if (size != std::pair<int, int>({ 0, 0 })) {
				QString tmp_sum = mysql_fetch_row(res)[0];
				sum_pur = tmp_sum.toDouble();
			}
			mysql_free_result(res);
			ui.TB_Income->setItem(mon - 1, 2, new QTableWidgetItem(QString::number(sum_pur)));
			ui.TB_Income->setItem(mon - 1, 3, new QTableWidgetItem(QString::number(sum_sel - sum_pur)));
			tot_sel += sum_sel, tot_pur += sum_pur;
		}
		ui.TB_Income->setItem(12, 0, new QTableWidgetItem(QString::fromStdString("全年")));
		ui.TB_Income->setItem(12, 1, new QTableWidgetItem(QString::number(tot_sel)));
		ui.TB_Income->setItem(12, 2, new QTableWidgetItem(QString::number(tot_pur)));
		ui.TB_Income->setItem(12, 3, new QTableWidgetItem(QString::number(tot_sel - tot_pur)));
		});

	connect(ui.PB_Que_Inc, &QPushButton::clicked, [=]()mutable {
		std::string year = ui.LE_Inc_Year->text().toStdString();
		ui.TB_Income->setRowCount(13);
		ui.TB_Income->setColumnCount(4);
		ui.TB_Income->setHorizontalHeaderLabels(QStringList() << QString::fromUtf8("日期") << QString::fromUtf8("收入") << QString::fromUtf8("支出") << QString::fromUtf8("利润"));
		double tot_sel = 0.0, tot_pur = 0.0;
		for (int mon = 1; mon <= 12; mon++) {
			double sum_sel = 0.0, sum_pur = 0.0;
			ui.TB_Income->setItem(mon - 1, 0, new QTableWidgetItem(QString::fromStdString(year + "-" + std::to_string(mon))));
			std::string str = "SELECT sum(price) FROM sell WHERE month(date) = " + std::to_string(mon) + " and year(date) = " + year + ";";
			db->DB_query(str.c_str(), res, size);
			if (size != std::pair<int, int>({ 0, 0 })) {
				QString tmp_sum = mysql_fetch_row(res)[0];
				sum_sel = tmp_sum.toDouble();
			}
			mysql_free_result(res);
			ui.TB_Income->setItem(mon - 1, 1, new QTableWidgetItem(QString::number(sum_sel)));
			str = "SELECT sum(price) FROM purchase WHERE month(date) = " + std::to_string(mon) + " and year(date) = " + year + ";";
			db->DB_query(str.c_str(), res, size);
			if (size != std::pair<int, int>({ 0, 0 })) {
				QString tmp_sum = mysql_fetch_row(res)[0];
				sum_pur = tmp_sum.toDouble();
			}
			mysql_free_result(res);
			ui.TB_Income->setItem(mon - 1, 2, new QTableWidgetItem(QString::number(sum_pur)));
			ui.TB_Income->setItem(mon - 1, 3, new QTableWidgetItem(QString::number(sum_sel - sum_pur)));
			tot_sel += sum_sel, tot_pur += sum_pur;
		}
		ui.TB_Income->setItem(12, 0, new QTableWidgetItem(QString::fromStdString("全年")));
		ui.TB_Income->setItem(12, 1, new QTableWidgetItem(QString::number(tot_sel)));
		ui.TB_Income->setItem(12, 2, new QTableWidgetItem(QString::number(tot_pur)));
		ui.TB_Income->setItem(12, 3, new QTableWidgetItem(QString::number(tot_sel - tot_pur)));
		});
}

MainWindow::~MainWindow()
{}

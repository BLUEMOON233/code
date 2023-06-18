#include "DataStructProgram.h"
#include <QFileDialog>
#include <QDebug> 
#include <QMessageBox>
#include <algorithm>
#include <cstring>

DataStructProgram::DataStructProgram(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::DataStructProgramClass)
{
	//��ʼ��������
	ui->setupUi(this);
	ui->stackedWidget->setCurrentIndex(0);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->P3_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->P4_tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->systemState->setCurrentIndex(0);

	//��ҳ���л���
	connect(ui->mainPB1, &QPushButton::clicked, [=]()mutable {
		ui->stackedWidget->setCurrentIndex(0);
		});
	connect(ui->mainPB2, &QPushButton::clicked, [=]()mutable {
		ui->stackedWidget->setCurrentIndex(1);
		});
	connect(ui->mainPB3, &QPushButton::clicked, [=]()mutable {
		ui->stackedWidget->setCurrentIndex(2);
		});
	connect(ui->mainPB4, &QPushButton::clicked, [=]()mutable {
		ui->stackedWidget->setCurrentIndex(3);
		});
	connect(ui->mainPB5, &QPushButton::clicked, [=]()mutable {
		this->close();
		});

	//���뵼���ļ���
	connect(ui->systemOpenFile, &QPushButton::clicked, [=]() mutable {
		QString filePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit(std::string("ѡ���ļ�").data()), QString::fromLocal8Bit(std::string("D:/DataStruct/data").data()));
		if (filePath.isEmpty()) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("·��Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}

		DSTS.initSystem(filePath);
		ui->systemState->setCurrentIndex(1);
		});

	connect(ui->systemSaveFile, &QPushButton::clicked, [=]()mutable {
		QString filePath = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit(std::string("ѡ���ļ���").data()), "D:/DataStruct/data");
		if (filePath.isEmpty()) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("·��Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		DSTS.saveSystem(filePath);
		});

	//�������棺
	connect(ui->P2_PBopenFile, &QPushButton::clicked, [=]() mutable {
		std::string majorName(ui->P2_LEname->text().toLocal8Bit());
		QString classNumData = ui->P2_LEclassNum->text();
		QString stuNumData = ui->P2_LEstuNum->text();
		if (majorName == "") {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("רҵ��Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		if (classNumData.isEmpty()) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("�༶����Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		if (stuNumData.isEmpty()) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("�༶����Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		int classNum = classNumData.toInt();
		int stuNum = stuNumData.toInt();
		ui->P2_LEclassNum->clear();
		ui->P2_LEstuNum->clear();
		ui->P2_LEname->clear();

		QString filePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit(std::string("ѡ���ļ�").data()), QString::fromLocal8Bit(std::string("D:/DataStruct/data/�����������").data()));
		if (filePath.isEmpty()) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("·��Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		else {
			QByteArray cdata = filePath.toLocal8Bit();
			std::pair<int, int> pairNum = { classNum, stuNum };
			int nodeNum = this->DSP.addMajorList(std::string(cdata), majorName, pairNum);
			ui->tableWidget->setColumnCount(4);
			ui->tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("���").data()) << QString::fromLocal8Bit(std::string("־Ը").data()) << QString("GPA") << QString::fromLocal8Bit(std::string("����").data()));
			ui->tableWidget->setRowCount(nodeNum);
			for (int i = 0, col = 0; i < nodeNum; i++, col = 0) {
				D_S_Student now = this->DSP.getNodeByPos(this->DSP.getListNum(), i + 1);
				ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(now.ID)));
				ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(now.choice)));
				ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(now.GPA, 'f', 2)));
				ui->tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(now.rank)));
			}
		}
		});

	connect(ui->P2_PBstartDiver, &QPushButton::clicked, [=]() mutable {
		if (DSTS.isInit) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("���з���������").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		std::vector<double> grade = DSTS.initSystem(DSP);
		std::vector<int> classNum = DSTS.getClassNum();
		ui->tableWidget->setColumnCount(3);
		ui->tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("רҵ").data()) << QString::fromLocal8Bit(std::string("�༶").data()) << QString::fromLocal8Bit(std::string("GPA��ֵ").data()));
		ui->tableWidget->setRowCount(grade.size());
		for (int i = 0, nowClass = 0; i < classNum.size(); i++) for (int j = 0, col = 0; j < classNum[i]; j++, nowClass++, col = 0) {
			ui->tableWidget->setItem(nowClass, col++, new QTableWidgetItem(QString::fromLocal8Bit(DSTS.getMajorName(i + 1).data())));
			ui->tableWidget->setItem(nowClass, col++, new QTableWidgetItem(QString::number(nowClass + 1)));
			ui->tableWidget->setItem(nowClass, col++, new QTableWidgetItem(QString::number(grade[nowClass], 'f', 2)));
		}
		ui->systemState->setCurrentIndex(1);
		});

	connect(ui->P2_PBclearDiver, &QPushButton::clicked, [=]() mutable {
		DSTS.deleteSystem();
		ui->systemState->setCurrentIndex(0);
		});

	connect(ui->P2_PBQuery, &QPushButton::clicked, [=]() mutable {
		if (!DSTS.isInit) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("δ��⵽����������").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		int nowID = ui->P2_LE_IDQuery->text().toInt();
		D_S_StudentPro now = DSTS.getArrayNodeByID(nowID);
		if (now.ID == -1) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("δ�ҵ���ѧ��ѧ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		ui->P2_LEmajorModify->setText(QString::fromLocal8Bit(DSTS.getMajorName(now.choice[0].first).data()));
		ui->P2_LEclassModify->setText(QString::number(now.choice[0].second));
		});

	connect(ui->P2_PBModify, &QPushButton::clicked, [=]() mutable {
		if (!DSTS.isInit) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("δ��⵽����������").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		int nowID = ui->P2_LE_IDQuery->text().toInt();
		if (nowID == 0) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("δ�ҵ���ѧ��ѧ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		if (ui->P2_LEmajorModify->text().isEmpty()) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("רҵ��������Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		if (ui->P2_LEclassModify->text().isEmpty()) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("�༶������Ϊ��").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		int majorPos = DSTS.getMajorPos(std::string(ui->P2_LEmajorModify->text().toLocal8Bit()));
		if (majorPos == 0) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("רҵ������").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		std::pair<int, int> classPos = DSTS.getMajorClassPos(majorPos);
		if (ui->P2_LEclassModify->text().toInt() < classPos.first + 1 || ui->P2_LEclassModify->text().toInt() > classPos.first + classPos.second) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("�༶������").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		DSTS.modifyArrayNodeByID(nowID, majorPos, ui->P2_LEclassModify->text().toInt());
		DSTS.sortSystem();
		ui->P2_LEmajorModify->clear();
		ui->P2_LEclassModify->clear();
		});

	//���ݲ鿴���棺
	connect(ui->mainPB3, &QPushButton::clicked, [=]() mutable {
		ui->P3_tableWidget->clear();
		if (!DSTS.isInit) {
			ui->P3_tableWidget->setColumnCount(1);
			ui->P3_tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("δ��⵽������ѧ���б�").data()));
			return;
		}
		std::vector<D_S_StudentPro> DSSarray = DSTS.getArray();
		ui->P3_tableWidget->setColumnCount(5);
		ui->P3_tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("רҵ").data()) << QString::fromLocal8Bit(std::string("�༶").data()) << QString::fromLocal8Bit(std::string("����").data()) << QString::fromLocal8Bit(std::string("ѧ��").data()) << QString::fromLocal8Bit(std::string("����").data()));
		ui->P3_tableWidget->setRowCount(DSSarray.size());
		for (int i = 0, col = 0; i < DSSarray.size(); i++, col = 0) {
			ui->P3_tableWidget->setItem(i, col++, new QTableWidgetItem(QString::fromLocal8Bit(DSTS.getMajorName(DSSarray[i].choice[0].first).data())));
			ui->P3_tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(DSSarray[i].choice[0].second)));
			ui->P3_tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(DSSarray[i].rank)));
			ui->P3_tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(DSSarray[i].ID)));
			ui->P3_tableWidget->setItem(i, col++, new QTableWidgetItem(QString::number(DSSarray[i].GPA, 'f', 2)));
		}
		});

	connect(ui->P3_PBstartFilt, &QPushButton::clicked, [=]()mutable {
		if (!DSTS.isInit) {
			ui->P3_tableWidget->setColumnCount(1);
			ui->P3_tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("δ��⵽������ѧ���б�").data()));
			return;
		}
		int lmt_major = -1, lmt_class = -1, lmt_ID = -1, lmt_rank = -1, nowRow = 0;
		std::vector<D_S_StudentPro> DSSarray = DSTS.getArray();
		std::string majorNameStr(ui->P3_LElimitedMajor->text().toLocal8Bit());
		QString lmt_classStr = ui->P3_LElimitedClass->text();
		QString lmt_IDStr = ui->P3_LElimitedID->text();
		QString lmt_rankStr = ui->P3_LElimitedRank->text();
		if (!majorNameStr.empty()) lmt_major = DSTS.getMajorPos(majorNameStr);
		if (!lmt_classStr.isEmpty()) lmt_class = lmt_classStr.toInt();
		if (!lmt_IDStr.isEmpty()) lmt_ID = lmt_IDStr.toInt();
		if (!lmt_rankStr.isEmpty()) lmt_rank = lmt_rankStr.toInt();

		ui->P3_tableWidget->setColumnCount(5);
		ui->P3_tableWidget->setRowCount(nowRow);
		ui->P3_tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("רҵ").data()) << QString::fromLocal8Bit(std::string("�༶").data()) << QString::fromLocal8Bit(std::string("����").data()) << QString::fromLocal8Bit(std::string("ѧ��").data()) << QString::fromLocal8Bit(std::string("����").data()));
		for (int i = 0, col = 0; i < DSSarray.size(); i++, col = 0) {
			if (lmt_major != -1 && lmt_major != DSSarray[i].choice[0].first) continue;
			if (lmt_class != -1 && lmt_class != DSSarray[i].choice[0].second) continue;
			if (lmt_ID != -1 && lmt_ID != DSSarray[i].ID) continue;
			if (lmt_rank != -1 && lmt_rank != DSSarray[i].rank) continue;
			ui->P3_tableWidget->setRowCount(++nowRow);
			ui->P3_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::fromLocal8Bit(DSTS.getMajorName(DSSarray[i].choice[0].first).data())));
			ui->P3_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSarray[i].choice[0].second)));
			ui->P3_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSarray[i].rank)));
			ui->P3_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSarray[i].ID)));
			ui->P3_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSarray[i].GPA, 'f', 2)));
		}
		});

	//���ݷ�����
	connect(ui->P4_PBanalyse, &QPushButton::clicked, [=]()mutable {
		if (!DSTS.isInit) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("δ��⵽����������").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		int sumClassNum = 0, nowRow = 0;
		std::vector<int> intVec;
		std::vector<int> classNumVec = DSTS.getClassNum();
		for (auto& x : classNumVec) sumClassNum += x;
		DSST.build(DSTS, 1, DSTS.getStuNum());
		std::string qry_classStr(ui->P4_LEclass->text().toLocal8Bit());
		std::string qry_majorStr(ui->P4_LEmajor->text().toLocal8Bit());
		if (!(qry_majorStr.empty() ^ qry_classStr.empty())) {
			QMessageBox::information(NULL, QString::fromLocal8Bit(std::string("����").data()), QString::fromLocal8Bit(std::string("��ѯֵ�쳣").data()), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
			return;
		}
		if (!qry_classStr.empty()) {
			string_split(qry_classStr, ";", intVec);
			std::sort(intVec.begin(), intVec.end());
			intVec.erase(std::unique(intVec.begin(), intVec.end()), intVec.end());
			ui->P4_tableWidget->setColumnCount(6);
			ui->P4_tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("רҵ").data()) << QString::fromLocal8Bit(std::string("�༶").data()) << QString::fromLocal8Bit(std::string("GPA��ֵ").data()) << QString::fromLocal8Bit(std::string("GPA���ֵ").data()) << QString::fromLocal8Bit(std::string("GPA��Сֵ").data()) << QString::fromLocal8Bit(std::string("����").data()));
			for (auto& x : intVec) {
				if (x <= 0 || x > sumClassNum) continue;
				int majorCnt = 0, temp = x;
				while (temp - classNumVec[majorCnt] > 0) temp -= classNumVec[majorCnt], majorCnt++;
				int l = DSTS.getClassLeftRange(x) + 1, r = DSTS.getClassLeftRange(x + 1), col = 0;
				D_S_S_TreeNode DSSTN = DSST.query(l, r);
				double averGPA = DSSTN.GPASum / double(r - l + 1);
				double GPA_S = DSST.getS(l, r, averGPA);
				ui->P4_tableWidget->setRowCount(++nowRow);
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::fromLocal8Bit(DSTS.getMajorName(majorCnt + 1).data())));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(x)));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(averGPA, 'f', 2)));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSTN.GPAMax, 'f', 2)));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSTN.GPAMin, 'f', 2)));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(GPA_S, 'f', 4)));
			}
		}
		std::vector<std::string> strVec;
		if (!qry_majorStr.empty()) {
			string_split(qry_majorStr, ";", strVec);
			std::sort(strVec.begin(), strVec.end());
			strVec.erase(std::unique(strVec.begin(), strVec.end()), strVec.end());
			ui->P4_tableWidget->setColumnCount(5);
			ui->P4_tableWidget->setHorizontalHeaderLabels(QStringList() << QString::fromLocal8Bit(std::string("רҵ").data()) << QString::fromLocal8Bit(std::string("GPA��ֵ").data()) << QString::fromLocal8Bit(std::string("GPA���ֵ").data()) << QString::fromLocal8Bit(std::string("GPA��Сֵ").data()) << QString::fromLocal8Bit(std::string("����").data()));
			for (auto& x : strVec) {
				int majorPos = DSTS.getMajorPos(x);
				if (!majorPos) continue;
				int l = DSTS.getMajorLeftRange(majorPos) + 1, r = DSTS.getMajorLeftRange(majorPos + 1), col = 0;
				D_S_S_TreeNode DSSTN = DSST.query(l, r);
				double averGPA = DSSTN.GPASum / double(r - l + 1);
				double GPA_S = DSST.getS(l, r, averGPA);
				ui->P4_tableWidget->setRowCount(++nowRow);
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::fromLocal8Bit(DSTS.getMajorName(majorPos).data())));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(averGPA, 'f', 2)));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSTN.GPAMax, 'f', 2)));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(DSSTN.GPAMin, 'f', 2)));
				ui->P4_tableWidget->setItem(nowRow - 1, col++, new QTableWidgetItem(QString::number(GPA_S, 'f', 4)));
			}
		}
		DSST.deleteTree();
		});
}

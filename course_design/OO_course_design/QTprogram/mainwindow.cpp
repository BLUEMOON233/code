#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200, 900);
    sm.Read();
    //界面设置：
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->mainPB, &QPushButton::clicked, [=]()mutable{
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->adddelPB, &QPushButton::clicked, [=]()mutable{
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->modifyPB, &QPushButton::clicked, [=]()mutable{
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->queryPB, &QPushButton::clicked, [=]()mutable{
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->exitPB, &QPushButton::clicked, this, &MainWindow::close);

    connect(ui->exitPB, &QPushButton::clicked, [&](){
        sm.Write();
    });

    //增删操作：
    connect(ui->ad_startPB, &QPushButton::clicked, [&](){
        sl.initStudentList(sm);
    });
    connect(ui->ad_endPB, &QPushButton::clicked, [&](){
        sm.StudentList2Manager(sl);
        sl.freeList();
    });
    connect(ui->ad_addPB, &QPushButton::clicked, [&](){
        int tNum = ui->ad_numLE->text().toInt();
        string tName = ui->ad_nameLE->text().toStdString();
        string tSGender = ui->ad_genderLE->text().toStdString();
        bool tGender = false;
        if(tSGender == "male") tGender = true;
        else if(tSGender == "female") tGender = false;
        double tMathGrade = ui->ad_mathLE->text().toDouble();
        double tComGrade = ui->ad_comLE->text().toDouble();
        double tEngGrade = ui->ad_engLE->text().toDouble();
        double tPhyGrade = ui->ad_phyLE->text().toDouble();
        CStudent s(tNum, tName, tGender, tMathGrade, tComGrade, tEngGrade, tPhyGrade);
        sl.addList(s);
    });
    connect(ui->ad_delPB, &QPushButton::clicked, [&](){
        int tNum = ui->ad_delNumLE->text().toInt();
        sl.deleteList(tNum);
    });
    connect(ui->ad_istPB, &QPushButton::clicked, [&](){
        int tNum = ui->ad_istNumLE->text().toInt();
        string tName = ui->ad_istNameLE->text().toStdString();
        string tSGender = ui->ad_istGenderLE->text().toStdString();
        bool tGender = false;
        if(tSGender == "male") tGender = true;
        else if(tSGender == "female") tGender = false;
        double tMathGrade = ui->ad_istMathLE->text().toDouble();
        double tComGrade = ui->ad_istComLE->text().toDouble();
        double tEngGrade = ui->ad_istEngLE->text().toDouble();
        double tPhyGrade = ui->ad_istPhyLE->text().toDouble();
        CStudent s(sm.getCount()+1, tName, tGender, tMathGrade, tComGrade, tEngGrade, tPhyGrade);
        sl.insertList(tNum, s);
    });
    //修改操作：
    connect(ui->mo_queryPB, &QPushButton::clicked, [&](){
        string name;
        bool bgender;
        double mathgrade, comgrade, enggrade, phygrade;
        int pos = ui->mo_numLE->text().toInt();
        CStudent* SP = sm.queryStudent(pos);
        if(SP != nullptr){
            SP->getInfo(name, bgender, mathgrade, comgrade, enggrade, phygrade);
            ui->mo_nameLE->setText(QString::fromStdString(name));
            QString gender;
            if(bgender) gender = "male";
            else gender = "female";
            ui->mo_genderLE->setText(gender);
            ui->mo_mathLE->setText(QString::number(mathgrade));
            ui->mo_comLE->setText(QString::number(comgrade));
            ui->mo_engLE->setText(QString::number(enggrade));
            ui->mo_phyLE->setText(QString::number(phygrade));
        }
    });
    connect(ui->mo_savePB, &QPushButton::clicked, [&](){
        string tName = ui->mo_nameLE->text().toStdString();
        string tSGender = ui->mo_genderLE->text().toStdString();
        bool tGender = false;
        if(tSGender == "male") tGender = true;
        else if(tSGender == "female") tGender = false;
        double tMathGrade = ui->mo_mathLE->text().toDouble();
        double tComGrade = ui->mo_comLE->text().toDouble();
        double tEngGrade = ui->mo_engLE->text().toDouble();
        double tPhyGrade = ui->mo_phyLE->text().toDouble();
        int pos = ui->mo_numLE->text().toInt();
        CStudent* SP = sm.queryStudent(pos);
        if(SP!=nullptr) SP->editInfo(tName, tGender, tMathGrade, tComGrade, tEngGrade, tPhyGrade);
    });
    //查询操作：
    ui->qu_stackedWidget->setCurrentIndex(0);
    connect(ui->qu_singgleInfoPB, &QPushButton::clicked, [=]()mutable{
        ui->qu_stackedWidget->setCurrentIndex(0);
    });
    connect(ui->qu_someInfoPB, &QPushButton::clicked, [=]()mutable{
        ui->qu_stackedWidget->setCurrentIndex(1);
    });
    connect(ui->qu_queryPosPB, &QPushButton::clicked, [&](){
        ui->qu_tableWidget->setColumnCount(1);
        ui->qu_tableWidget->setRowCount(0);
        ui->qu_tableWidget->clear();
        string name;
        bool bgender;
        double mathgrade, comgrade, enggrade, phygrade;
        int pos = ui->qu_posLE->text().toInt();
        CStudent * SP = sm.queryStudent(pos);
        if(SP!=nullptr){
            SP->getInfo(name, bgender, mathgrade, comgrade, enggrade, phygrade);
            QString gender;
            if(bgender) gender = "male";
            else gender = "female";
            double sumgrade = mathgrade + comgrade + enggrade + phygrade;
            double averagegrade = sumgrade/4;
            ui->qu_tableWidget->setColumnCount(9);
            ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"编码"<<"姓名"<<"性别"<<"数学成绩"<<"计算机成绩"<<"英语成绩"<<"物理成绩"<<"总成绩"<<"平均成绩");
            ui->qu_tableWidget->setRowCount(1);
            int col = 0;
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::number(pos)));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::fromStdString(name)));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(gender));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::number(mathgrade, 'f', 2)));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::number(comgrade, 'f', 2)));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::number(enggrade, 'f', 2)));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::number(phygrade, 'f', 2)));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::number(sumgrade, 'f', 2)));
            ui->qu_tableWidget->setItem(0, col++, new QTableWidgetItem(QString::number(averagegrade, 'f', 2)));
        }else{
            ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"查询不到信息");
        }
    });
    connect(ui->qu_queryNamePB, &QPushButton::clicked, [&]{
        ui->qu_tableWidget->setColumnCount(1);
        ui->qu_tableWidget->setRowCount(0);
        ui->qu_tableWidget->clear();
        string tName = ui->qu_nameLE->text().toStdString();
        CStudentArray CSA = sm.queryStudentByName(tName);
        if(CSA.cnt!=0){
            ui->qu_tableWidget->setColumnCount(9);
            ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"编码"<<"姓名"<<"性别"<<"数学成绩"<<"计算机成绩"<<"英语成绩"<<"物理成绩"<<"总成绩"<<"平均成绩");
            ui->qu_tableWidget->setRowCount(CSA.cnt);
            for(int tms = 0;tms < CSA.cnt;tms++){
                string name;
                bool bgender;
                double mathgrade, comgrade, enggrade, phygrade;
                (*(CSA.st + tms))->getInfo(name, bgender, mathgrade, comgrade, enggrade, phygrade);
                QString gender;
                if(bgender) gender = "male";
                else gender = "female";
                double sumgrade = mathgrade + comgrade + enggrade + phygrade;
                double averagegrade = sumgrade/4;
                int col = 0;
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(*(CSA.posSt+tms))));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::fromStdString(name)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(gender));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(mathgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(comgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(enggrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(phygrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(sumgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(averagegrade, 'f', 2)));
            }
        }else{
            ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"查询不到信息");
        }
    });
    connect(ui->qu_queryAllInfoPB, &QPushButton::clicked, [&]{
        ui->qu_tableWidget->setColumnCount(9);
        ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"编码"<<"姓名"<<"性别"<<"数学成绩"<<"计算机成绩"<<"英语成绩"<<"物理成绩"<<"总成绩"<<"平均成绩");
        ui->qu_tableWidget->setRowCount(sm.getCount());
        for(int pos = 1; pos <= sm.getCount(); pos++){
            string name;
            bool bgender;
            double mathgrade, comgrade, enggrade, phygrade;
            CStudent * SP = sm.queryStudent(pos);
            if(SP!=nullptr){
                SP->getInfo(name, bgender, mathgrade, comgrade, enggrade, phygrade);
                QString gender;
                if(bgender) gender = "male";
                else gender = "female";
                double sumgrade = mathgrade + comgrade + enggrade + phygrade;
                double averagegrade = sumgrade/4;
                int col = 0;
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::number(pos)));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::fromStdString(name)));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(gender));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::number(mathgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::number(comgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::number(enggrade, 'f', 2)));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::number(phygrade, 'f', 2)));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::number(sumgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(pos - 1, col++, new QTableWidgetItem(QString::number(averagegrade, 'f', 2)));
            }
        }
    });
    connect(ui->qu_querySomeInfoPB, &QPushButton::clicked, [&](){
        StudentSegment sg;
        int ll = ui->qu_startLE->text().toInt();
        int rr = ui->qu_endLE->text().toInt();
        int NumOfStudent = rr - ll + 1;
        sg.build(sm, sg.getRoot(), 1, sm.getCount());
        try{
            SSNodeData data = sg.query(sg.getRoot(), ll, rr, sm.getCount());
            ui->qu_tableWidget->setColumnCount(1);
            ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"分数");
            ui->qu_tableWidget->setRowCount(12);
            ui->qu_tableWidget->setVerticalHeaderLabels(QStringList()<<"数学平均分"<<"数学最高分"<<"数学最低分"<<"计算机平均分"<<"计算机最高分"<<"计算机最低分"<<"英语平均分"<<"英语最高分"<<"英语最低分"<<"物理平均分"<<"物理最高分"<<"物理最低分");
            int row = -1;
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.MathGradeSum/NumOfStudent, 'f', 2)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.MathGradeMax)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.MathGradeMin)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.ComGradeSum/NumOfStudent, 'f', 2)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.ComGradeMax)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.ComGradeMin)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.EngGradeSum/NumOfStudent, 'f', 2)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.EngGradeMax)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.EngGradeMin)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.PhyGradeSum/NumOfStudent, 'f', 2)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.PhyGradeMax)));
            ui->qu_tableWidget->setItem(row++, 1, new QTableWidgetItem(QString::number(data.PhyGradeMin)));
        }catch(int inter){

        }catch(char charer){

        }catch(double doubleer){

        }
    });
    connect(ui->qu_spePB, &QPushButton::clicked, [&](){
        double tGrade = ui->qu_speGradeLE->text().toDouble();
        string tSGender = ui->qu_speGenderLE->text().toStdString();
        bool tGender = false;
        if(tSGender == "male") tGender = true;
        else if(tSGender == "female") tGender = false;
        CStudentArray CSA = sm.queryStudentByGradeAndGender(tGrade, tGender);
        if(CSA.cnt!=0){
            ui->qu_tableWidget->setColumnCount(9);
            ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"编码"<<"姓名"<<"性别"<<"数学成绩"<<"计算机成绩"<<"英语成绩"<<"物理成绩"<<"总成绩"<<"平均成绩");
            ui->qu_tableWidget->setRowCount(CSA.cnt);
            for(int tms = 0;tms < CSA.cnt;tms++){
                string name;
                bool bgender;
                double mathgrade, comgrade, enggrade, phygrade;
                (*(CSA.st + tms))->getInfo(name, bgender, mathgrade, comgrade, enggrade, phygrade);
                QString gender;
                if(bgender) gender = "male";
                else gender = "female";
                double sumgrade = mathgrade + comgrade + enggrade + phygrade;
                double averagegrade = sumgrade/4;
                int col = 0;
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(*(CSA.posSt+tms))));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::fromStdString(name)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(gender));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(mathgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(comgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(enggrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(phygrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(sumgrade, 'f', 2)));
                ui->qu_tableWidget->setItem(tms, col++, new QTableWidgetItem(QString::number(averagegrade, 'f', 2)));
            }
        }else{
            ui->qu_tableWidget->setHorizontalHeaderLabels(QStringList()<<"查询不到信息");
        }

    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


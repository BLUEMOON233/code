#pragma once
/*********************************************************
 * 版权：长安大学
 * 编写者：刘文越，王子卓，肖芷馨，孙翔，康旭
 *
 * 编写时间：2022/12/04
 * 功能描述：DivergenceSystem头文件。
 *			 包括所有自定义类的声明
**********************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <QDebug>
#include <map>

class D_S_PretreatSystem;
class D_S_TreatedSystem;
void string_split(const std::string& str, const std::string& split, std::vector<int>& rs);
void string_split(const std::string& str, const std::string& split, std::vector<std::string>& rs);

struct D_S_Student {
	/*
	原始学生数据的存储节点
	*/
	int ID = 0;  // 学生学号
	int choice = 0;  //学生志愿，值为1代表第一志愿
	double GPA = -1;  //绩点，精度维护在4位有效数字
	int rank = 0;  //学生排名信息，值为1代表排名第一
	friend std::istream& operator>>(std::istream& in, D_S_Student& DSS);
	friend std::ostream& operator<<(std::ostream& out, const D_S_Student& DSS);
};

struct D_S_DeLinkedListNode {
	D_S_Student data;
	D_S_DeLinkedListNode* pre = nullptr;
	D_S_DeLinkedListNode* nex = nullptr;
};

class D_S_MajorList {
	/*
	用于接收原始数据的链表类
	对应于一个专业的分流前初始文件
	*/
public:
	D_S_MajorList();
	~D_S_MajorList();
	void deleteMajorList(); //释放链表内存空间
	void printList(); //【调试】【控制台】输出链表
	void initList(std::string filePath); //从文件读入原始数据，并存储至链表
	void addNode(D_S_Student DSS); //增加节点
	void setListName(std::string name); //设置该专业的名称
	int getNodeNum(); //获取该专业人数

	friend D_S_PretreatSystem;
	friend D_S_TreatedSystem;

private:
	D_S_DeLinkedListNode* head = nullptr;
	D_S_DeLinkedListNode* tail = nullptr;
	std::string majorName = "NULL";
	int nodeNum = 0;
	std::pair<int, int> maxNum = { -1, -1 }; //first->专业班级数，second->班级人数
};


class D_S_PretreatSystem {
	/*
	用于将所有未分流专业报名链表整合至一起并进行分流操作
	*/
public:
	void initSystem(); //用于初始化预处理系统
	int addMajorList(std::string filePath, std::string majorName, std::pair<int, int> pairNum); //向预处理系统中增添新的专业链表类
	D_S_Student getNodeByPos(int pos1, int pos2); //通过下标获取单独学生信息
	int getListNum(); //得到专业数量
	int getListNodeNum(int pos); //通过下标获取对应专业的学生人数
	int getSumNum(); //得到学生总数

	friend D_S_TreatedSystem;

private:
	std::vector<D_S_MajorList> MajorList;
	std::map<int, bool> mp; //用于标记学生学号
	int listNum = 0;
};

struct D_S_StudentPro {
	/*
	分流后的学生数据节点
	*/
	int ID = -1; //学生学号
	double GPA = 0; //学生绩点
	int rank = 0; //学生排名
	std::vector<std::pair<int, int>> choice; //分流前代表该学生的报考情况，分流后仅有一个元素，first->专业，second->班级
	friend std::istream& operator>>(std::istream& in, D_S_StudentPro& DSSP);
	friend std::ostream& operator<<(std::ostream& out, const D_S_StudentPro& DSSP);
};

class D_S_TreatedSystem {
	/*
	分流后的学生管理系统类
	*/
public:
	std::vector<double> initSystem(D_S_PretreatSystem& DSP); //导入分流后的预处理系统，用于初始化分流后的学生管理系统类
	void initSystem(QString filePath); //用于从文件导入分流后的学生管理系统类
	void saveSystem(QString filePath); //向硬盘中导出分流后的学生管理系统类
	void deleteSystem(); //释放内存空间
	std::vector<D_S_StudentPro> getArray(); //获得学生信息
	D_S_StudentPro getArrayNode(int Pos); //通过下标获得单独学生信息
	D_S_StudentPro getArrayNodeByID(int tmpID); //通过学生的学号获得单独的学生信息
	std::string getMajorName(int Pos); //通过下标获取专业名称
	int getMajorPos(std::string str); //通过专业名称获取对应下标
	std::vector<int> getClassNum(); //获得当前班级人数
	std::pair<int, int> getMajorClassPos(int majorPos); //获得当前专业对应班级的下标
	int getStuNum(); //获得当前全部学生人数'
	bool modifyArrayNodeByID(int tmpID, int majorPos, int classPos); //修改学生信息
	void sortSystem(); //系统排序

	int getClassLeftRange(int x); //线段树中的划分范围函数
	int getMajorLeftRange(int x); //线段树中的划分范围函数
	bool isInit = false; //用于标记当前软件中有无分流后的学生管理系统类

private:
	std::vector<D_S_StudentPro> DSSParray;
	std::vector<std::string> majorName; //专业名字
	std::vector<std::pair<int, int>> maxNum; // first->班级数量，second->班级的最大人数
	std::vector<int> nowMajorNum; //当前专业人数
	std::vector<int> nowClassNum; //当前班级人数
};

struct D_S_S_TreeNode {
	/*
	用于维护线段树的数据节点
	*/
	double GPASum = 0, GPAMax = -1, GPAMin = 10;
	int l = 0, r = 0;
	D_S_S_TreeNode* left = nullptr, * right = nullptr;

	friend std::ostream& operator<<(std::ostream& out, const D_S_S_TreeNode& DSSTN);
};

class D_S_SegmentTree {
	/*
	线段树封装类
	用于维护学生数据的区间特征值
	*/
public:
	void build(D_S_TreatedSystem& DSTS, D_S_S_TreeNode*& x, int l, int r); //建树函数，初始化线段树
	void build(D_S_TreatedSystem& DSTS, int l, int r); //建树函数，初始化线段树
	D_S_S_TreeNode query(D_S_S_TreeNode* x, int l, int r); //查询函数
	D_S_S_TreeNode query(int l, int r); //查询函数

	double getS(int l, int r, double x); //维护方差
	void deleteTree(); //释放内存空间
private:
	D_S_S_TreeNode* root = nullptr;
};
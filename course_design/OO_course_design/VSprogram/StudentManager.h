#pragma once
#include<iostream>
//#include<QDebug>
using namespace std;

class StudentManager;
class Node;
class SSNode;
class SSNodeData;
class StudentList;
class StudentSegment;

//得分点3 自定义类的封装
//得分点7 多文件结构
//得分点21 图形化界面

class CStudent {
public:
	CStudent() {}
	CStudent(int tNum, string tName = "NULL", bool tGender = false, double tMathGrade = 0.0, double tComGrade = 0.0, double tEngGrade = 0.0, double tPhyGrade = 0.0) //得分点2 带缺省形参函数1
		:Num(tNum), Name(tName), Gender(tGender), MathGrade(tMathGrade), ComGrade(tComGrade), EngGrade(tEngGrade), PhyGrade(tPhyGrade) {} //得分点4 构造函数1
	CStudent(CStudent& CS) :Num(CS.Num), Name(CS.Name), Gender(CS.Gender), MathGrade(CS.MathGrade), ComGrade(CS.ComGrade), EngGrade(CS.EngGrade), PhyGrade(CS.PhyGrade) {}
	//得分点5 复制构造函数
	~CStudent() {
		//qDebug() << "CStudent destrcuting";
	} //得分点4 析构函数
	void getInfo(string& name, bool& gender, double& mathgrade, double& comgrade, double& enggrade, double& phygrade);
	void editInfo(string name, bool gender, double mathgrade, double comgrade, double enggrade, double phygrade);
	CStudent& operator++(); //得分点13 运算符重载1
	static long long SumOfStudent; //得分点8 类的静态成员
	static long long getSumOfStudent() { return SumOfStudent; }

	friend StudentManager; //得分点9 友元类
	friend Node;
	friend StudentList;
	friend SSNode;
	friend StudentSegment;
	friend ofstream& operator<<(ofstream& out, CStudent& CS); //得分点13 运算符重载2


private:
	int Num = -1;
	string Name = "NULL";
	bool Gender = false;	//male = true, female = false;
	double MathGrade = 0.0;
	double ComGrade = 0.0;
	double EngGrade = 0.0;
	double PhyGrade = 0.0;
};

struct CStudentArray {
	int* posSt = nullptr;
	CStudent** st = nullptr;
	int cnt = 0;
};

class Node {
public:
	Node() :data(nullptr), next(nullptr) {}

	friend StudentList;
	friend StudentManager;
private:
	CStudent* data;
	Node* next;
};

class StudentList {
public:
	StudentList();
	void initStudentList(StudentManager sm);
	void addList(CStudent tdata);
	bool insertList(long long pos, CStudent tdata);
	bool deleteList(long long pos);
	void freeList();
	long long getListCount();

	friend StudentManager;
private:
	Node* head = nullptr;
	long long cnt = 0;
};

class StudentManager {
public:
	StudentManager() :st(nullptr), cnt(0) {} //得分点4 构造函数2
	void StudentList2Manager(StudentList sl);
	CStudent* queryStudent(long long num = 1); //得分点2 带缺省形参函数2
	CStudentArray queryStudentByName(string tName = "NULL");
	long long getCount();
	string getFilePath() const { return FilePath; } //得分点10 共享数据保护

	void Write(); //得分点17 写文件
	void Read(); //得分点18 读文件

	friend StudentList;
	friend StudentSegment;

private:
	CStudent* st = nullptr;
	long long cnt = 0;
	const string FilePath = "D:/res.txt";
};

class SSNodeDataBase { //得分点15 抽象类
public:
	virtual string queryType() = 0;
};

class SSNodeData :public SSNodeDataBase {
public:
	double MathGradeSum = 0, ComGradeSum = 0, EngGradeSum = 0, PhyGradeSum = 0;
	double MathGradeMax = -1, ComGradeMax = -1, EngGradeMax = -1, PhyGradeMax = -1;
	double MathGradeMin = 200, ComGradeMin = 200, EngGradeMin = 200, PhyGradeMin = 200;
	SSNodeData() :SSNodeDataBase() {}
	string queryType();
	virtual void update(SSNodeData t); //得分点14 虚函数
};

class Range {
public:
	Range(long long ll, long long rr) :l(ll), r(rr) {}
	bool check(long long SumCnt);

	friend SSNode;
	friend StudentSegment;
private:
	long long l;
	long long r;
};

class SSNode :public SSNodeData { //得分点11 继承与派生
public:
	SSNode(long long tl, long long tr) :range(tl, tr), left(nullptr), right(nullptr), SSNodeData() {} //得分点12 派生类构造函数中完成对基类构造函数的调用
	long long mid() { return (range.l + range.r) >> 1; }
	long long len() { return range.r - range.l + 1; }
	SSNodeData SSNode2SSNodeData();
	string queryType();
	virtual void update(SSNodeData t); //得分点14 虚函数

	friend StudentSegment;
private:
	Range range; //得分点6 类的组合
	SSNode* left, * right;
	//SSNodeData data;
};

class StudentSegment {
public:
	void build(StudentManager& sm, SSNode*& x, long long l, long long r);
	void build(StudentManager& sm, long long l, long long r);
	//得分点1 类成员函数重载。
	//void modify(StudentManager& sm, SSNode*& x, long long l, long long r);
	SSNodeData query(SSNode* x, long long l, long long r);
	SSNode*& getRoot();

private:
	SSNode* root;
};

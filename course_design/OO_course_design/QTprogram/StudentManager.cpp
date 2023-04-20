#include<iostream>
#include<fstream>
//#include<QDebug>
#include"StudentManager.h"
using namespace std;

//CStudent:
void CStudent::getInfo(string& name, bool& gender, double& mathgrade, double& comgrade, double& enggrade, double& phygrade) {
	name = Name, gender = Gender, mathgrade = MathGrade, comgrade = ComGrade, enggrade = EngGrade, phygrade = PhyGrade;
	return;
}

void CStudent::editInfo(string name, bool gender, double mathgrade, double comgrade, double enggrade, double phygrade) {
	Name = name, Gender = gender, MathGrade = mathgrade, ComGrade = comgrade, EngGrade = enggrade, PhyGrade = phygrade;
	return;
}

CStudent& CStudent::operator++() {
	this->Num += 1;
	return *this;
}

ofstream& operator<<(ofstream& out, CStudent& CS) {
	out << CS.Num << ' ' << CS.Name << ' ' << CS.Gender << ' ' << CS.MathGrade << ' ' << CS.ComGrade << ' ' << CS.EngGrade << ' ' << CS.PhyGrade;
	return out;
}

//StudentList:

StudentList::StudentList() {
	this->head = new Node;
	this->cnt = 0;
}

void StudentList::initStudentList(StudentManager sm) {
	this->cnt = sm.cnt;
	Node* now = this->head;
	for (int i = 0; i < sm.cnt; i++) {
		CStudent* newStudent = new CStudent(*(sm.st + i));
		if (i == sm.cnt - 1) {
			now->data = newStudent;
			now->next = nullptr;
		}
		else {
			Node* newNode = new Node;
			now->data = newStudent;
			now->next = newNode;
			now = now->next;
		}
	}
}

void StudentList::addList(CStudent tdata) {
	CStudent* data = new CStudent(tdata);
	if (cnt == 0) {
		head->data = data;
		CStudent::SumOfStudent++;
		(this->cnt)++;
	}
	else {
		Node* tmp = this->head;
		while (tmp->next != nullptr) tmp = tmp->next;
		Node* newNode = new Node;
		tmp->next = newNode;
		newNode->data = data;
		CStudent::SumOfStudent++;
		(this->cnt)++;
	}
}

bool StudentList::insertList(long long pos, CStudent tdata) {
    CStudent* data = new CStudent(tdata);
	Node* tmp = this->head;
    if(cnt == 0){
        return false;
    }
    while (tmp != nullptr) {
		if (tmp->data->Num == pos) {
			Node* newNode = new Node;
            newNode->next = tmp->next;
			tmp->next = newNode;
			newNode->data = data;
			(this->cnt)++;
			return true;
		}
        tmp = tmp->next;
	}
	return false;
}

bool StudentList::deleteList(long long pos) {

	if (cnt == 0) {
		return false;
	}
	else if (cnt == 1) {
		if (head->data->Num == pos) {
			CStudent::SumOfStudent = 0;
			cnt = 0;
			return true;
		}
		else return false;
	}
	else if (head->data->Num == pos) {
		Node* pre = head;
		head = head->next;
		delete pre->data;
		delete pre;
		CStudent::SumOfStudent--;
		cnt--;
		return true;
	}
	else {
		Node* now = head->next, * pre = head;
		while (now != nullptr) {
			if (now->data->Num == pos) {
				pre->next = now->next;
				delete now->data;
				delete now;
				CStudent::SumOfStudent--;
				cnt--;
				return true;
			}
			pre = pre->next;
			now = now->next;
		}
		return false;
	}
}

void StudentList::freeList() {
	Node* tmp = head;
	while (tmp != nullptr) {
		head = head->next;
		delete tmp->data;
		delete tmp;
		tmp = head;
	}
	cnt = 0;
	head = new Node;
	return;
}

long long StudentList::getListCount() {
	return this->cnt;
}

//StudentManager:

long long CStudent::SumOfStudent = 0;

void StudentManager::StudentList2Manager(StudentList sl) {
	if (sl.cnt == 0) return;
	CStudent* newSt = new CStudent[sl.cnt];
	int nowNum = 0;
	Node* now = sl.head;
	while (now != nullptr) {
		*(newSt + nowNum) = *(now->data);
		(newSt + nowNum)->Num = nowNum + 1;
		nowNum++;
		now = now->next;
	}
	delete[] this->st;
	this->st = newSt;
	this->cnt = sl.cnt;
}

CStudent* StudentManager::queryStudent(long long tNum) {
	for (int i = 0; i < cnt; i++) if ((st + i)->Num == tNum) return (st + i);
	return nullptr;
}

CStudentArray StudentManager::queryStudentByName(string tName) {
    CStudentArray CSA;
    for (int i = 0; i < cnt; i++) {
        //qDebug() << QString::fromStdString((st + i)->Name);
        //qDebug() << QString::fromStdString(tName);
        if ((st + i)->Name == tName){
            if(CSA.cnt != 0){
                int * posPre = CSA.posSt;
                CSA.posSt = new int[CSA.cnt + 1];
                for(int i = 0;i < CSA.cnt; i++) *(CSA.posSt+i) = *(posPre+i);
                *(CSA.posSt + CSA.cnt) = i + 1;
                CStudent ** pre = CSA.st;
                CSA.st = new CStudent*[CSA.cnt + 1];
                for(int i = 0;i < CSA.cnt; i++) *(CSA.st+i) = *(pre+i);
                *(CSA.st + CSA.cnt) = (st + i);
                CSA.cnt++;
                delete[] posPre;
                delete[] pre;
            }else{
                CSA.posSt = new int[1];
                *CSA.posSt = i + 1;
                CSA.st = new CStudent*[1];
                *CSA.st = (st + i);
                CSA.cnt++;
            }
        }}
    return CSA;
}

CStudentArray StudentManager::queryStudentByGradeAndGender(double tGrade, bool tGender) {
    CStudentArray CSA;
    for (int i = 0; i < cnt; i++) {
        double SumGrade = (st + i)->MathGrade + (st + i)->ComGrade + (st + i)->EngGrade + (st + i)->PhyGrade;
        if (SumGrade >= tGrade && (st + i)->Gender == tGender){
            if(CSA.cnt != 0){
                int * posPre = CSA.posSt;
                CSA.posSt = new int[CSA.cnt + 1];
                for(int i = 0;i < CSA.cnt; i++) *(CSA.posSt+i) = *(posPre+i);
                *(CSA.posSt + CSA.cnt) = i + 1;
                CStudent ** pre = CSA.st;
                CSA.st = new CStudent*[CSA.cnt + 1];
                for(int i = 0;i < CSA.cnt; i++) *(CSA.st+i) = *(pre+i);
                *(CSA.st + CSA.cnt) = (st + i);
                CSA.cnt++;
                delete[] posPre;
                delete[] pre;
            }else{
                CSA.posSt = new int[1];
                *CSA.posSt = i + 1;
                CSA.st = new CStudent*[1];
                *CSA.st = (st + i);
                CSA.cnt++;
            }
        }}
    return CSA;
}

long long StudentManager::getCount() {
	return this->cnt;
}

void StudentManager::Write() {
	ofstream out;
	out.open("D:/res.txt");
	out << cnt << '\n';
	for (int i = 0; i < cnt; i++) {
		CStudent* p = st + i;
		out << p->Num << ' ' << p->Name << ' ' << p->Gender << ' ' << p->MathGrade << ' ' << p->ComGrade << ' ' << p->EngGrade << ' ' << p->PhyGrade << '\n';
	}
	out.close();
}

void StudentManager::Read() {
	ifstream in;
	in.open("D:/res.txt");
	in >> cnt;
	CStudent::SumOfStudent += cnt;
	st = new CStudent[cnt];
	for (int i = 0; i < cnt; i++) {
		CStudent* p = st + i;
		in >> p->Num >> p->Name >> p->Gender >> p->MathGrade >> p->ComGrade >> p->EngGrade >> p->PhyGrade;
	}
	in.close();
}

//SSNodeData:

string SSNodeData::queryType() {
	return "SSNodeData Type";
}

void SSNodeData::update(SSNodeData t) {
	MathGradeSum += t.MathGradeSum;
	MathGradeMax = max(MathGradeMax, t.MathGradeMax);
	MathGradeMin = min(MathGradeMin, t.MathGradeMin);
	ComGradeSum += t.ComGradeSum;
	ComGradeMax = max(ComGradeMax, t.ComGradeMax);
	ComGradeMin = min(ComGradeMin, t.ComGradeMin);
	EngGradeSum += t.EngGradeSum;
	EngGradeMax = max(EngGradeMax, t.EngGradeMax);
	EngGradeMin = min(EngGradeMin, t.EngGradeMin);
	PhyGradeSum += t.PhyGradeSum;
	PhyGradeMax = max(PhyGradeMax, t.PhyGradeMax);
	PhyGradeMin = min(PhyGradeMin, t.PhyGradeMin);
}

//SSNode:

string SSNode::queryType() {
	return "SSNode Type";
}

void SSNode::update(SSNodeData t) {
	MathGradeSum = left->MathGradeSum + right->MathGradeSum;
	ComGradeSum = left->ComGradeSum + right->ComGradeSum;
	EngGradeSum = left->EngGradeSum + right->EngGradeSum;
	PhyGradeSum = left->PhyGradeSum + right->PhyGradeSum;
	MathGradeMax = max(left->MathGradeMax, right->MathGradeMax);
	ComGradeMax = max(left->ComGradeMax, right->ComGradeMax);
	EngGradeMax = max(left->EngGradeMax, right->EngGradeMax);
	PhyGradeMax = max(left->PhyGradeMax, right->PhyGradeMax);
	MathGradeMin = min(left->MathGradeMin, right->MathGradeMin);
	ComGradeMin = min(left->ComGradeMin, right->ComGradeMin);
	EngGradeMin = min(left->EngGradeMin, right->EngGradeMin);
	PhyGradeMin = min(left->PhyGradeMin, right->PhyGradeMin);
}

SSNodeData SSNode::SSNode2SSNodeData() {
	SSNodeData res;
	res.MathGradeSum = MathGradeSum;
	res.MathGradeMax = MathGradeMax;
	res.MathGradeMin = MathGradeMin;
	res.ComGradeSum = ComGradeSum;
	res.ComGradeMax = ComGradeMax;
	res.ComGradeMin = ComGradeMin;
	res.EngGradeSum = EngGradeSum;
	res.EngGradeMax = EngGradeMax;
	res.EngGradeMin = EngGradeMin;
	res.PhyGradeSum = PhyGradeSum;
	res.PhyGradeMax = PhyGradeMax;
	res.PhyGradeMin = PhyGradeMin;
	return res;
}

//StudentSegment:

void StudentSegment::build(StudentManager& sm, SSNode*& x, long long l, long long r) {
	x = new SSNode(l, r);
    SSNodeData tmp;
	if (l == r) {
        x->MathGradeSum = (sm.st + l - 1)->MathGrade;
        x->MathGradeMax = (sm.st + l - 1)->MathGrade;
        x->MathGradeMin = (sm.st + l - 1)->MathGrade;
        x->ComGradeSum = (sm.st + l - 1)->ComGrade;
        x->ComGradeMax = (sm.st + l - 1)->ComGrade;
        x->ComGradeMin = (sm.st + l - 1)->ComGrade;
        x->EngGradeSum = (sm.st + l - 1)->EngGrade;
        x->EngGradeMax = (sm.st + l - 1)->EngGrade;
        x->EngGradeMin = (sm.st + l - 1)->EngGrade;
        x->PhyGradeSum = (sm.st + l - 1)->PhyGrade;
        x->PhyGradeMax = (sm.st + l - 1)->PhyGrade;
        x->PhyGradeMin = (sm.st + l - 1)->PhyGrade;
		return;
	}
	build(sm, x->left, l, x->mid());
	build(sm, x->right, x->mid() + 1, r);
    SSNodeData *p = x;
    p->update(tmp);
}

void StudentSegment::build(StudentManager& sm, long long l, long long r) {
	root = new SSNode(l, r);
	SSNodeData tmp;
	if (l == r) {
		root->MathGradeSum = (sm.st + l - 1)->MathGrade;
		root->MathGradeMax = (sm.st + l - 1)->MathGrade;
		root->MathGradeMin = (sm.st + l - 1)->MathGrade;
		root->ComGradeSum = (sm.st + l - 1)->ComGrade;
		root->ComGradeMax = (sm.st + l - 1)->ComGrade;
		root->ComGradeMin = (sm.st + l - 1)->ComGrade;
		root->EngGradeSum = (sm.st + l - 1)->EngGrade;
		root->EngGradeMax = (sm.st + l - 1)->EngGrade;
		root->EngGradeMin = (sm.st + l - 1)->EngGrade;
		root->PhyGradeSum = (sm.st + l - 1)->PhyGrade;
		root->PhyGradeMax = (sm.st + l - 1)->PhyGrade;
		root->PhyGradeMin = (sm.st + l - 1)->PhyGrade;
		return;
	}
	build(sm, root->left, l, root->mid());
	build(sm, root->right, root->mid() + 1, r);
	SSNodeData* p = root;
	p->update(tmp);
}

SSNodeData StudentSegment::query(SSNode* x, long long l, long long r, long long SumCnt) {
    if (r < l) throw 1;
    else if (r == 0 || l == 0) throw 'a';
    else if (l < 1 || r > SumCnt) throw 2.0;

	if (l <= x->range.l && r >= x->range.r) return x->SSNode2SSNodeData();
	SSNodeData res;
    if (l <= x->mid()) res.update(query(x->left, l, r, SumCnt));
    if (r >= x->mid() + 1) res.update(query(x->right, l, r, SumCnt));
	return res;
}

SSNode*& StudentSegment::getRoot() {
	return root;
}

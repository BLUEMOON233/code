/*********************************************************
 * 版权：长安大学
 * 编写者：刘文越，王子卓，肖芷馨，孙翔，康旭
 *
 * 编写时间：2022/12/06
 * 功能描述：DivergenceSystem头文件中所有函数的实现
**********************************************************/
#include "DivergenceSystem.h"
#include <ctime>
#include <algorithm>

//Fuctions:

void string_split(const std::string& str, const std::string& split, std::vector<int>& rs) {
	char* Cstr = new char[str.size() + 1];
	strcpy(Cstr, str.c_str());
	char* temp = strtok(Cstr, split.c_str());
	while (temp != NULL) {
		rs.push_back(stoi(std::string(temp)));
		temp = strtok(NULL, split.c_str());
	}
	delete[] Cstr;
}

void string_split(const std::string& str, const std::string& split, std::vector<std::string>& rs) {
	char* Cstr = new char[str.size() + 1];
	strcpy(Cstr, str.c_str());
	char* temp = strtok(Cstr, split.c_str());
	while (temp != NULL) {
		rs.push_back(std::string(temp));
		temp = strtok(NULL, split.c_str());
	}
	delete[] Cstr;
}

//D_S_Student:

std::istream& operator>>(std::istream& in, D_S_Student& DSS) {
	in >> DSS.ID >> DSS.choice >> DSS.GPA >> DSS.rank;
	return in;
}

std::ostream& operator<< (std::ostream& out, const D_S_Student& DSS) {
	out << "test: " << DSS.ID << ' ' << DSS.choice << ' ' << DSS.GPA << ' ' << DSS.rank << '\n';
	return out;
}

//D_S_MajorList:

D_S_MajorList::D_S_MajorList() {
	head = new D_S_DeLinkedListNode;
	tail = new D_S_DeLinkedListNode;
	this->head->nex = tail;
	this->tail->pre = head;
}

D_S_MajorList::~D_S_MajorList() {
	//D_S_DeLinkedListNode* now = this->head, * lst = nullptr;
	//while (now) {
	//	lst = now;
	//	now = now->nex;
	//	delete lst;
	//}
}

void D_S_MajorList::deleteMajorList() {
	D_S_DeLinkedListNode* now = this->head->nex, * lst = nullptr;
	while (now != this->tail) {
		lst = now;
		now = now->nex;
		delete lst;
	}
}

void D_S_MajorList::printList() {
	D_S_DeLinkedListNode* now = this->head->nex;
	while (now != this->tail) {
		std::cout << now->data;
		now = now->nex;
	}
}

void D_S_MajorList::initList(std::string filePath) {
	D_S_Student now;
	std::ifstream fin(filePath, std::ios::in);
	if (!fin) {
		std::cout << "Failed to open the file !\n";
		return;
	}
	std::string str;
	fin >> str >> str >> str >> str;
	while (fin >> now.ID) {
		fin >> str;
		if (str == "第一志愿") now.choice = 1;
		else if (str == "第二志愿") now.choice = 2;
		else if (str == "第三志愿") now.choice = 3;
		else if (str == "第四志愿") now.choice = 4;
		else if (str == "第五志愿") now.choice = 5;
		else now.choice = 0;
		fin >> now.GPA >> now.rank;
		D_S_DeLinkedListNode* nowptr = new D_S_DeLinkedListNode;
		nowptr->data = now;
		nowptr->nex = this->tail, nowptr->pre = this->tail->pre;
		this->tail->pre->nex = nowptr, this->tail->pre = nowptr;
		this->nodeNum++;
	}
}

void D_S_MajorList::addNode(D_S_Student DSS) {
	D_S_DeLinkedListNode* nowptr = new D_S_DeLinkedListNode;
	nowptr->data = DSS;
	nowptr->nex = this->tail, nowptr->pre = this->tail->pre;
	this->tail->pre->nex = nowptr, this->tail->pre = nowptr;
	this->nodeNum++;
}

void D_S_MajorList::setListName(std::string name) {
	this->majorName = name;
}

int D_S_MajorList::getNodeNum() {
	return this->nodeNum;
}

//D_S_PretreatSystem:

void D_S_PretreatSystem::initSystem() {
	for (int i = 0; i < this->listNum; i++) this->MajorList[i].deleteMajorList();
	this->MajorList.clear();
	this->mp.clear();
	this->listNum = 0;
}

int D_S_PretreatSystem::addMajorList(std::string filePath, std::string majorName, std::pair<int, int> pairNum) {
	D_S_MajorList DSM;
	DSM.initList(filePath);
	DSM.setListName(majorName);
	DSM.maxNum = pairNum;
	this->MajorList.push_back(DSM);
	this->listNum++;
	return DSM.getNodeNum();
}

D_S_Student D_S_PretreatSystem::getNodeByPos(int pos1, int pos2) {
	D_S_DeLinkedListNode* now = this->MajorList[pos1 - 1].head->nex;
	int posCnt = 0;
	while (now != this->MajorList[pos1 - 1].tail) {
		if (++posCnt == pos2) return now->data;
		else now = now->nex;
	}
}

int D_S_PretreatSystem::getListNum() {
	return this->listNum;
}

int D_S_PretreatSystem::getListNodeNum(int cnt) {
	return this->MajorList[cnt - 1].getNodeNum();
}

int D_S_PretreatSystem::getSumNum() {
	int rs = 0;
	for (int i = 0; i < this->listNum; i++) {
		D_S_DeLinkedListNode* now = this->MajorList[i].head->nex;
		while (now != this->MajorList[i].tail) {
			if (!mp[now->data.ID]) rs++, mp[now->data.ID] = true;
			now = now->nex;
		}
	}
	mp.clear();
	return rs;
}

//D_S_StudentPro:

std::istream& operator>>(std::istream& in, D_S_StudentPro& DSSP) {
	in >> DSSP.choice[0].first >> DSSP.choice[0].second >> DSSP.rank >> DSSP.ID >> DSSP.GPA;
	return in;
}

std::ostream& operator<<(std::ostream& out, const D_S_StudentPro& DSSP) {
	out << DSSP.choice[0].first << ' ' << DSSP.choice[0].second << ' ' << DSSP.rank << ' ' << DSSP.ID << ' ' << DSSP.GPA << '\n';
	return out;
}

//D_S_TreatedSystem:

std::vector<double> D_S_TreatedSystem::initSystem(D_S_PretreatSystem& DSP) {
	//分流操作：
	int sumNum = DSP.getSumNum(), nowPos = 1;
	std::map<int, int> ID2Pos;
	D_S_StudentPro fir;
	fir.choice.push_back({ 0, 0 });
	DSSParray.push_back(fir);
	for (int i = 0; i < DSP.getListNum(); i++) {
		D_S_DeLinkedListNode* now = DSP.MajorList[i].head->nex;
		while (now != DSP.MajorList[i].tail) {
			if (!ID2Pos[now->data.ID]) {
				ID2Pos[now->data.ID] = DSSParray.size();
				D_S_StudentPro DSSP;
				DSSP.ID = now->data.ID, DSSP.GPA = now->data.GPA, DSSP.rank = now->data.rank;
				DSSP.choice.push_back({ now->data.choice, i + 1 });
				DSSParray.push_back(DSSP);
			}
			else DSSParray[ID2Pos[now->data.ID]].choice.push_back({ now->data.choice, i + 1 });
			now = now->nex;
		}
	}
	for (auto& x : this->DSSParray) std::sort(x.choice.begin(), x.choice.end());
	std::sort(DSSParray.begin(), DSSParray.end(), [](D_S_StudentPro& a, D_S_StudentPro& b) {
		return a.rank < b.rank;
		});
	for (int i = 0; i < DSP.getListNum(); i++) this->majorName.push_back(DSP.MajorList[i].majorName);
	for (int i = 0; i < DSP.getListNum(); i++) this->maxNum.push_back(DSP.MajorList[i].maxNum);
	for (int i = 0; i < DSP.getListNum(); i++) nowMajorNum.push_back(0);
	for (int i = 0; i < DSP.getListNum(); i++) for (int j = 0; j < DSP.MajorList[i].maxNum.first; j++) nowClassNum.push_back(0);
	while (nowPos < DSSParray.size()) {
		bool flag = true;
		std::vector<bool> st(DSP.getListNum(), false);
		for (int i = 0; i < DSP.getListNum(); i++) if (maxNum[i].first * maxNum[i].second > nowMajorNum[i]) st[i] = true;
		while (flag) {
			flag = false;
			int defChoice = -1;
			for (auto& x : DSSParray[nowPos].choice) if (st[x.second - 1]) {
				nowMajorNum[x.second - 1]++;
				defChoice = x.second;
				break;
			}
			DSSParray[nowPos].choice.clear();
			if (defChoice != -1) DSSParray[nowPos].choice.push_back({ defChoice, 0 });
			if (nowPos != DSSParray.size() - 1 && DSSParray[nowPos].rank == DSSParray[nowPos + 1].rank) flag = true;
			nowPos++;
		}
	}
	for (int i = 1; i < DSSParray.size(); i++) if (DSSParray[i].choice.size() == 0) {
		int minPos = -1, minNum = 0x3f3f3f3f;
		for (int j = 0; j < DSP.getListNum(); j++) if (minNum > nowMajorNum[j]) minNum = nowMajorNum[j], minPos = j;
		DSSParray[i].choice.push_back({ minPos + 1, 0 });
		nowMajorNum[minPos]++;
	}

	//分班操作：
	srand(unsigned(time(nullptr)));
	std::vector<int> classID;
	int startPos = 1, randStartPos = 0;
	for (int i = 0; i < DSP.getListNum(); i++) {
		for (int j = 1; j <= nowMajorNum[i]; j++) {
			classID.push_back(j % maxNum[i].first + startPos);
			nowClassNum[j % maxNum[i].first + startPos - 1]++;
		}
		std::random_shuffle(classID.begin() + randStartPos, classID.end());
		startPos += maxNum[i].first, randStartPos += nowMajorNum[i];
	}
	sort(DSSParray.begin() + 1, DSSParray.end(), [](D_S_StudentPro& a, D_S_StudentPro& b) {
		return a.choice[0].first < b.choice[0].first;
		});
	for (int i = 1; i < DSSParray.size(); i++) DSSParray[i].choice[0].second = classID[i - 1];
	sort(DSSParray.begin() + 1, DSSParray.end(), [](D_S_StudentPro& a, D_S_StudentPro& b) {
		if (a.choice[0].second != b.choice[0].second) return a.choice[0].second < b.choice[0].second;
		else return a.rank < b.rank;
		});
	int classSum = 0;
	for (int i = 0; i < DSP.getListNum(); i++) classSum += maxNum[i].first;
	std::vector<double> classGrade(classSum, 0.0);
	std::vector<int> classNum(classSum, 0);
	for (int i = 1; i < DSSParray.size(); i++) {
		classGrade[DSSParray[i].choice[0].second - 1] += DSSParray[i].GPA;
		classNum[DSSParray[i].choice[0].second - 1]++;
	}
	for (int i = 0; i < classSum; i++) classGrade[i] /= double(classNum[i]);
	this->isInit = true;
	return classGrade;
}

void D_S_TreatedSystem::initSystem(QString filePath) {
	this->isInit = true;
	std::ifstream fcin(filePath.toStdString());
	int Size = 0;
	fcin >> Size;
	while (Size--) {
		D_S_StudentPro now;
		std::pair<int, int> nowPair;
		fcin >> nowPair.first >> nowPair.second >> now.rank >> now.ID >> now.GPA;
		now.choice.push_back(nowPair);
		this->DSSParray.push_back(now);
	}
	fcin >> Size;
	while (Size--) {
		std::string now;
		fcin >> now;
		this->majorName.push_back(now);
	}
	fcin >> Size;
	while (Size--) {
		std::pair<int, int> now;
		fcin >> now.first >> now.second;
		this->maxNum.push_back(now);
	}
	fcin >> Size;
	while (Size--) {
		int now;
		fcin >> now;
		this->nowMajorNum.push_back(now);
	}
	fcin >> Size;
	while (Size--) {
		int now;
		fcin >> now;
		this->nowClassNum.push_back(now);
	}
	fcin.close();
}

void D_S_TreatedSystem::saveSystem(QString filePath) {
	filePath += "/DivergenceSystemDataFile.txt";
	std::ofstream fout(std::string(filePath.toLocal8Bit()));
	fout << this->DSSParray.size() << '\n';
	for (auto& x : this->DSSParray) fout << x;
	fout << this->majorName.size() << '\n';
	for (auto& x : this->majorName) fout << x << '\n';
	fout << this->maxNum.size() << '\n';
	for (auto& x : this->maxNum) fout << x.first << ' ' << x.second << '\n';
	fout << this->nowMajorNum.size() << '\n';
	for (auto& x : this->nowMajorNum) fout << x << '\n';
	fout << this->nowClassNum.size() << '\n';
	for (auto& x : this->nowClassNum) fout << x << '\n';
	fout.close();
}

void D_S_TreatedSystem::deleteSystem() {
	this->isInit = false;
	this->DSSParray.clear();
	this->majorName.clear();
	this->maxNum.clear();
	this->nowMajorNum.clear();
	this->nowClassNum.clear();
}

std::vector<D_S_StudentPro> D_S_TreatedSystem::getArray() {
	std::vector<D_S_StudentPro> rs;
	for (int i = 1; i < this->DSSParray.size(); i++) rs.push_back(DSSParray[i]);
	return rs;
}

D_S_StudentPro D_S_TreatedSystem::getArrayNode(int Pos) {
	return this->DSSParray[Pos];
}

D_S_StudentPro D_S_TreatedSystem::getArrayNodeByID(int tmpID) {
	for (auto& x : this->DSSParray) if (x.ID == tmpID) return x;
	return DSSParray[0];
}

std::string D_S_TreatedSystem::getMajorName(int pos) {
	return majorName[pos - 1];
}

int D_S_TreatedSystem::getMajorPos(std::string str) {
	for (int i = 0; i < this->majorName.size(); i++) if (this->majorName[i] == str) return i + 1;
	return 0;
}

std::vector<int> D_S_TreatedSystem::getClassNum() {
	std::vector<int> rs;
	for (auto& x : this->maxNum) rs.push_back(x.first);
	return rs;
}

std::pair<int, int> D_S_TreatedSystem::getMajorClassPos(int majorPos) {
	std::pair<int, int> rs = { 0, -1 };
	for (int i = 0; i < majorPos - 1; i++) rs.first += this->maxNum[i].first;
	rs.second = maxNum[majorPos - 1].first;
	return rs;
}

int D_S_TreatedSystem::getStuNum() {
	int rs = 0;
	for (auto& x : nowMajorNum) rs += x;
	return rs;
}

bool D_S_TreatedSystem::modifyArrayNodeByID(int tmpID, int majorPos, int classPos) {
	for (auto& x : this->DSSParray) if (x.ID == tmpID) {
		x.choice[0].first = majorPos, x.choice[0].second = classPos;
		return true;
	}
	return false;
}

void D_S_TreatedSystem::sortSystem() {
	sort(DSSParray.begin() + 1, DSSParray.end(), [](D_S_StudentPro& a, D_S_StudentPro& b) {
		if (a.choice[0].first != b.choice[0].first) return a.choice[0].first < b.choice[0].first;
		else if (a.choice[0].second != b.choice[0].second) return a.choice[0].second < b.choice[0].second;
		else return a.rank < b.rank;
		});
}

int D_S_TreatedSystem::getClassLeftRange(int x) {
	int rs = 0;
	for (int i = 0; i < x - 1; i++) rs += this->nowClassNum[i];
	return rs;
}

int D_S_TreatedSystem::getMajorLeftRange(int x) {
	int rs = 0;
	for (int i = 0; i < x - 1; i++) rs += this->nowMajorNum[i];
	return rs;
}

void pushup(D_S_S_TreeNode*& x) {
	x->GPASum = x->left->GPASum + x->right->GPASum;
	x->GPAMax = std::max(x->left->GPAMax, x->right->GPAMax);
	x->GPAMin = std::min(x->left->GPAMin, x->right->GPAMin);
}

void deleteNode(D_S_S_TreeNode*& x) {
	if (x->left != nullptr) deleteNode(x->left);
	if (x->right != nullptr) deleteNode(x->right);
	delete x;
}

//D_S_S_TreeNode:

std::ostream& operator<<(std::ostream& out, const D_S_S_TreeNode& DSSTN) {
	out << DSSTN.GPASum << ' ' << DSSTN.GPAMax << ' ' << DSSTN.GPAMin << '\n';
	return out;
}

//D_S_SegmentTree:

void D_S_SegmentTree::build(D_S_TreatedSystem& DSTS, int l, int r) {
	if (r == 0) return;
	root = new D_S_S_TreeNode;
	root->l = l, root->r = r;
	if (l == r) {
		root->GPASum = DSTS.getArrayNode(l).GPA;
		root->GPAMin = DSTS.getArrayNode(l).GPA;
		root->GPAMax = DSTS.getArrayNode(l).GPA;
	}
	else {
		int mid = l + r >> 1;
		build(DSTS, root->left, l, mid);
		build(DSTS, root->right, mid + 1, r);
		pushup(root);
	}
}

void D_S_SegmentTree::build(D_S_TreatedSystem& DSTS, D_S_S_TreeNode*& x, int l, int r) {
	x = new D_S_S_TreeNode;
	x->l = l, x->r = r;
	if (l == r) {
		x->GPASum = DSTS.getArrayNode(l).GPA;
		x->GPAMin = DSTS.getArrayNode(l).GPA;
		x->GPAMax = DSTS.getArrayNode(l).GPA;
	}
	else {
		int mid = l + r >> 1;
		build(DSTS, x->left, l, mid);
		build(DSTS, x->right, mid + 1, r);
		pushup(x);
	}
}

D_S_S_TreeNode D_S_SegmentTree::query(D_S_S_TreeNode* x, int l, int r) {
	if (l <= x->l && r >= x->r) return *x;
	D_S_S_TreeNode rs, son;
	int mid = x->l + x->r >> 1;
	if (l <= mid) {
		son = query(x->left, l, r);
		rs.GPASum += son.GPASum;
		rs.GPAMax = std::max(rs.GPAMax, son.GPAMax);
		rs.GPAMin = std::min(rs.GPAMin, son.GPAMin);
	}
	if (r > mid) {
		son = query(x->right, l, r);
		rs.GPASum += son.GPASum;
		rs.GPAMax = std::max(rs.GPAMax, son.GPAMax);
		rs.GPAMin = std::min(rs.GPAMin, son.GPAMin);
	}
	return rs;
}

D_S_S_TreeNode D_S_SegmentTree::query(int l, int r) {
	if (l <= this->root->l && r >= this->root->r) return *(this->root);
	D_S_S_TreeNode rs, son;
	int mid = this->root->l + this->root->r >> 1;
	if (l <= mid) {
		son = query(this->root->left, l, r);
		rs.GPASum += son.GPASum;
		rs.GPAMax = std::max(rs.GPAMax, son.GPAMax);
		rs.GPAMin = std::min(rs.GPAMin, son.GPAMin);
	}
	if (r > mid) {
		son = query(this->root->right, l, r);
		rs.GPASum += son.GPASum;
		rs.GPAMax = std::max(rs.GPAMax, son.GPAMax);
		rs.GPAMin = std::min(rs.GPAMin, son.GPAMin);
	}
	return rs;
}

double D_S_SegmentTree::getS(int l, int r, double x) {
	double Sum = 0;
	for (int i = l; i <= r; i++) Sum += (this->query(i, i).GPASum - x) * (this->query(i, i).GPASum - x);
	return Sum / double(r - l + 1);
}

void D_S_SegmentTree::deleteTree() {
	deleteNode(this->root);
	this->root = nullptr;
}
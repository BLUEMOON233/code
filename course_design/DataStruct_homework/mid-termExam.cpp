#include <windows.h>

#include <algorithm>
#include <ctime>
#include <iostream>

template <class Element>
struct DeNode;

template <class Element>
class DeLinkList;

template <class Element>
DeNode<Element>* Locate(DeLinkList<Element>& L, Element x);

//[struct]:Node
template <class Element>
struct Node {
    Element data;
    Node<Element>* p;
};

//[class]:LinkList
template <class Element>
class LinkList {
   public:
    LinkList();
    LinkList(Element initElement[], int n);
    ~LinkList();
    bool Empty();
    void printListByRow();
    void printListByColumn();
    void reverse();
    void Insert(int i, Element x);
    Element Delete(int i);
    int getLength();
    Element findbyIndex(int i);
    LinkList<Element> findbyName(std::string tName);
    LinkList<Element> findbyID(int tID);
    LinkList<Element> findbyGender(std::string tGender);

    void sortBySp1();
    void sortBySp2();
    void Merge(LinkList<Element>& x);

   private:
    Node<Element>* head = nullptr;
    int size = -1;
};

//[struct]:DeNode
template <class Element>
struct DeNode {
    Element data;
    DeNode<Element>* pre;
    DeNode<Element>* nex;
    int fre = 0;
};

//[class]:DeLinkList
template <class Element>
class DeLinkList {
   public:
    DeLinkList();
    DeLinkList(Element initElement[], int n);
    ~DeLinkList();
    void printListByRow();
    friend DeNode<Element>* Locate<Element>(DeLinkList<Element>& L, Element x);

   private:
    DeNode<Element>*head = nullptr, *tail = nullptr;
    int size = -1;
};

template <class Element>
LinkList<Element>::LinkList() {
    this->head = new Node<Element>;
    this->head->p = nullptr;
    this->size = 0;
}

template <class Element>
LinkList<Element>::LinkList(Element initElement[], int n) {
    this->size = n;
    this->head = new Node<Element>;
    if (n == 0) this->head->p = nullptr;
    else {
        Node<Element>* now = this->head;
        for (int i = 1; i <= n; i++) {
            Node<Element>* tmp = new Node<Element>;
            tmp->data = initElement[i - 1], now->p = tmp, now = tmp;
        }
        now->p = nullptr;
    }
}

template <class Element>
LinkList<Element>::~LinkList() {
    Node<Element>* now = this->head;
    while (now) {
        Node<Element>* p = now;
        now = now->p;
        delete p;
    }
}

template <class Element>
bool LinkList<Element>::Empty() {
    if (this->head->p == nullptr) return true;
    else return false;
}

template <class Element>
void LinkList<Element>::printListByRow() {
    Node<Element>* now = this->head->p;
    if (this->getLength() == 0) std::cout << "No data！\n";
    else {
        while (now != nullptr) {
            std::cout << now->data << ' ';
            now = now->p;
        }
    }
    std::cout << '\n';
}

template <class Element>
void LinkList<Element>::printListByColumn() {
    Node<Element>* now = this->head->p;
    if (this->getLength() == 0) std::cout << "No data！\n";
    else {
        while (now != nullptr) {
            std::cout << now->data << '\n';
            now = now->p;
        }
    }
}

template <class Element>
void LinkList<Element>::Insert(int i, Element x) {
    Node<Element>*now = this->head, *tmp = nullptr;
    int cnt = 0;
    while (now != nullptr && cnt < i - 1) now = now->p, cnt++;
    if (now == nullptr) throw "Wrong Position of Insert";
    else {
        tmp = new Node<Element>;
        tmp->data = x, tmp->p = now->p, now->p = tmp, this->size++;
    }
}

template <class Element>
Element LinkList<Element>::Delete(int i) {
    Node<Element>*now = this->head, *p = nullptr;
    int cnt = 0;
    while (now != nullptr && cnt < i - 1) now = now->p, cnt++;
    if (now == nullptr) throw "Wrong Position of Delete";
    else {
        p = now->p;
        Element tmp = p->data;
        now->p = p->p;
        delete p;
        this->size--;
        return tmp;
    }
}

template <class Element>
int LinkList<Element>::getLength() {
    return this->size;
}

template <class Element>
Element LinkList<Element>::findbyIndex(int i) {
    Node<Element>* now = this->head;
    int cnt = 0;
    while (now != nullptr && cnt < i) now = now->p, cnt++;
    if (now == nullptr) throw "Wrong Position of FindbyIndex";
    else return now->data;
}

template <class Element>
LinkList<Element> LinkList<Element>::findbyName(std::string tName) {
    LinkList<Element> tmpll;
    Node<Element>* now = this->head;
    while (now != nullptr) {
        if (now->data.getName() == tName) tmpll.Insert(tmpll.getLength(), now->data);
        now = now->p;
    }
    return tmpll;
}

template <class Element>
LinkList<Element> LinkList<Element>::findbyID(int tID) {
    LinkList<Element> tmpll;
    Node<Element>* now = this->head;
    while (now != nullptr) {
        if (now->data.getID() == tID) tmpll.Insert(tmpll.getLength(), now->data);
        now = now->p;
    }
    return tmpll;
}

template <class Element>
LinkList<Element> LinkList<Element>::findbyGender(std::string tGender) {
    LinkList<Element> tmpll;
    Node<Element>* now = this->head;
    while (now != nullptr) {
        if (now->data.getGender() == tGender) tmpll.Insert(tmpll.getLength(), now->data);
        now = now->p;
    }
    return tmpll;
}

template <class Element>
void LinkList<Element>::reverse() {
    Node<Element>*pre = nullptr, *now = head->p, *nex = nullptr;
    while (now) {
        nex = now->p, now->p = pre, pre = now, now = nex;
        if (now == nullptr) head->p = pre;
    }
}

template <class Element>
void LinkList<Element>::sortBySp1() {
    Node<Element>*pre = head, *now = head->p;
    while (now && now->data < 0) now = now->p, pre = pre->p;
    while (now)
        if (now->data < 0) pre->p = now->p, now->p = head->p, head->p = now, now = pre->p;
        else now = now->p, pre = pre->p;
}

template <class Element>
void LinkList<Element>::sortBySp2() {
    int midLen = (this->getLength() >> 1) + (this->getLength() & 1);
    Node<Element>* mid = head;
    for (int i = 1; i <= midLen; i++) mid = mid->p;
    Node<Element>*now = mid->p, *nex = nullptr, *pre = nullptr;
    while (now) {
        nex = now->p, now->p = pre, pre = now, now = nex;
        if (!now) mid->p = pre;
    }
    Node<Element>*fr = head->p, *ba = mid->p, *tmp = nullptr;
    mid->p = nullptr;
    while (ba) tmp = ba, ba = ba->p, tmp->p = fr->p, fr->p = tmp, fr = fr->p->p;
}

template <class Element>
void LinkList<Element>::Merge(LinkList<Element>& x) {
    Node<Element>*a = this->head->p, *b = x.head->p, *tmp = nullptr;
    this->head->p = nullptr, x.head->p = nullptr, this->size += x.size, x.size = 0;
    while (a && b)
        if (a->data < b->data) tmp = a->p, a->p = head->p, head->p = a, a = tmp;
        else tmp = b->p, b->p = head->p, head->p = b, b = tmp;
    while (!b && a) tmp = a->p, a->p = head->p, head->p = a, a = tmp;
    while (!a && b) tmp = b->p, b->p = head->p, head->p = b, b = tmp;
}

template <class Element>
DeLinkList<Element>::DeLinkList() {
    this->head = new DeNode<Element>, this->tail = new DeNode<Element>;
    this->head->nex = tail, this->head->pre = nullptr, this->tail->nex = nullptr, this->tail->pre = head, this->head->fre = 0x3f3f3f3f, this->tail->fre = -0x3f3f3f3f;
    this->size = 0;
}

template <class Element>
DeLinkList<Element>::DeLinkList(Element initElement[], int n) {
    this->size = n;
    this->head = new DeNode<Element>, this->tail = new DeNode<Element>;
    this->head->fre = 0x3f3f3f3f, this->tail->fre = -0x3f3f3f3f;
    if (this->size == 0) this->head->nex = tail, this->head->pre = nullptr, this->tail->nex = nullptr, this->tail->pre = head;
    else {
        DeNode<Element>* now = this->head;
        now->pre = nullptr;
        for (int i = 0; i <= n - 1; i++) {
            now->nex = new DeNode<Element>;
            now->nex->pre = now, now->nex->data = initElement[i], now = now->nex;
        }
        now->nex = this->tail, this->tail->pre = now;
    }
}

template <class Element>
DeLinkList<Element>::~DeLinkList() {
    DeNode<Element>*now = this->head, *lst = nullptr;
    while (now) {
        lst = now;
        now = now->nex;
        delete (lst);
    }
}

template <class Element>
void DeLinkList<Element>::printListByRow() {
    DeNode<Element>* now = this->head->nex;
    while (now != this->tail) {
        std::cout << now->data << ' ';
        now = now->nex;
    }
    std::cout << '\n';
}

template <class Element>
DeNode<Element>* Locate(DeLinkList<Element>& L, Element x) {
    DeNode<Element>* now = L.head->nex;
    while (now != L.tail) {
        if (now->data == x) break;
        now = now->nex;
    }
    if (now == L.tail) {
        std::cout << "Not Found!\n";
        return nullptr;
    }
    DeNode<Element>* pos = now->pre;
    now->fre++;
    while (now->fre > pos->fre) pos = pos->pre;
    now->pre->nex = now->nex, now->nex->pre = now->pre, now->pre = pos, now->nex = pos->nex, pos->nex->pre = now, pos->nex = now;
    return now;
}

const int testSize = 10;

int main() {
    // pro1:
    // srand((unsigned)time(0));
    // int num[testSize];
    // for (int i = 0; i < testSize; i++) num[i] = rand() % 2001 - 1000;
    // LinkList<int> ll(num, testSize);
    // std::cout << "排序前数组元素为：\n";
    // ll.printListByRow();
    // ll.sortBySp1();
    // std::cout << "排序后数组元素为：\n";
    // ll.printListByRow();

    // pro2:
    // int num[testSize];
    // for (int i = 0; i < testSize; i++) num[i] = i + 1;
    // LinkList<int> ll(num, testSize);
    // std::cout << "排序前数组元素为：\n";
    // ll.printListByRow();
    // ll.sortBySp2();
    // std::cout << "排序后数组元素为：\n";
    // ll.printListByRow();

    // pro3:
    // srand((unsigned)time(0));
    // int num[testSize];
    // for (int i = 0; i < testSize; i++) num[i] = rand() % 2001 - 1000;
    // std::sort(num, num + testSize);
    // LinkList<int> ll(num, testSize);
    // std::cout << "第一个链表元素：\n";
    // ll.printListByRow();
    // for (int i = 0; i < testSize; i++) num[i] = rand() % 2001 - 1000;
    // std::sort(num, num + testSize);
    // LinkList<int> lll(num, testSize);
    // std::cout << "第二个链表元素：\n";
    // lll.printListByRow();
    // ll.Merge(lll);
    // std::cout << "合并后链表元素：\n";
    // ll.printListByRow();

    // pro4:
    int num[testSize];
    srand((unsigned)time(0));
    for (int i = 0; i < testSize; i++) num[i] = rand() % 2001 - 1000;
    DeLinkList<int> dll(num, testSize);
    while (1) {
        std::cout << "当前链表中元素情况：\n";
        dll.printListByRow();
        int op; //输入-1退出测试，输入[0, testSize - 1]中的数值查询链表元素。
        std::cin >> op;
        if (op == -1) break;
        else std::cout <<"输出返回的节点指针内部数据："<< Locate<int>(dll, num[op])->data << '\n';
    }
    system("pause");
}
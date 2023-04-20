#include <iostream>
const int MaxSize = 1e3 + 7;

struct indexArray {
    int length = 0;
    int data[MaxSize];
};

std::ostream& operator<<(std::ostream& out, const indexArray IA) {
    for (int i = 0; i < IA.length; i++)
        out << IA.data[i] << " \n"[i == IA.length - 1];
    return out;
}

class Student {
   public:
    Student(){};
    Student(std::string Tname, int Tid, std::string Tgender)
        : name(Tname), id(Tid), gender(Tgender) {}
    void setName(std::string tName) {
        this->name = tName;
    }
    void setID(int tID) {
        this->id = tID;
    }
    void setGender(std::string tGender) {
        this->gender = tGender;
    }
    std::string getName() {
        return this->name;
    }
    int getID() {
        return this->id;
    }
    std::string getGender() {
        return this->gender;
    }
    friend std::ostream& operator<<(std::ostream& out, Student stu);
    friend std::istream& operator>>(std::istream& out, Student& stu);
    bool operator==(Student& stu) {
        if (this->gender != stu.getGender() || this->name != stu.getName() || this->id != stu.getID())
            return false;
        else
            return true;
    }

   private:
    std::string name = "null";
    int id = -1;
    std::string gender = "null";
};

std::ostream& operator<<(std::ostream& out, Student stu) {
    out << stu.getName() << ' ' << stu.getID() << ' ' << stu.getGender() << ' ';
    return out;
}

std::istream& operator>>(std::istream& out, Student& stu) {
    std::string name, gender;
    int id;
    std::cout << "请输入姓名、ID、性别\n";
    std::cin >> name >> id >> gender;
    stu.setName(name), stu.setGender(gender), stu.setID(id);
    return out;
}

template <typename Element>
class LinearList {
   public:
    LinearList();
    LinearList(Element t[], int len);
    ~LinearList();
    bool InitList();
    bool DestoryList();
    int Length();
    Element Get(int i);
    indexArray Locate(Element x);
    void Insert(int i, Element x);
    Element Delete(int i);
    bool Empty();
    void Add(Element x);

   private:
    Element data[MaxSize];
    int length = -1;  // -1 表示顺序表不存在 0 表示顺序表为空 正整数表示顺序表元素个数
};

template <typename Element>
LinearList<Element>::LinearList() {
    this->InitList();
}

template <typename Element>
LinearList<Element>::LinearList(Element t[], int len) {
    this->InitList();
    length = len;
    for (int i = 0; i < len; i++)
        data[i] = t[i];
}

template <typename Element>
LinearList<Element>::~LinearList() {
    this->DestoryList();
}

template <typename Element>
bool LinearList<Element>::InitList() {
    this->length = 0;
    return true;
}

template <typename Element>
bool LinearList<Element>::DestoryList() {
    this->length = -1;
    return true;
}

template <typename Element>
int LinearList<Element>::Length() {
    if (length == -1)
        throw "Null";
    return this->length;
}

template <typename Element>
Element LinearList<Element>::Get(int i) {
    if (length == -1)
        throw "Null";
    return data[i];
}

template <typename Element>
indexArray LinearList<Element>::Locate(Element x) {
    indexArray IA;
    if (length == -1)
        throw "Null";
    for (int i = 0; i < this->length; i++)
        if (x == this->data[i])
            IA.data[IA.length++] = i + 1;
    return IA;
}

template <typename Element>
void LinearList<Element>::Insert(int i, Element x) {
    if (length == -1)
        throw "Null";
    if (this->length == MaxSize)
        throw "full";
    else if (i < 1 || i > this->length)
        throw "WrongPosition";
    for (int j = this->length; j >= i; j--)
        data[j] = data[j - 1];
    data[i - 1] = x;
    this->length++;
}

template <typename Element>
Element LinearList<Element>::Delete(int i) {
    if (length == -1)
        throw "Null";
    if (this->length == MaxSize)
        throw "full";
    else if (i < 1 || i > this->length)
        throw "WrongPosition";
    length--;
    Element tmp = data[i - 1];
    for (int j = i - 1; j < this->length; j++)
        data[j] = data[j + 1];
    return tmp;
}

template <typename Element>
bool LinearList<Element>::Empty() {
    if (length == -1)
        throw "Null";
    if (length == 0)
        return true;
    else
        return false;
}

template <typename Element>
void LinearList<Element>::Add(Element x) {
    if (length == -1)
        throw "Null";
    if (this->length == MaxSize)
        throw "full";
    data[length++] = x;
}

int main() {
    Student initStuList[] = {{"刘文越", 1, "武装直升机"}, {"王子卓", 2, "女"}, {"李逸涵", 3, "男"}, {"支露瑶", 4, "女"}};
    LinearList<Student> ll(initStuList, 4);
    std::cout << initStuList[1];
    int op;
    bool isEnd = true;
    while (isEnd) {
        std::cout << "*****************************************\n"
                  << "输入0 退出线性表\n输入1 查询线性表是否为空\n输入2 将数据插入线性表\n输入3 从线性表中删除数据\n输入4 向线性表尾增添数据\n输入5 查询线性表长度\n输入6 获取索引对应数据\n输入7 定位数据索引\n";
        std::cout << "当前线性表中数据为：\n";
        for (int i = 0; i < ll.Length(); i++) {
            std::cout << i << ":   " << ll.Get(i) << "\n";
        }
        std::cin >> op;
        std::cout << "*****************************************\n";
        Student nowX;
        int idx;
        indexArray IA;
        switch (op) {
            case 0:
                std::cout << "退出线性表！\n";
                isEnd = false;
                break;
            case 1:
                if (ll.Empty())
                    std::cout << "线性表为空！\n";
                else
                    std::cout << "线性表不为空！\n";
                break;
            case 2:
                std::cout << "请输入数据及其想要插入的索引位置：\n";
                std::cin >> nowX >> idx;
                ll.Insert(idx, nowX);
                break;
            case 3:
                std::cout << "请输入想要删除数据的索引位置：\n";
                std::cin >> idx;
                ll.Delete(idx);
                break;
            case 4:
                std::cout << "请输入数据：\n";
                std::cin >> nowX;
                ll.Add(nowX);
                break;
            case 5:
                std::cout << "线性表长度为" << ll.Length() << '\n';
                break;
            case 6:
                std::cout << "请输入索引位置：\n";
                std::cin >> idx;
                std::cout << "数据为：" << ll.Get(idx) << '\n';
                break;
            case 7:
                std::cout << "请输入数据：\n";
                std::cin >> nowX;
                IA = ll.Locate(nowX);
                if (IA.length) {
                    std::cout << "数据位置索引为：\n";
                    std::cout << IA;
                } else {
                    std::cout << "未找到该数据\n";
                }
                break;
            default:
                std::cout << "输入有误，请重新输入！\n";
                break;
        }
    }
}
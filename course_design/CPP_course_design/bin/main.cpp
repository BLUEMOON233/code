#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//调用函数
void PrintHelp();
int InsertRecord();
int QueryAllRecord();
int QueryRecord();
int DelRecord();
int ModifyRecord();
int QueryFailedRecord();
int BubbleSort();
int DeleteAll();

// 学生信息结构体
typedef struct _STRU_STU_SCORE_ {
    unsigned int nStuId;
    string cpName;
    string sex;
    double nScoreComputing;
    double nScoreMath;
    double nScoreEnglish;
    double nScoreAver;
} STRU_STU_SCORE;

//定义链表中基本节点。
struct NODE {
    _STRU_STU_SCORE_ data;
    NODE* next;
};

//链表类
class List {
    NODE* head;

   public:
    List() { head = NULL; }
    void InsertList(_STRU_STU_SCORE_ bData);
    void DeleteList_Id(unsigned int aID);
    void OutputList();
    void FindList_Id(unsigned int aID);
    void FindList_Name(string name);
    void FindList_Sum();
    void ModifyRecord(_STRU_STU_SCORE_ e);
    void BubbleSort(int op);
    void Fileout();
    void DeleteAll();
    NODE* GetHead() { return head; }
};
List test;  //程序运行时进行操作的链表变量

//链表中的输出函数，输出全部学生数据
void List::OutputList() {
    NODE* current = head;
    cout << endl;
    if (head == NULL) {
        cout << "该学生管理系统内暂无学生记录\n";
        return;
    }
    cout << endl;
    cout << setw(10) << "学号" << setw(15) << "姓名" << setw(8) << "性别"
         << setw(10) << setprecision(1) << "高数" << setw(10) << setprecision(1)
         << "计算机" << setw(10) << setprecision(1) << "英语" << setw(10)
         << setprecision(1) << "平均分" << endl;
    cout << fixed;
    while (current != NULL) {
        cout << setw(10) << current->data.nStuId << setw(15)
             << current->data.cpName << setw(8) << current->data.sex << setw(10)
             << setprecision(1) << current->data.nScoreComputing << setw(10)
             << setprecision(1) << current->data.nScoreMath << setw(10)
             << setprecision(1) << current->data.nScoreEnglish << setw(10)
             << setprecision(1) << current->data.nScoreAver;
        current = current->next;
        cout << endl;
    }
    cout << endl;
}

//链表中的增添函数，在链表最后插入数据。
void List::InsertList(_STRU_STU_SCORE_ bData) {
    NODE *p, *s;
    p = head;
    s = (NODE*)new (NODE);
    s->data = bData;
    if (p == NULL) {
        head = s;
        s->next = NULL;
    } else {
        while (p->next != NULL)
            p = p->next;
        p->next = s;
        s->next = NULL;
    }
}

//链表中的搜索函数，该搜索为ID索引搜索
void List::FindList_Id(unsigned int aID) {
    NODE* current = head;
    bool flag = true;
    cout << endl;
    cout << setw(10) << "学号" << setw(15) << "姓名" << setw(8) << "性别"
         << setw(10) << setprecision(1) << "高数" << setw(10) << setprecision(1)
         << "计算机" << setw(10) << setprecision(1) << "英语" << setw(10)
         << setprecision(1) << "平均分" << endl;
    while (current != NULL) {
        if (current->data.nStuId == aID) {
            cout << fixed;
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            break;
        }
        current = current->next;
    }
    if (flag)
        cout << "未查询到此学生" << endl;
}

//链表中的搜索函数，该函数为姓名变量索引搜索
void List::FindList_Name(string name) {
    NODE* current = head;
    bool flag = true;
    cout << endl;
    cout << setw(10) << "学号" << setw(15) << "姓名" << setw(8) << "性别"
         << setw(10) << setprecision(1) << "高数" << setw(10) << setprecision(1)
         << "计算机" << setw(10) << setprecision(1) << "英语" << setw(10)
         << setprecision(1) << "平均分" << endl;
    while (current != NULL) {
        if (current->data.cpName == name) {
            cout << fixed;
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            break;
        }
        current = current->next;
    }
    if (flag)
        cout << "未查询到此学生" << endl;
}

//链表中的删除函数，使用ID变量查找学生记录并且删除。
void List::DeleteList_Id(unsigned aID) {
    NODE *p, *q;
    p = head;
    bool flag = false;
    if (p == NULL) {
        cout << endl << "学生列表中暂无学生记录\n" << endl;
        return;
    }
    if (p->data.nStuId == aID) {
        head = p->next;
        flag = true;
        delete p;
    } else {
        while (p->data.nStuId != aID && p->next != NULL) {
            q = p;
            p = p->next;
        }
        if (p->data.nStuId == aID) {
            q->next = p->next;
            flag = true;
            delete p;
        }
    }
    if (flag)
        cout << endl << "删除完毕。" << endl << endl;
    else
        cout << endl << "未找到该学生记录。" << endl << endl;
}

//链表中的修改函数，为ID变量查询
void List::ModifyRecord(_STRU_STU_SCORE_ e) {
    NODE* current = head;
    bool flag = true;
    while (current != NULL) {
        if (current->data.nStuId == e.nStuId) {
            current->data = e;
            flag = false;
            break;
        }
        current = current->next;
    }
    if (flag)
        cout << "未查询到此学生" << endl;
}

//链表中的统计函数，用于统计各个分数段学生数量
void List::FindList_Sum() {
    int sum0 = 0, sum60 = 0, sum75, sum85 = 0;
    cout << endl;
    cout << endl;
    cout << setw(10) << "学号" << setw(15) << "姓名" << setw(8) << "性别"
         << setw(10) << setprecision(1) << "高数" << setw(10) << setprecision(1)
         << "计算机" << setw(10) << setprecision(1) << "英语" << setw(10)
         << setprecision(1) << "平均分" << endl;
    cout << fixed;
    cout << "\n不及格分段的学生为：\n";
    NODE* current = head;
    bool flag = true;
    while (current != NULL) {
        if (current->data.nScoreAver >= 0 && current->data.nScoreAver < 60) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
        }
        current = current->next;
    }
    if (flag)
        cout << "无\n";
    cout << "人数为:" << sum0 << endl << endl;
    flag = true;
    cout << "及格分段的学生为\n";
    current = head;
    while (current != NULL) {
        if (current->data.nScoreAver >= 60 && current->data.nScoreAver < 75) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
            sum60++;
        }
        current = current->next;
    }
    if (flag)
        cout << "无\n";
    cout << "人数为:" << sum60 << endl << endl;
    flag = true;
    cout << "良好分段的学生为：\n";
    current = head;
    while (current != NULL) {
        if (current->data.nScoreAver >= 75 && current->data.nScoreAver < 85) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
            sum75++;
        }
        current = current->next;
    }
    if (flag)
        cout << "无\n";
    flag = true;
    cout << "人数为:" << sum75 << endl << endl;
    cout << "优秀分段的学生为：\n";
    current = head;
    while (current != NULL) {
        if (current->data.nScoreAver >= 85 && current->data.nScoreAver <= 100) {
            cout << setw(10) << current->data.nStuId << setw(15)
                 << current->data.cpName << setw(8) << current->data.sex
                 << setw(10) << setprecision(1) << current->data.nScoreComputing
                 << setw(10) << setprecision(1) << current->data.nScoreMath
                 << setw(10) << setprecision(1) << current->data.nScoreEnglish
                 << setw(10) << setprecision(1) << current->data.nScoreAver;
            cout << endl;
            flag = false;
            sum0++;
            sum85++;
        }
        current = current->next;
    }
    if (flag)
        cout << "无\n";
    cout << "人数为:" << sum85 << endl << endl;
}

//链表中的排序函数，可定义正向排序或逆向排序
void List::BubbleSort(int op) {
    if (head == NULL)
        return;
    else {
        NODE* goal = head;
        while (goal->next != NULL)
            goal = goal->next;
        if (op == '1') {
            for (NODE* i = head; i != goal; i = i->next)
                for (NODE* j = i; j != NULL; j = j->next)
                    if (i->data.nScoreAver < j->data.nScoreAver)
                        swap(i->data, j->data);
        } else
            for (NODE* i = head; i != goal; i = i->next)
                for (NODE* j = i; j != NULL; j = j->next)
                    if (i->data.nScoreAver > j->data.nScoreAver)
                        swap(i->data, j->data);
    }
}

//函数中的存储函数，用于向文件中存储数据，数据以txt的形式存储
void List::Fileout() {
    ofstream fout("source.txt", ios::binary);
    NODE* current = head;
    while (current != NULL) {
        fout << current->data.cpName << ' ';
        fout << current->data.nStuId << ' ';
        fout << current->data.sex << ' ';
        fout << current->data.nScoreComputing << ' ';
        fout << current->data.nScoreEnglish << ' ';
        fout << current->data.nScoreMath << ' ';
        fout << current->data.nScoreAver << ' ';
        current = current->next;
    }
    fout << "end";
    fout.close();
}

//函数中的清空函数，用于清空所有学生数据
void List::DeleteAll() {
    while (head != NULL) {
        NODE* p;
        p = head;
        head = p->next;
        delete p;
    }
}

int main() {                                   // main函数中
    ifstream fcin("source.txt", ios::binary);  //开始初始化test链表变量
    while (1) {                                //初始化test链表变量
        string op;
        fcin >> op;
        if (op == "end") {
            fcin.close();
            break;
        } else {
            _STRU_STU_SCORE_ tmp;
            tmp.cpName = op;
            fcin >> tmp.nStuId;
            fcin >> tmp.sex;
            fcin >> tmp.nScoreComputing;
            fcin >> tmp.nScoreEnglish;
            fcin >> tmp.nScoreMath;
            fcin >> tmp.nScoreAver;
            test.InsertList(tmp);
        }
    }

    system("color 30");  //实现颜色效果
    char cSelection;
    PrintHelp();  //输出菜单面板
    while (1) {
        printf("\n请输入您的选择（i,d,m,g,a,f,h,c或q）：");
        cSelection = getche();
        switch (cSelection) {  // switch语句实现功能选择
            case 'i':
            case 'I': {
                InsertRecord();
                break;
            }
            case 'd':
            case 'D': {
                DelRecord();
                break;
            }
            case 'm':
            case 'M': {
                ModifyRecord();
                break;
            }
            case 'g':
            case 'G': {
                QueryRecord();
                break;
            }
            case 'a':
            case 'A': {
                QueryAllRecord();
                break;
            }
            case 'f':
            case 'F': {
                QueryFailedRecord();
                break;
            }
            case 'c':
            case 'C': {
                DeleteAll();
                break;
            }
            case 'q':
            case 'Q': {
                //				DestroyList();;
                break;
            }
            case 'h':
            case 'H': {
                PrintHelp();
                break;
            }
            case 's':
            case 'S': {
                BubbleSort();
                break;
            }
            default: {
                break;
            }
        }
        if (cSelection == 'q' || cSelection == 'Q') {
            cout << "\n\n是否保存到文件？（Y/N）" << endl;
            int op;
            while (1) {
                op = getche();
                if (op == 'y' || op == 'Y') {
                    test.Fileout();
                    break;
                } else if (op == 'n' || op == 'N')
                    break;
                else
                    cout << "输入有误，请重新输入。" << endl;
            }
            break;
        }
    }
    return 0;
}

void PrintHelp() {
    cout << "\n//"
            "**************************************************************"
            "****"
            "********//\n";
    cout << "//*************  学    生   成   绩   管   理   系   统    "
            "*****************//\n";
    cout << "//"
            "**************************************************************"
            "****"
            "********//\n";

    cout << "（1）插入一条纪录，请输入i或I；\n（2）删除一条纪录，请输入d或D"
            "；\n";
    cout << "（3）修改纪录，请输入m或M；\n（4）查询纪录，请输入g或G；\n";
    cout
        << "（5）显示所有纪录，请输入a或A；\n（6）显示各分数段统计数据，请输入f"
           "或F；"
           "\n";
    cout << "（7）显示帮助文件，请输入h或H；\n（8）删除所有纪录，请输入c或C"
            "。\n";
    cout << "（9）进行排序,请输入s或S。\n"
         << "（10）退出，请输入q或Q。\n";

    cout << flush;

    return;
}

int InsertRecord() {
    STRU_STU_SCORE e;
    int rslt;

    cout << "\n请输入纪录的各个信息：\n";

    cout << "\n学号：";
    cin >> e.nStuId;

    cout << "\n姓名：";
    cin >> e.cpName;

    cout << "\n性别：";
    cin >> e.sex;

    while (1) {
        cout << "\n计算机成绩：";
        cin >> e.nScoreComputing;
        if (e.nScoreComputing >= 0 && e.nScoreComputing <= 100)
            break;
        cout << "输入的成绩应该在0-100分之间，请重新检查后输入\n\n";
    }
    while (1) {
        cout << "\n高数成绩：";
        cin >> e.nScoreMath;
        if (e.nScoreMath >= 0 && e.nScoreMath <= 100)
            break;
        cout << "输入的成绩应该在0-100分之间，请重新检查后输入\n\n";
    }
    while (1) {
        cout << "\n英语成绩：";
        cin >> e.nScoreEnglish;
        if (e.nScoreEnglish >= 0 && e.nScoreEnglish <= 100)
            break;
        cout << "输入的成绩应该在0-100分之间，请重新检查后输入\n\n";
    }

    e.nScoreAver = (e.nScoreComputing + e.nScoreEnglish + e.nScoreMath) / 3;

    // 插入链表
    // 调用链表的Insert操作代码

    test.InsertList(e);

    rslt = 0; /* 插入结果 */
    if (rslt == 0) {
        cout << endl << "插入纪录成功！";
    } else {
        cout << endl << "\n插入纪录失败！";
    }
    cout << flush;
    return 0;
}

int QueryAllRecord() {
    //打印所有学生的成绩信息。
    cout << "\n打印所有学生的成绩信息。\n";
    // 显示所有学生信息
    test.OutputList();
    cout << endl;
    cout << flush;
    return 0;
}

int QueryRecord() {
    while (true) {
        char jdg;
        cout << "\n请问您是要查询学号还是姓名";
        cout << "\n学号请输入1，姓名请输入2:";
        jdg = getche();
        if (jdg == '1') {
            unsigned int e;

            cout << "\n请输入要查询纪录的学号：";
            cin >> e;
            cout << endl;
            cout << endl;
            test.FindList_Id(e);
            cout << endl;
            cout << endl;
            cout << flush;
            return 0;
        } else if (jdg == '2') {
            string e;
            cout << "\n请输入要查询纪录的姓名：";
            cin >> e;
            cout << endl;
            cout << endl;
            test.FindList_Name(e);
            cout << endl;
            cout << endl;
            cout << flush;
            return 0;
        } else {
            cout << "\n输入有误，请重新输入";
            continue;
        }
    }
}

int DelRecord() {
    unsigned int stuid;
    cout << "\n请输入要删除纪录的学号：";
    cin >> stuid;
    test.DeleteList_Id(stuid);
    // 删除记录代码
    return 0;
}

int ModifyRecord() {
    STRU_STU_SCORE e;

    cout << "\n请输入修改纪录的学号：";
    cin >> e.nStuId;

    cout << "\n请输入更新后的记录数据：\n";
    cout << "\n姓名：";
    cin >> e.cpName;

    cout << "\n性别：";
    cin >> e.sex;

    while (1) {
        cout << "\n计算机成绩：";
        cin >> e.nScoreComputing;
        if (e.nScoreComputing >= 0 && e.nScoreComputing <= 100)
            break;
        cout << "输入的成绩应该在0-100分之间，请重新检查后输入\n\n";
    }
    while (1) {
        cout << "\n高数成绩：";
        cin >> e.nScoreMath;
        if (e.nScoreMath >= 0 && e.nScoreMath <= 100)
            break;
        cout << "输入的成绩应该在0-100分之间，请重新检查后输入\n\n";
    }
    while (1) {
        cout << "\n英语成绩：";
        cin >> e.nScoreEnglish;
        if (e.nScoreEnglish >= 0 && e.nScoreEnglish <= 100)
            break;
        cout << "输入的成绩应该在0-100分之间，请重新检查后输入\n\n";
    }

    e.nScoreAver = (e.nScoreComputing + e.nScoreEnglish + e.nScoreMath) / 3;

    // 修改记录代码

    test.ModifyRecord(e);
    cout << endl << "修改完毕。" << endl << endl;
    return 0;
}

int QueryFailedRecord() {
    test.FindList_Sum();
    return 0;
}

int BubbleSort() {
    cout << "\n请问您是顺序排序还是逆序排序";
    cout << "\n顺序排序请输入1，逆序排序请输入2:";
    int op;
    op = getche();
    test.BubbleSort(op);
    test.OutputList();
    cout << endl << "排序完毕。" << endl << endl;
    return 0;
}

int DeleteAll() {
    cout << endl << "请确认是否清空所有学生记录 (Y/N)" << endl;
    int op;
    while (1) {
        op = getche();
        if (op == 'y' || op == 'Y') {
            test.DeleteAll();
            cout << endl << "删除完毕。" << endl << endl;
            break;
        } else if (op == 'n' || op == 'N') {
            cout << endl << "已撤回删除操作" << endl;
            break;
        } else
            cout << endl << "输入有误，请重新输入。" << endl;
    }
    return 0;
}
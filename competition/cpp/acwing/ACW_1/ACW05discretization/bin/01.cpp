#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 300010;
int n, m;
int a[N], s[N];
vector<int> alls;
vector<PII> add, que;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {  //二分法寻找x,并返回坐标
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;  //因为要用到前缀和，所以向后推移一位，从1开始
}

int main() {
    cin >> n >> m;
    while (n--) {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);  //将坐标存入alls
    }
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        que.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);  //将查询的边界输入alls
    }
    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()),
               alls.end());  // unique返回后面的边界值

    //处理插入
    for (auto item : add) {
        int x = find(item.first);  //找到x对应的位置
        a[x] += item.second;
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    //处理询问
    for (auto item : que) {
        int l = find(item.first), r = find(item.second);
        printf("%d\n", s[r] - s[l - 1]);  //得出x坐标上数值的和
    }
    return 0;
}
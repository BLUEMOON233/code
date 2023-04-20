#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int UI;
typedef long long LL;

const int N = 100010;
int e[N], l[N], r[N], idx;

void init() {  //初始化
    r[0] = 1, l[1] = 0;
    idx = 2;
}

void add(int k, int x) {  //在k后插入数据x
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx++;
}

void remove(int k) {  //删除k点
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main() {
    int M;
    cin >> M;
    init();
    while (M--) {
        string com;
        cin >> com;
        if (com == "L") {
            int x;
            cin >> x;
            add(0, x);
        } else if (com == "R") {
            int x;
            cin >> x;
            add(l[1], x);
        } else if (com == "D") {
            int k;
            cin >> k;
            remove(k + 1);
        } else if (com == "IL") {
            int k, x;
            cin >> k >> x;
            add(l[k + 1], x);
        } else if (com == "IR") {
            int k, x;
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    cout << endl;
    return 0;
}
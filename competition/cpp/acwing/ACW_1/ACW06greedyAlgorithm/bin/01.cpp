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
typedef pair<int, int> PII;

int n;
vector<PII> segs;

void merge(vector<PII>& segs) {
    vector<PII> res;
    sort(segs.begin(), segs.end());  // pair调用sort排序会优先左端点排序
    int st = -2e9, ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if (st != -2e9)  //跳过第一个使其初始化
                res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        } else
            ed = max(ed, seg.second);  //更新后端点
    }
    if (st != -2e9)
        res.push_back({st, ed});  //将最后一个区间存入res
    segs = res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}
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
int p[N];

int find(int x) {  //返回x所在集合的根节点
    if (p[x] != x)
        p[x] = find(p[x]);  //路径压缩
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        p[i] = i;
    while (m--) {
        char com;
        int a, b;
        scanf(" %c%d%d", &com, &a, &b);
        if (com == 'M')
            p[find(a)] = find(b);
        else if (find(a) == find(b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
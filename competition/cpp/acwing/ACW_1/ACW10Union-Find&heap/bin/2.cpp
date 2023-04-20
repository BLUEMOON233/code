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
int p[N], siz[N];

int find(int x) {  //返回x所在集合的根节点
    if (p[x] != x)
        p[x] = find(p[x]);  //路径压缩
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        siz[i] = 1;  //只有根节点的size有意义
    }
    while (m--) {
        char com;
        int a, b;
        scanf(" %c", &com);
        if (com == 'C') {
            scanf(" %d%d", &a, &b);
            if (find(a) == find(b))
                continue;
            siz[find(b)] += siz[find(a)];
            p[find(a)] = find(b);
        } else if (com == 'Q') {
            int op;
            scanf(" %d", &op);
            if (op == 1) {
                scanf(" %d%d", &a, &b);
                if (find(a) == find(b))
                    printf("Yes\n");
                else
                    printf("No\n");
            } else {
                scanf(" %d", &a);
                printf("%d\n", siz[find(a)]);
            }
        }
    }
    return 0;
}
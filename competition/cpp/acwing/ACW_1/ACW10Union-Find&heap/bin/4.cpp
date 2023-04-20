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
int n, m = 0;
int h[N], siz;
int ph[N],
    hp[N];  // ph[k]存放的是第k个插入的位置在堆里的下标，hp[k]存放的是堆里的当前元素是第几个插入的。
bool isDel[N];

void hpSwap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    int t = u;
    if (u * 2 <= siz && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= siz && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t) {
        hpSwap(u, t);
        down(t);
    }
}

void up(int u) {
    while (u / 2 > 0 && h[u / 2] > h[u]) {
        hpSwap(u / 2, u);
        u /= 2;
    }
}

int main() {
    scanf(" %d", &n);
    while (n--) {
        char op[10];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            ph[++m] = ++siz;
            hp[siz] = m;
            h[siz] = x;
            up(siz);
        } else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM")) {
            isDel[hp[1]] = true;
            hpSwap(1, siz--);
            down(1);
        } else if (!strcmp(op, "D")) {
            scanf("%d", &k);
            if (isDel[k])
                continue;
            isDel[k] = true;
            k = ph[k];
            hpSwap(k, siz--);
            down(k), up(k);
        } else {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
        for (int i = 1; i <= siz; i++)
            cout << h[i] << ' ';
        puts("");
    }
    return 0;
}
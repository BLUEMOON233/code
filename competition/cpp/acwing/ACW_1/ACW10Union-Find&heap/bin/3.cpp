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
int n, m;
int hp[N], siz;

void down(int u) {
    int t = u;
    if (u * 2 <= siz && hp[u * 2] < hp[t])
        t = u * 2;
    if (u * 2 + 1 <= siz && hp[u * 2 + 1] < hp[t])
        t = u * 2 + 1;
    if (u != t) {
        swap(hp[u], hp[t]);
        down(t);
    }
}

void up(int u) {
    while (u / 2 > 0 && hp[u / 2] > hp[u]) {
        swap(hp[u / 2], hp[u]);
        u /= 2;
    }
}

int main() {
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &hp[i]);
    }
    siz = n;
    for (int i = n / 2; i; i--)
        down(i);
    while (m--) {  //取出最小值
        printf("%d ", hp[1]);
        hp[1] = hp[siz--];
        down(1);
    }
}
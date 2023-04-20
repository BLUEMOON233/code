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


int son[N][26];
int cnt[N], idx;
char tmp[N];

void insert(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!(son[p][u]))
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!(son[p][u]))
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        char com;
        scanf(" %c%s", &com, &tmp);
        if (com == 'I') {
            insert(tmp);
        } else if (com == 'Q') {
            printf("%d\n", query(tmp));
        }
    }
    return 0;
}
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 1010;
char str[N][15];
int f[15][15];

int edit_distance(char a[], char b[]) {
    int m = strlen(b + 1);
    int n = strlen(a + 1);
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= m; i++)
        f[0][i] = i;
    for (int i = 0; i <= n; i++)
        f[i][0] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    return f[n][m];
}

int main() {
    int n, m;
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf(" %s", str[i] + 1);
    while (m--) {
        char tmp[15];
        int lmt, cnt = 0;
        scanf(" %s%d", tmp + 1, &lmt);
        for (int i = 1; i <= n; i++)
            if (edit_distance(str[i], tmp) <= lmt)
                cnt++;
        printf("%d\n", cnt);
    }
}
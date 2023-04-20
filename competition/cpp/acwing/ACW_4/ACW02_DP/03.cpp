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
char a[N], b[N];
int f[N][N];

int main() {
    int n, m;
    scanf(" %d%d", &n, &m);
    scanf(" %s%s", a + 1, b + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    printf("%d\n", f[n][m]);
}
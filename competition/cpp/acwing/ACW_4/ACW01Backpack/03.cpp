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
#include <unordered_map>
#include <vector>

using namespace std;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 110;
int n, m;
int v[N], w[N], s[N];
int f[N][N];

int main() {
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf(" %d%d%d", &v[i], &w[i], &s[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + k * w[i]);
    printf("%d\n", f[n][m]);

    return 0;
}
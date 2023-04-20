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

const int N = 1010;
int v[N], w[N];
int f[N][N];

int main() {
    int n, m;
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf(" %d%d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
    printf("%d\n", f[n][m]);
}
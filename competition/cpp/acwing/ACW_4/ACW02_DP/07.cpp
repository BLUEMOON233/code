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

const int N = 20, M = 1 << N;
int n;
int w[N][N];
int f[M][N];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf(" %d", &w[i][j]);
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if ((i - (1 << j)) >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
    printf("%d\n", f[(1 << n) - 1][n - 1]);
}

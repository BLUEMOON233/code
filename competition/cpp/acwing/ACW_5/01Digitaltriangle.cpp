#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int w[N][N], f[N][N];

int main() {
    int T;
    scanf(" %d", &T);
    while (T--) {
        int R, C;
        scanf(" %d%d", &R, &C);
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                scanf(" %d", &w[i][j]);
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
        printf("%d\n", f[R][C]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 210;
int n, m, k;
int g[N][N];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
}

int main() {
    int a, b, c;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf(" %d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    floyd();
    while (k--) {
        int a, b;
        scanf(" %d%d", &a, &b);
        if (g[a][b] == INF)
            puts("impossible");
        else
            printf("%d\n", g[a][b]);
    }
}
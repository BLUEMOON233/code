#include <bits/stdc++.h>
using namespace std;

const int N = 510, M = 1e5 + 10;

struct edge {
    int a, b, c;
} e[M];

int n, m, k;
int dist[N];
int last[N];

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= k; i++) {
        memcpy(last, dist, sizeof dist);
        for (int j = 1; j <= m; j++) {
            auto t = e[j];
            dist[t.b] = min(dist[t.b], last[t.a] + t.c);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", dist[n]);
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf(" %d%d%d", &a, &b, &c);
        e[i] = {a, b, c};
    }
    bellman_ford();
}
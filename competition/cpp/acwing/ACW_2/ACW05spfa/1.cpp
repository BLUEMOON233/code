#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], e[2 * N], ne[2 * N], w[2 * N], idx = 0;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        printf("%d\n", dist[n]);
}

int main() {
    memset(h, -1, sizeof h);
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf(" %d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    spfa();
}
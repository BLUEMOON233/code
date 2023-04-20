#include <bits/stdc++.h>
using namespace std;

// spfa判断是否存在负环：
const int N = 2010, M = 1e5 + 10;
int n, m;
int h[N], e[M], ne[M], w[M], idx = 0;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > n)
                    return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf(" %d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    if (spfa())
        puts("Yes");
    else
        puts("No");
}
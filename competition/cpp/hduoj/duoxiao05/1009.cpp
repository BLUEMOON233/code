#include<bits/stdc++.h>
using i64 = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
template<class T>
inline T read() {
    T x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
template<class T>
inline void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
#define read() read<int>()
#define write(tmp) write<int>(tmp);

vector<vector<int>> adj(maxn);
int dep[maxn];
int w[maxn];
int ans;
int fa[maxn];
int top[maxn];

int get(int x) {
    return (int)ceil(log2(2.0 * x));
}

void dfs(int p, int fav, int topv, int sz) {
    dep[p] = dep[topv];
    top[p] = topv;
    if (adj[p].size() == 1 && adj[p].front() == fav) {
        //leaf
        dep[top[p]] = dep[top[p]] + get(sz);
        ans = max(ans, dep[top[p]]);
        // cout<<p<<' '<<top[p]<<' '<<dep[top[p]]<<'\n';
        return;
    }
    if (w[p] == 0) {
        dep[top[p]] = dep[top[p]] + get(sz);
    } else {
        dfs(w[p], p, topv, sz + 1);
    }
    for (auto v : adj[p]) {
        if (v == fav || v == w[p])continue;
        dep[v] = dep[top[p]];
        dfs(v, p, v, 1);
    }
    ans = max(ans, dep[top[p]]);
    // cout<<p<<' '<<top[p]<<' '<<dep[top[p]]<<'\n';
}

void slv() {
    int n;
    // cin >> n;
    n = read();
    ans = 1;
    for (int i = 1; i <= n; i++) adj[i].clear(), dep[i] = 0, top[i] = i;
    for (int i = 1; i <= n; i++) {
        // cin >> fa[i];
        fa[i] = read();
        if (fa[i] == 0) continue;
        adj[i].push_back(fa[i]);
        adj[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        // cin >> w[i];
        w[i] = read();
    }
    dep[1] = 0;
    dfs(1, 0, 1, 1);
    // cout << ans << '\n';
    write(ans);
    putchar('\n');
}

int main() {
    // int size(512<<20); // 512M
    // __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    _ = read();
    while (_--) slv();
    // exit(0);
}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define mes(tmp, data) memset(tmp, data, sizeof tmp)
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << " = " << x << endl;
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout<<tmp[i]<<" \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout<<tmp[i]<<" \n"[i == Size]
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
const int N = 1e5 + 7;

int h[N], e[N << 1], ne[N << 1], w[N << 1], idx = 0;
inline void add(int a, int b, int c) {
    e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}
int sz[N], fa[N];
LL rs[N];
LL res = 1e18 + 7;

void dfssz(int now, int father) {
    sz[now] = 1;
    fa[now] = father;
    for (int i = h[now]; i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        dfssz(j, now);
        sz[now] += sz[j];
    }
}

LL dfs(int now, int father, int ww) {
    for (int i = h[now]; i; i = ne[i]) {
        int j = e[i];
        if (j == father) continue;
        rs[now] += dfs(j, now, w[i]);
    }
    if (ww == 1) {
        res = min(res, (LL)rs[now] + sz[1] - sz[now]);
        return sz[now];
    }
    else {
        return rs[now] + 2;
    }
}

inline void solve() {
    int n;
    cin >> n;
    rep(i, 1, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
    dfssz(1, 0);
    // debug1(sz, n);
    dfs(1, 0, 0);
    res = min(res, (LL)rs[1]);
    cout << res << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

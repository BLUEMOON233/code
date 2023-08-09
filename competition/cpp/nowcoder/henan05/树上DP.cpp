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
const int N = 2e5 + 7;
int h[N], e[N << 1], ne[N << 1], idx = 0;
inline void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}
vector<LL> sz;

void dfs(int now, int fa, int dp) {
    sz[now] = dp;
    for (int i = h[now]; i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        dfs(j, now, dp + 1);
    }
}

inline void solve() {
    int n;
    cin >> n;
    idx = 0;
    rep(i, 1, n) h[i] = 0;
    sz.resize(n + 1, 0);
    rep(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    vector<int> w(n + 1);
    rep(i, 1, n) cin >> w[i];
    sort(w.begin() + 1, w.end());
    dfs(1, 0, 1);
    sort(sz.begin() + 1, sz.end());
    LL rs = 0;
    rep(i, 1, n) rs += sz[i] * w[i];
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

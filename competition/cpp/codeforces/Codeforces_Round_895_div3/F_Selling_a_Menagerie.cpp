#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = j; i <= int(k); i++)
const int N = 1e5 + 7;
int to[N], c[N], f[N], in[N];
vector<int> cir;
vector<int> ret;
int n;

void dfs(int now, int pos) {
    ret.emplace_back(now);
    f[now] = pos;
    int nxt = to[now];
    if (f[nxt] && f[nxt] != pos) return;
    if (f[nxt]) {
        vector<bool> mp(n + 1, false);
        int t = now;
        int p = now;
        do {
            if (c[p] > c[t]) p = t;
            if (c[p] == c[t] && p > t) p = t;
            t = to[t];
        } while (t != now);
        t = to[p];
        do {
            cir.emplace_back(t);
            mp[t] = true;
            t = to[t];
        } while (t != to[p]);
        t = pos;
        ret.clear();
        while (!mp[t]) {
            ret.emplace_back(t);
            t = to[t];
        }
        return;
    }
    dfs(nxt, pos);
}

void solve() {
    cin >> n;
    cir.clear();
    ret.clear();
    rep(i, 1, n) to[i] = 0;
    rep(i, 1, n) c[i] = 0;
    rep(i, 1, n) f[i] = 0;
    rep(i, 1, n) in[i] = 0;
    rep(i, 1, n) { cin >> to[i]; in[to[i]]++; }
    rep(i, 1, n) cin >> c[i];
    bool sp = false;
    rep(i, 1, n) if (!in[i]) {
        sp = true;
        ret.clear();
        dfs(i, i);
        for (auto ri : ret) cout << ri << ' ';
    }
    if (sp) for (auto ci : cir) cout << ci << ' ';
    else {
        rep(i, 1, n) if (!f[i]) {
            ret.clear();
            dfs(i, i);
            for (auto ri : ret) cout << ri << ' ';
        }
        for (auto ci : cir) cout << ci << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
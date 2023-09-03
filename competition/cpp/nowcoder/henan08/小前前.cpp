#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

inline void solve() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n + 1);
    vector<vector<int> > pre(n + 1, vector(60, 0));
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        pre[i] = pre[i - 1];
        rep(j, 0, 59) pre[i][j] += (a[i] >> j) & 1;
    }
    while (q--) {
        LL l, r, x;
        cin >> l >> r >> x;
        vector<bool> now(60, 0);
        rep(i, 0, 59) now[i] = bool(pre[r][i] - pre[l - 1][i]);
        LL rs = 0;
        per(i, 59, 0) {
            rs <<= 1;
            if (now[i] || ((x >> i) & 1)) rs += 1;
        }
        cout << rs << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)


void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<vector<LL>> dp(n + 1, vector<LL>(k + 1, 1e18 + 7));
    dp[0][0] = 0;
    rep(i, 1, n) rep(l, max(i - k, 1), i) rep(r, i, min(i + k, n)) {
        if (r - l > k) continue;
        int cost = r - l;
        rep(now, cost, k)
            dp[r][now] = min(dp[l - 1][now - cost] + a[i] * (r - l + 1), dp[r][now]);
    }
    LL rs = 1e18 + 7;
    rep(i, 0, k) rs = min(rs, dp[n][i]);
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
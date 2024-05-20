#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    LL m, x;
    cin >> m >> x;
    vector<LL> c(m + 1), h(m + 1);
    rep(i, 1, m) cin >> c[i] >> h[i];
    LL up = 0;
    rep(i, 1, m) up += h[i];
    vector<LL> dp(up + 1, 1e14);
    dp[0] = 0;
    rep(i, 1, m) {
        LL now = 1LL * (i - 1) * x;
        per(j, up, h[i]) {
            if (now >= dp[j - h[i]] + c[i])
                dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
        }
    }
    per(i, up, 0) if (dp[i] != 1e14) {
        cout << i << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
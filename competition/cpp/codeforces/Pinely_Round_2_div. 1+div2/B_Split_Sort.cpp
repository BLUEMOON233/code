#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

inline void solve() {
    int n, rs = 0;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> dp(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) dp[a[i]] = i;
    rep(i, 1, n - 1) if (dp[i] > dp[i + 1]) rs++;
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
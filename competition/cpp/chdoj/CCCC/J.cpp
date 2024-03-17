#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)
using namespace std;

/*完全背包，每天尽可能的赚钱即可满足，体积为手里的钱，cost为今天的价格，value为我明天的价格*/
const int M = 1e4 + 7;

void solve() {
	int t, n, m;
	cin >> t >> n >> m;
	vector<vector<int>> p(t + 1, vector<int>(n + 1));
	rep(i, 1, t) rep(j, 1, n) cin >> p[i][j];
	rep(i, 1, t - 1) {
		vector<LL> dp(M, 0);
		rep(j, 1, n) rep(k, p[i][j], m) dp[k] = max(dp[k], dp[k - p[i][j]] + p[i + 1][j] - p[i][j]);
		m += dp[m];
	}
	cout << m << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
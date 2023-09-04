#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 107;


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
	rep(i, 1, n) rep(j, i + 1, n) cin >> g[i][j];
	vector<LL> dp(1 << n, 0);
	LL rs = -1;
	rep(now, 0, (1 << n) - 1) {
		rs = max(rs, dp[now]);
		rep(i, 0, n - 1) rep(j, i + 1, n - 1) if (!((now >> i) & 1) && !((now >> j) & 1)) {
			dp[now | (1 << i) | (1 << j)] = max(dp[now | (1 << i) | (1 << j)], dp[now] + g[i + 1][j + 1]);
		}
	}
	cout << rs << '\n';
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
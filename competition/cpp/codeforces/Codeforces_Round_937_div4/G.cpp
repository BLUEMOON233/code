#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void init() {
}

void solve() {
	int n, rs = 0;
	cin >> n;
	vector<vector<string>> songs(n, vector<string>(2));
	vector<vector<int>> e(n, vector<int>(n + 1, 0));
	vector<vector<int>> dp(1 << n, vector<int>(n, 0));
	rep(i, 0, n - 1) cin >> songs[i][0] >> songs[i][1];
	rep(i, 0, n - 1) rep(j, i + 1, n - 1) if (songs[i][0] == songs[j][0] || songs[i][1] == songs[j][1])
		e[i][j] = e[j][i] = 1;
	rep(i, 0, n - 1) dp[1 << i][i] = 1;
	rep(path, 1, (1 << n) - 1) rep(i, 0, n - 1) if (dp[path][i]) {
		int sum = 0;
		int cul = path;
		while (cul) { sum += cul & 1; cul >>= 1;}
		rs = max(rs, sum);
		rep(j, 0, n - 1) if (e[i][j] && !((path >> j) & 1)) dp[path | 1 << j][j] = 1;
	}
	cout << n - rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	init();
	while (T--) solve();
	return 0;
}
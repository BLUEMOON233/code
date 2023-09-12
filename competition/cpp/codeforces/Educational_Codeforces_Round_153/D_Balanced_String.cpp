#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 3e5 + 1;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	s = '@' + s;
	int c0 = 0, c1 = 0;
	rep(i, 1, n) if (s[i] == '0') c0++;
	rep(i, 1, n) if (s[i] == '1') c1++;
	int top = (n * (n - 1) / 2 - c0 * (c0 - 1) / 2 + c1 * (c1 - 1) / 2) >> 1;
	vector<vector<int>> dp(n + 1, vector<int>(top + 1, 0x3f3f3f3f));
	dp[0][0] = 0;
	rep(i, 0, n - 1) per(j, c1, 1) rep(k, i, top) {
		dp[j][k] = min(dp[j][k], dp[j - 1][k - i] + (s[i + 1] == '0'));
	}
	cout << dp[c1][top] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
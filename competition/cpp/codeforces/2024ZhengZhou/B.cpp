#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	vector<LL> a(n + 1);
	vector<LL> dp(n + 1);
	rep(i, 1, n) cin >> a[i];
	dp[n] = a[n];

	per(i, n - 1, 1) dp[i] = min(dp[i + 1], a[i]);
	LL rs = 0;
	LL now = 0;
	rep(i, 1, n) {
		now++;
		if (a[i] == dp[i]) {
			rs += now / a[i];
			now %= a[i];
		}
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
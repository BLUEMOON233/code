#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 107;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	vector<vector<int>> rs(n + 1);
	rep(i, 1, n) rs[a[i]].emplace_back(i);
	LL ans = 0;
	rep(i, 1, n) {
		if (rs[i].size() >= 2) {
			rep(j, 1, rs[i].size() - 1) {
				// ans += LL(rs[i].size() - 1) * (rs[i][j] - rs[i][j - 1] - 1);
				int cnt = rs[i][j] - rs[i][j - 1] - 1;
				ans += 1LL * cnt * j * (rs[i].size() - j);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
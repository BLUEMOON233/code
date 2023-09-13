#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

inline void solve() {
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		rep(i, 1, n + 1) cout << "0\n";
		return;
	} else {
		cout << min(n + 1, m) << '\n';
		int t = n;
		while (t) {
			rep(i, 0, min({n - 1, m - 2, t - 1})) rep(j, 0, m - 1) cout << (i + j) % m << " \n"[j == m - 1];
			t -= min({n - 1, m - 2, t - 1}) + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
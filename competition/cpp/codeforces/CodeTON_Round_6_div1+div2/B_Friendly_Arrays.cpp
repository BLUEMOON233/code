#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, m) cin >> b[i];
	int rs = 0;
	rep(i, 1, n) rs ^= a[i];
	int mx = rs, mn = rs;
	if (n & 1) {
		rep(i, 1, m) {
			int t = mx;
			int now = b[i];
			while (now) {
				int op = now & -now;
				now -= op;
				t |= op;
			}
			mx = max(mx, t);
		}
	} else {
		rep(i, 1, m) {
			int t = mn;
			int now = b[i];
			while (now) {
				int op = now & -now;
				now -= op;
				op = -op - 1;
				t &= op;
			}
			mn = min(mn, t);
		}
	}
	cout << mn << ' ' << mx << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
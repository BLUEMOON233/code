#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	LL rsl = 1, rsr = 1e18 + 7;
	LL n, m;
	cin >> n >> m;
	vector<LL> L(n + 1);
	rep(i, 1, n) cin >> L[i];
	rep(i, 1, n) L[i]++;
	rep(i, 1, n) L[i] += L[i - 1];
	while (rsl < rsr) {
		LL now = (rsl + rsr) >> 1;
		LL cnt = 0, pos = 1;
		bool f = true;
		while (pos <= n) {
			if (cnt >= m) {
				f = false;
				break;
			}
			LL l = pos, r = n;
			while (l < r) {
				LL mid = (l + r + 1) >> 1;
				if (L[mid] - L[pos - 1] - 1 > now) r = mid - 1;
				else l = mid;
			}
			if (L[l] - L[pos - 1] - 1 > now) {
				f = false;
				break;
			}
			cnt++;
			pos = l + 1;
		}
		// cout << now << ' ' << f << '\n';
		if (f) rsr = now;
		else rsl = now + 1;
	}
	cout << rsl << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	LL d;
	cin >> d;
	LL rs = d;
	rep(i, 1, 1e7) {
		LL now = 1LL * i * i;
		if (now > d) break;
		LL l = 0, r = 1e7 + 7;
		while (l < r) {
			LL mid = (l + r + 1) >> 1;
			if (mid * mid > d - now) r = mid - 1;
			else l = mid;
		}
		// cout << i << ' ' << l << '\n';
		rs = min(rs, d - l * l - now);
		l++;
		rs = min(rs, abs(d - l * l - now));
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
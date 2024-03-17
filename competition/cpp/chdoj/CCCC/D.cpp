#include<bits/stdc++.h>
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
using namespace std;

void solve() {
	LL now = 0;
	LL mom = 0;
	rep(m, 1, 12) {
		now += 300;
		LL t;
		cin >> t;
		LL guess = now - t;
		while (guess >= 100) guess -= 100, now -= 100, mom += 100;
		now -= t;
		if (now < 0) {
			cout << -m << '\n';
			return;
		}
	}
	cout << now + mom + mom / 5 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
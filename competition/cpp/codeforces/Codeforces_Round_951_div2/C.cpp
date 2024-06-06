#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int limit = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<LL> k(n + 1);
	rep(i, 1, n) cin >> k[i];
	LL l = 1, r = 1e18;

	auto check = [&](LL x) -> bool {
		vector<LL> a(n + 1);
		LL sum = 0;
		rep(i, 1, n) a[i] = x / k[i] + 1;
		rep(i, 1, n) sum += a[i];
		rep(i, 1, n) if (sum >= a[i] * k[i]) {
			return false;
		}
		return true;
	};

	while (l < r) {
		LL mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	// cout << l << '\n';
	rep(i, 1, n) if (l / k[i] + 1 > limit) {
		cout << -1 << '\n';
		return;
	}
	rep(i, 1, n) cout << (l / k[i] + 1) << " \n"[i == n];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
	return 0;
}
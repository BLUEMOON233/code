#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	vector<LL> a(n + 1), b(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	auto check = [&](LL k) -> bool{
		LL l = a[1] - k * b[1];
		LL r = a[1] + k * b[1];
		rep(i, 2, n) {
			LL nowl = a[i] - k * b[i];
			LL nowr = a[i] + k * b[i];
			if (nowr < l || nowl > r) {
				return false;
			} else {
				l = max(nowl, l);
				r = min(nowr, r);
			}
		}
		if (l <= r) return true;
		else return false;
	};
	LL l = 0, r = 1e9;
	while (l < r) {
		LL mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
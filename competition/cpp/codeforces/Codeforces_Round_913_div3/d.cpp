#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
int n;
vector<pair<int, int>> lr;

bool check(int k) {
	int mn = 0, mx = 0;
	rep(i, 1, n) {
		auto [l, r] = lr[i];
		mn = max(l, mn - k);
		mx = min(r, mx + k);
		if (mn > mx) return false;
	}
	return true;
}

void solve() {
	cin >> n;
	lr.resize(n + 1);
	rep(i, 1, n) cin >> lr[i].first >> lr[i].second;
	LL l = 0, r = 1e9 + 7;
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
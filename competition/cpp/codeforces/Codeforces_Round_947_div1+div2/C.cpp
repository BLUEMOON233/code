#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)


void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	if (n == 2) {
		cout << min(a[1], a[2]) << '\n';
		return;
	}
	if (n == 3) {
		sort(a.begin() + 1, a.end());
		cout << a[2] << '\n';
		return;
	}
	int rs = 0;
	rep(i, 1, n - 2) {
		int x = a[i], y = a[i + 1], z = a[i + 2];
		if(y > z) swap(y, z);
		if(x > y) swap(x, y);
		if(y > z) swap(y, z);
		rs = max(rs, y);
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
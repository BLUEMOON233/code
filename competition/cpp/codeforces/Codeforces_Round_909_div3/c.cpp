#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	vector<LL> a(n + 1), pre(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) pre[i] = a[i] + pre[i - 1];
	LL rs = a[1];
	for (int l = 1, r = 1; l <= r && r <= n; l++, r++) {
		while (r + 1 <= n && abs(a[r + 1]) % 2 != abs(a[r]) % 2) r++;
		// cout << l << ' ' << r << '\n';
		// rep(i, l, r) cout << a[i] << " \n"[i == r];
		LL mn = pre[l - 1];
		rep(i, l, r) {
			rs = max(rs, pre[i] - mn);
			mn = min(pre[i], mn);
		}
		l = r;
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	vector<LL> pre(n + 1);
	rep(i, 1, n) cin >> pre[i];
	rep(i, 1, n) pre[i] += pre[i - 1];
	LL rs = 0;
	do {
		LL mx = -1, mn = 1e18 + 7;
		for (int i = 1, lst = 0; i <= n; i++, lst++) {
			mx = max(pre[i] - pre[lst], mx);
			mn = min(pre[i] - pre[lst], mn);
		}
		rs = max(mx - mn, rs);
	} while (false);
	rep(i, 2, sqrt(n)) if (n % i == 0) {
		LL a = i, b = n / i;
		LL mx = -1, mn = 1e18 + 7;
		for (int i = a, lst = 0; i <= n; i += a, lst += a) {
			mx = max(pre[i] - pre[lst], mx);
			mn = min(pre[i] - pre[lst], mn);
		}
		rs = max(mx - mn, rs);
		mx = -1, mn = 1e18 + 7;
		for (int i = b, lst = 0; i <= n; i += b, lst += b) {
			mx = max(pre[i] - pre[lst], mx);
			mn = min(pre[i] - pre[lst], mn);
		}
		rs = max(mx - mn, rs);
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
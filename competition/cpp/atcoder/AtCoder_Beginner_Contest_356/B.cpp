#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, m;
	cin >> n >> m;
	vector<LL> a(m + 1), sum(m + 1);
	rep(i, 1, m) cin >> a[i];
	rep(i, 1, n) {
		rep(j, 1, m) {
			LL t;
			cin >> t;
			sum[j] += t;
		}
	}
	rep(i, 1, m) if (sum[i] < a[i]) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
	return 0;
}
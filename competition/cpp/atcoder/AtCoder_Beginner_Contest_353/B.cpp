#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	int empty = 0;
	int rs = 0;
	rep(i, 1, n) {
		if (a[i] > empty) {
			rs++;
			empty = k - a[i];
			continue;
		}
		empty -= a[i];
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
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void init() {
}

void solve() {
	int n, m;
	cin >> n >> m;
	int sum = (n + 1) / 2;
	if (sum >= m) {
		cout << 1 + (m - 1) * 2 << '\n';
		return;
	}
	for (int i = 2; i <= n; i *= 2) {
		int t = sum + (int)ceil(((n - i + 1) * 1.0) / (i * 2));
		if (t >= m) {
			m -= sum;
			cout << i + (m - 1) * (2 * i) << '\n';
			return;
		}
		sum = t;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T = 1;
	cin >> T;
	while (T--) solve();
}
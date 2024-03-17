#include<bits/stdc++.h>
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
using namespace std;

void solve() {
	int k;
	cin >> k;
	int N = 2e6;
	vector<double> pre(N + 1, 0);
	rep(i, 1, N) {
		pre[i] = double(1.0 / i) + pre[i - 1];
		if (pre[i] > k) {
			cout << i << '\n';
			break;
		}
	}
	// cout << pre[N] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
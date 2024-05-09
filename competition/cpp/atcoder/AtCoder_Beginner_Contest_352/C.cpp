#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	rep(i, 1, n) cin >> a[i] >> b[i];
	rep(i, 1, n) b[i] -= a[i];
	rep(i, 1, n) b[i] = max(b[i], b[i - 1]);
	LL sum = 0;
	rep(i, 1, n) sum += a[i];
	cout << sum + b[n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}
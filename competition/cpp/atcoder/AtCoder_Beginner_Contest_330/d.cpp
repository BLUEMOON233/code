#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	LL rs = 0;
	vector<vector<char>> g(n + 1, vector<char>(n + 1, 'x'));
	rep(i, 1, n) rep(j, 1, n) cin >> g[i][j];
	vector<int> r(n + 1), c(n + 1);
	rep(i, 1, n) rep(j, 1, n) if (g[i][j] == 'o') r[i]++, c[j]++;
	rep(i, 1, n) rep(j, 1, n) if (g[i][j] == 'o') rs += 1LL * (r[i] - 1) * (c[j] - 1);
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
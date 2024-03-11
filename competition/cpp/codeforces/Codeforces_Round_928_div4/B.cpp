#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	vector<vector<char>> g(n + 1, vector<char>(n + 1, '0'));
	rep(i, 1, n) rep(j, 1, n) cin >> g[i][j];
	int max_r = -1, max_c = -1;
	int min_r = n + 1, min_c = n + 1;
	rep(i, 1, n) rep(j, 1, n) if(g[i][j] == '1') max_r = max(max_r, i), max_c = max(max_c, j);
	rep(i, 1, n) rep(j, 1, n) if(g[i][j] == '1') min_r = min(min_r, i), min_c = min(min_c, j);
	cout << ((max_c - min_c == max_r - min_r) ? "SQUARE" : "TRIANGLE") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
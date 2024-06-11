#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n + 2, vector<char>(m + 2, '.'));
	rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
	vector<int> r(n + 2, 0), c(m + 2, 0);
	int rsr = -1, rsc = -1;
	rep(i, 1, n + 1) {
		rep(j, 1, m) r[i] += (g[i][j] == '#' ? 1 : 0);
		if (r[i] < r[i - 1]) {
			rsr = i - 1;
			break;
		}
	}
	rep(j, 1, m + 1) {
		rep(i, 1, n) c[j] += (g[i][j] == '#' ? 1 : 0);
		if (c[j] < c[j - 1]) {
			rsc = j - 1;
			break;
		}
	}
	cout << rsr << ' ' << rsc << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
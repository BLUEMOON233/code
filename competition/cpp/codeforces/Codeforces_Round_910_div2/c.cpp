#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	LL n, m, k;
	cin >> n >> m >> k;
	int nd = n - 1 + m - 1;
	k -= nd;
	int cnt = k / 4, chk = k % 4;
	// cout << k << '\n';
	if (k < 0) {
		cout << "NO\n";
		return;
	}
	if (chk != 2 && chk != 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	// rep(i, 1, n) rep(j, 1, m - 1) cout << "R" << " \n"[j == m - 1];
	// rep(i, 1, n - 1) rep(j, 1, m) cout << "B" << " \n"[j == m];
	char lst = 'R';
	vector<vector<char>> g1(n + 1, vector<char>(m + 1, 'B'));
	vector<vector<char>> g2(n + 1, vector<char>(m + 1, 'B'));
	per(i, m - 1, 1) {
		if (lst == 'R') lst = 'B';
		else lst = 'R';
		g1[n][i] = lst;
	}
	g1[n - 1][m - 1] = 'R';
	per(i, n - 1, 1) {
		if (lst == 'R') lst = 'B';
		else lst = 'R';
		g2[i][1] = lst;
	}
	g2[1][2] = g2[1][1];
	if (lst == 'R') lst = 'B';
	else lst = 'R';
	g1[1][1] = g1[2][1] = lst;
	rep(i, 1, n) rep(j, 1, m - 1) cout << g1[i][j] << " \n"[j == m - 1];
	rep(i, 1, n - 1) rep(j, 1, m) cout << g2[i][j] << " \n"[j == m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
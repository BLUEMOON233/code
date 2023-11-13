#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
const int N = 1;

inline void solve() {
	vector<vector<char>> g(11, vector<char>(11, '.'));
	rep(i, 1, 10) rep(j, 1, 10) cin >> g[i][j];
	LL rs = 0;
	rep(i, 1, 10) rep(j, 1, 10) if (g[i][j] == 'X') {
		int x = -1, y = -1;
		if (i <= 5) x = i;
		else x = 11 - i;
		if (j <= 5) y = j;
		else y = 11 - j;
		rs += min(x, y);
	}
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

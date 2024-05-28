#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, t;
	cin >> n >> t;
	vector<int> row(n + 1, 0), col(n + 1, 0);
	int dig_1 = 0, dig_2 = 0;
	rep(turn, 1, t) {
		int now;
		cin >> now;
		int r = (now - 1) / n + 1;
		int c = (now - 1) % n + 1;
		row[r]++;
		col[c]++;
		if (r == c) dig_1++;
		if (r + c == n + 1) dig_2++;
		// cerr << r << ' ' << c << ' ' << dig_1 << '\n';
		if (row[r] == n || col[c] == n || dig_1 == n || dig_2 == n) {
			cout << turn << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
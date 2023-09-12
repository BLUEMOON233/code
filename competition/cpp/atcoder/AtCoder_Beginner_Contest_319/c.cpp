#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	vector<int> c(9), p(9);
	for (int &ci : c) { cin >> ci; }
	iota(p.begin(), p.end(), 0);
	vector<vector<int>> l = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
		{1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}
	};
	int x = 0, y = 0;
	do {
		bool ok = true;
		for (auto li : l) {
			vector<int> f;
			for (int i = 0; i < 9; i += 1) {
				if (ranges::count(li, p[i])) { f.push_back(c[p[i]]); }
			}
			if (f[0] == f[1]) { ok = false; }
		}
		x += ok;
		y += 1;
	} while (ranges::next_permutation(p).found);
	cout << fixed << setprecision(9) << double(x) / y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
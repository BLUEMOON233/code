#include<bits/stdc++.h>
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
using namespace std;

int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};

void solve() {
	vector<vector<int>> g(9, vector<int>(9, 0));
	rep(i, 1, 7) rep(j, 1, 7) {
		char c;
		cin >> c;
		if (c == 'B') g[i][j] = 1;
	}

	auto dfs = [&](int p) -> int {
		auto check = [&](int x, int y) -> bool {
			bool flag = g[x][y];
			rep(i, 0, 3) {
				int xx = x + dx[i], yy = y + dy[i];
				flag &= g[xx][yy];
			}
			return !flag;
		};

		vector<pair<int, int>> xy;
		rep(i, 2, 6) rep(j, 2, 6) if ((i + j) % 2 == p) xy.emplace_back(i, j);
		int sz = xy.size();
		int ans = sz;

		rep(i, 1, 1 << sz) {
			int rs = 0;
			bool flag = true;
			rep(j, 0, sz - 1) {
				if (i & (1 << j)) {
					auto [x, y] = xy[j];
					if (g[x][y] == 0) {flag = false; break;}
					rs++;
				}
			}

			if (!flag) continue;
			if (rs >= ans) continue;

			rep(j, 0, sz - 1) if (i & (1 << j)) {
				auto [x, y] = xy[j];
				g[x][y] = 0;
			}

			flag = true;
			for (auto [x, y] : xy) {
				flag &= check(x, y);
			}
			if (flag) ans = rs;
			
			rep(j, 0, sz - 1) if (i & (1 << j)) {
				auto [x, y] = xy[j];
				g[x][y] = 1;
			}

		}
		return ans;
	};
	cout << dfs(1) + dfs(0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
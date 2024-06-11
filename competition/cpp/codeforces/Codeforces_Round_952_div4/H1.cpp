#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

struct DSU {
	vector<int> p, Size;
	DSU(int n) : p(n + 1), Size(n + 1, 1) { iota(p.begin(), p.end(), 0);}
	int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
	bool same(int x, int y) {return find(x) == find(y);}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		Size[x] += Size[y], p[y] = x;
		return true;
	}
	int size(int x) {return Size[find(x)];}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> g(n + 1, vector<char>(m + 1, '.'));
	rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
	auto hash = [&](int r, int c) -> int {
		return (r - 1) * m + c;
	};
	DSU dsu(n * m);
	vector<int> st(n * m + 1, 0);

	auto dfs = [&](auto && self, int r, int c) -> void {
		st[hash(r, c)] = 1;
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};
		rep(i, 0, 3) {
			int y = r + dy[i];
			int x = c + dx[i];
			if (y < 1 || y > n || x < 1 || x > m) continue;
			if (g[y][x] == '.') continue;
			if (st[hash(y, x)] == 1) continue;
			dsu.merge(hash(y, x), hash(r, c));
			self(self, y, x);
		}
	};

	rep(i, 1, n) rep(j, 1, m) if (g[i][j] == '#') {
		dfs(dfs, i, j);
	}
	// rep(i, 1, n) rep(j, 1, m) if (g[i][j] == '#') {
	// 	cout << dsu.find(hash(i, j)) << ' ' << dsu.size(hash(i, j)) << '\n';
	// }
	int rs = max(n, m);
	rep(i, 1, n) {
		// cerr << "row: " << i << '\n';
		int cnt = 0;
		rep(j, 1, m) if (g[i][j] == '.') cnt++;
		// rep(j, 1, n * m) st[j] = 0;
		unordered_map<int, bool> st;
		int now = 0;

		rep(j, 1, m) if (g[i][j] == '#') {
			int p = dsu.find(hash(i, j));
			if (st[p] == 1) continue;
			// cerr << p << ' ' << dsu.size(p) << '\n';
			st[p] = 1;
			now += dsu.size(p);
		}

		if (i >= 2) {
			rep(j, 1, m) if (g[i - 1][j] == '#') {
				int p = dsu.find(hash(i - 1, j));
				if (st[p] == 1) continue;
				// cerr << p << ' ' << dsu.size(p) << '\n';
				st[p] = 1;
				now += dsu.size(p);
			}
		}
		if (i <= n - 1) {
			rep(j, 1, m) if (g[i + 1][j] == '#') {
				int p = dsu.find(hash(i + 1, j));
				if (st[p] == 1) continue;
				// cerr << p << ' ' << dsu.size(p) << '\n';
				st[p] = 1;
				now += dsu.size(p);
			}
		}
		// cerr << i << ' ' << now << '\n';
		rs = max(rs, now + cnt);
	}

	rep(j, 1, m) {
		int cnt = 0;
		rep(i, 1, n) if (g[i][j] == '.') cnt++;
		// rep(i, 1, n * m) st[i] = 0;
		unordered_map<int, bool> st;

		int now = 0;

		rep(i, 1, n) if (g[i][j] == '#') {
			int p = dsu.find(hash(i, j));
			if (st[p] == 1) continue;
			st[p] = 1;
			now += dsu.size(p);
		}

		if (j >= 2) {
			rep(i, 1, n) if (g[i][j - 1] == '#') {
				int p = dsu.find(hash(i, j - 1));
				if (st[p] == 1) continue;
				st[p] = 1;
				now += dsu.size(p);
			}
		}
		if (j <= m - 1) {
			rep(i, 1, n) if (g[i][j + 1] == '#') {
				int p = dsu.find(hash(i, j + 1));
				if (st[p] == 1) continue;
				st[p] = 1;
				now += dsu.size(p);
			}
		}
		// cerr << j << ' ' << now + cnt << '\n';
		rs = max(rs, now + cnt);
	}

	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
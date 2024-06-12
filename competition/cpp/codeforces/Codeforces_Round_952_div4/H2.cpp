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

	vector<int> er(n + 1, 0), ec(m + 1, 0);
	rep(i, 1, n) rep(j, 1, m) {
		if (g[i][j] == '.') {
			er[i]++;
			ec[j]++;
		}
	}
	vector<int> mem_r(n + 1, 0), mem_c(m + 1, 0);

	rep(i, 1, n) {
		int cnt = 0;
		rep(j, 1, m) if (g[i][j] == '.') cnt++;
		unordered_map<int, bool> st;
		int now = 0;

		rep(j, 1, m) if (g[i][j] == '#') {
			int p = dsu.find(hash(i, j));
			if (st[p] == 1) continue;
			st[p] = 1;
			now += dsu.size(p);
		}
		if (i >= 2) {
			rep(j, 1, m) if (g[i - 1][j] == '#') {
				int p = dsu.find(hash(i - 1, j));
				if (st[p] == 1) continue;
				st[p] = 1;
				now += dsu.size(p);
			}
		}
		if (i <= n - 1) {
			rep(j, 1, m) if (g[i + 1][j] == '#') {
				int p = dsu.find(hash(i + 1, j));
				if (st[p] == 1) continue;
				st[p] = 1;
				now += dsu.size(p);
			}
		}
		now += er[i];
		mem_r[i] = now;
	}

	rep(j, 1, m) {
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
		now += ec[j];
		mem_c[j] = now;
	}

	unordered_map<int, PII> dr, dc;
	vector<int> list;
	rep(i, 1, n) rep(j, 1, m) if (g[i][j] == '#') {
		int p = dsu.find(hash(i, j));

		if (dr[p].first == 0) {
			dr[p].first = i;
			dr[p].second = i;
			dc[p].first = j;
			dc[p].second = j;
			list.emplace_back(p);
			continue;
		}
		dr[p].first = min(dr[p].first, i);
		dr[p].second = max(dr[p].second, i);
		dc[p].first = min(dc[p].first, j);
		dc[p].second = max(dc[p].second, j);
	}

	vector<vector<int>> rc(n + 2, vector<int>(m + 2, 0));

	for (int p : list) {
		dr[p].first = max(dr[p].first - 1, 1);
		dr[p].second = min(dr[p].second + 1, n);
		dc[p].first = max(dc[p].first - 1, 1);
		dc[p].second = min(dc[p].second + 1, m);
		int sz = dsu.size(p);
		auto [r1, r2] = dr[p];
		auto [c1, c2] = dc[p];

		rc[r1][c1] += sz;
		rc[r2 + 1][c2 + 1] += sz;
		rc[r2 + 1][c1] -= sz;
		rc[r1][c2 + 1] -= sz;
	}

	rep(i, 1, n) rep(j, 1, m) {
		rc[i][j] += rc[i - 1][j] + rc[i][j - 1] - rc[i - 1][j - 1];
	}

	int rs = 0;

	rep(i, 1, n) rep(j, 1, m) {
		int now = mem_r[i] + mem_c[j] - rc[i][j];
		if (g[i][j] == '.') now--;
		rs = max(rs, now);
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
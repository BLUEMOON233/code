#include<bits/stdc++.h>
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define inf 0x3f3f3f3f
using namespace std;

int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>>adj(n);
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		x--;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	string s; cin >> s;
	vector<array<int, 3>>f(n, {inf, inf, inf});
	auto dfs = [&](auto self, int u, int p) -> void {
		for (auto v : adj[u]) {
			if (p == v) continue;
			self(self, v, u);
		}
		array<int, 3>g;
		if (s[u] == 'S') {
			g[2] = g[0] = inf;
			g[1] = 0;
			for (auto v : adj[u]) {
				if (p == v) continue;
				g[1] += min({f[v][0], f[v][1], f[v][2] + 1});
			}
		}
		if (s[u] == 'P') {
			g[1] = g[0] = inf;
			g[2] = 0;
			for (auto v : adj[u]) {
				if (p == v) continue;
				g[2] += min({f[v][0], f[v][1] + 1, f[v][2]});
			}
		}
		if (s[u] == 'C') {
			g[0] = g[1] = g[2] = 0;
			for (auto v : adj[u]) {
				if (p == v) continue;
				g[0] += min({f[v][0], f[v][1] + 1, f[v][2] + 1});
				g[1] += min({f[v][0], f[v][1], f[v][2] + 1});
				g[2] += min({f[v][0], f[v][1] + 1, f[v][2]});
			}
		}
		f[u] = g;
	};
	dfs(dfs, 0, -1);
	int rs = min({f[0][0], f[0][1], f[0][2]});
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
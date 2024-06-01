#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	vector<vector<int>> g(n + 1);
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	rep(i, 1, n) sort(g[i].begin(), g[i].end(), [&](int x, int y) {
		return a[x] > a[y];
	} );

	unordered_map<int, int> mp;
	auto hash = [](int a, int b, int c) -> int{
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		int code = a;
		code = code * 5007 + b;
		code = code * 5007 + c;
		return code;
	};

	int rs = 0;

	rep(now, 1, n) {
		if (g[now].empty()) {
			rs = max(rs, a[now]);
			continue;
		}
		if (g[now].size() == 1) {
			rs = max(rs, a[now] + a[g[now][0]]);
			continue;
		}

		int len = g[now].size();

		for (int i = 0; i <= len - 1; i++) for (int j = i + 1; j <= len - 1; j++) {
				int x = g[now][i], y = g[now][j];
				int code = hash(now, x, y);
				if (mp[code]) continue;
				// unordered_map<int, bool> in;

				int sum = a[now] + a[x] + a[y];

				int z;
				// in[now] = in[x] = in[y] = true;
				for (int next : g[x]) {
					if (next == now || next == x || next == y) continue;
					sum += a[next];
					z = next;
					break;
				}
				for (int next : g[y]) {
					if (next == now || next == x || next == y || next == z) continue;
					sum += a[next];
					break;
				}
				rs = max(rs, sum);
				mp[code] = sum;
			}
	}

	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

struct Node {
	int dist;
	int p;
	int dep;

	bool operator< (Node other) const {
		return dist > other.dist;
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<vector<int>> g(n + 1);

	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) a[i] = -a[i];
	rep(i, 1, m) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}



	int rs = 0;

	auto dijkstra = [&](int s) {
		priority_queue<Node> heap;
		vector<int> dist(n + 1, 0);
		vector<int> st(n + 1, 0);
		dist[s] = a[s];
		heap.push({a[s], s, 1});
		while (!heap.empty()) {
			auto [d, now, dep] = heap.top();
			heap.pop();
			if (st[now]) continue;
			st[now] = 1;

			rs = max(rs, -d);
			// cerr << "\nnode: " << - d << ' ' << now << ' ' << dep << '\n';

			if (dep == 5) continue;
			for (int next : g[now]) {
				// cerr << "next: " << dist[next] << ' ' << next << ' ' << dep + 1 << '\n';
				if (dist[next] > dist[now] + a[next]) {

					dist[next] = dist[now] + a[next];
					heap.push({dist[next], next, dep + 1});
				}
			}
			// vector<Node> save;
			// while (!heap.empty()) {
			// 	save.emplace_back(heap.top());
			// 	heap.pop();
			// }
			// for (Node node : save) {
			// 	cerr << "heap: " << - node.dist << ' ' << node.p << ' ' << node.dep << '\n';
			// 	heap.push(node);
			// }
		}
	};

	// dijkstra(1);
	rep(i, 1, n) dijkstra(i);
	cout << rs << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
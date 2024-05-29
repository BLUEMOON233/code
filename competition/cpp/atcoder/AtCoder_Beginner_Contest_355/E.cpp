#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

vector<vector<int>> g;

int ask(int l, int r) {
	int sig = 1;
	if (r < l) {
		swap(l, r);
		sig = -1;
	}
	int i = log2(r - l), j = l >> i;
	// cerr << l << ' ' << r << '\n';
	cout << "? " << i << ' ' << j << '\n';
	cout.flush();
	int ret = 0;
	cin >> ret;
	return sig * ret;
}

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	g.resize((1 << (n + 1)) + 1, vector<int>());
	rep(i, 0, n) for (int j = 0; j < (1 << n); j += (1 << i)) {
		g[j].emplace_back(j + (1 << i));
		g[j + (1 << i)].emplace_back(j);
	}
	queue<int> q;
	vector<int> dist((1 << (n + 1)) + 1, 0);
	q.push(l);
	dist[l] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next : g[now]) if (!dist[next]) {
				dist[next] = dist[now] + 1;
				q.push(next);
			}
	}
	int now = r + 1;
	int rs = 0;
	while (now != l) {
		for (int bef : g[now]) {
			if (dist[bef] + 1 == dist[now]) {
				rs = (rs + ask(bef, now) + 100) % 100;
				now = bef;
				break;
			}
		}
	}
	cout << "! " << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
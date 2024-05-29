#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

struct Node {
	int l, r;
	int idx = 0;
	bool const operator< (Node other) const {
		if (l != other.l) return l < other.l;
		if (r != other.r) return r < other.r;
		return idx < other.idx;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<Node> nodes(n + 1);
	rep(i, 1, n) cin >> nodes[i].l >> nodes[i].r;
	rep(i, 1, n) nodes[i].idx = i;
	sort(nodes.begin() + 1, nodes.end());
	int idx = 1;
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	vector<int> rs;
	rep(i, 0, n - 1) {
		while (idx <= n && nodes[idx].l <= i) {
			pq.push({nodes[idx].r, nodes[idx].idx});
			idx++;
		}
		while (!pq.empty() && pq.top().first < i) pq.pop();
		if (!pq.empty()) {
			rs.emplace_back(pq.top().second);
			pq.pop();
		} else break;
	}
	cout << rs.size() << '\n';
	for (int val : rs) cout << val << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
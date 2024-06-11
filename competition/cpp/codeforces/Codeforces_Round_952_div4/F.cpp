#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<LL, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const LL inf = 1e18;

void solve() {
	LL h, n;
	cin >> h >> n;
	vector<LL> a(n + 1), c(n + 1);
	// vector<LL> dp(h + 1, inf);
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> c[i];
	rep(i, 1, n) {
		h -= a[i];
		pq.emplace(c[i] + 1, i);
	}
	LL now = 1;
	while (!pq.empty()) {
		// cerr << now << ' ' << h << '\n';
		if (h <= 0) {
			cout << now << '\n';
			return;
		}
		auto [turn, p] = pq.top();
		// cerr << turn << ' ' << p << '\n';
		now = turn;
		pq.pop();
		h -= a[p];
		pq.emplace(turn + c[p], p);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

struct Fenwick {
	int n;
	vector<LL> tr;
	Fenwick(int n) {
		this->n = n;
		tr.resize(n + 2, 0);
	}
	inline LL lowbit(int x) {
		return x & -x;
	}
	inline void add(LL x, LL y) {
		for (LL i = x; i <= n; i += lowbit(i)) tr[i] += y;
	}
	LL getSum(LL x) {
		LL rs = 0;
		for (LL i = x; i; i -= lowbit(i)) rs += tr[i];
		return rs;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<PII> intervals(n + 1);
	rep(i, 1, n) cin >> intervals[i].first >> intervals[i].second;
	vector<int> pos(1, 0);
	rep(i, 1, n) pos.emplace_back(intervals[i].first), pos.emplace_back(intervals[i].second);
	sort(pos.begin() + 1, pos.end());
	pos.erase(unique(pos.begin() + 1, pos.end()), pos.end());
	int m = pos.size() - 1;
	unordered_map<int, int> mp;
	rep(i, 1, m) mp[pos[i]] = i;
	Fenwick tr_l(m);
	Fenwick tr_r(m);
	for (auto &[l, r] : intervals) {
		l = mp[l];
		r = mp[r];
	}
	sort(intervals.begin() + 1, intervals.end(), [](PII x, PII y) {
		if (x.second - x.first == y.second - y.first) return x.first < y.first;
		return x.second - x.first < y.second - y.first;
	});
	LL rs = 0;
	rep(i, 1, n) {
		auto [l, r] = intervals[i];
		cerr << l << ' ' << r << ": ";
		cerr << tr_r.getSum(l - 1) << ' ' << tr_l.getSum(m) - tr_l.getSum(r) << '\n';
		rs += (i - 1) - tr_r.getSum(l - 1) - tr_l.getSum(m) + tr_l.getSum(r);
		tr_r.add(r, 1), tr_l.add(l, 1);
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
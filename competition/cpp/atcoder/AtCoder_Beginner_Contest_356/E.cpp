#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

struct Fenwick {
	int n;
	std::vector<LL> a;
	Fenwick(int n) {init(n);}
	void init(int n) {
		this->n = n;
		a.resize(n + 1, 0);
	}

	void add(int x, LL v) {
		for (int i = x; i <= n; i += i & -i) a[i] += v;
	}
	LL sum(int x) {
		LL rs = 0LL;
		for (int i = x; i; i -= i & -i) rs += a[i];
		return rs;
	}
	LL rangeSum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<LL> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	Fenwick fenwick(1e6);
	rep(i, 1, n) fenwick.add(a[i], 1);
	// sort(a.begin() + 1, a.end());
	vector<LL> mem(1e6 + 1, -1);
	LL rs = 0;
	rep(i, 1, n) {
		if (mem[a[i]] != -1) {
			rs += mem[a[i]];
			continue;
		}
		LL now = -1;
		for (int l = a[i]; l <= 1e6; l += a[i]) {
			int r = min(l + a[i] - 1, 1000000LL);
			// cerr << max(l, 1) << ' ' << l + a[i] - 1 << '\n';
			now += fenwick.rangeSum(l, r) * l / a[i];
		}
		// cerr << a[i] << ' ' << now << '\n';
		mem[a[i]] = now;
		rs += now;
	}

	rep(i, 1, 1e6) {
		LL t = fenwick.rangeSum(i, i);
		rs -= t * (t - 1) / 2;
	}

	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
	return 0;
}
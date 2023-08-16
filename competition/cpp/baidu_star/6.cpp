#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

struct DSU {
	vector<int> p, Size;
	DSU(int n): p(n + 1), Size(n + 1, 1) {iota(p.begin(), p.end(), 0);}
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
	int n;
	cin >> n;
	vector<PII> a(n + 1);
	rep(i, 1, n) cin >> a[i].first >> a[i].second;
	sort(a.begin() + 1, a.end(), [](PII & x, PII & y) {
		if (x.first == y.first) return x.second < y.second;
		return x.first > y.first;
	});
	DSU dsu(n);
	int idx = 0, p = 0x3f3f3f3f, v = 0x3f3f3f3f;
	rep(i, 1, n) {
		auto [x, y] = a[i];
		if (y < v) idx = i, v = y, p = x;
		else if (y == v) {
			if (p != x) idx = i, v = y, p = x;
			else dsu.merge(idx, i);
		} else {
			dsu.merge(idx, i);
		}
	}
	int rs = 0;
	rep(i, 1, n) rs = max(rs, dsu.size(i));
	cout << rs << '\n';
}

int main() {
	fast();
	solve();
	return 0;
}
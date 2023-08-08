#include<bits/stdc++.h>
using i64 = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
map<int, int> id;
int idx = 0;
set<int> ls;

struct sgt {
	int l, r;
	int ri;
} tr[500000], tr1[500000];

void pushup(int u) {
	tr[u].ri = max(tr[u << 1].ri, tr[u << 1 | 1].ri);
}

void build(int u, int l, int r) {
	tr[u].l = l;
	tr[u].r = r;
	if (l == r) {
		tr[u].ri = -inf;
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void build1(int u, int l, int r) {
	tr1[u].l = l;
	tr1[u].r = r;
	if (l == r) {
		tr1[u].ri = -inf;
		return;
	}
	int mid = (l + r) >> 1;
	build1(u << 1, l, mid);
	build1(u << 1 | 1, mid + 1, r);
}

void update(int u, int pos, int x) {
	if (tr[u].l == tr[u].r && tr[u].l == pos) {
		tr[u].ri = max(x, tr[u].ri);
		return;
	}
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (pos <= mid) {
		update(u << 1, pos, x);
	}
	if (mid < pos) {
		update(u << 1 | 1, pos, x);
	}
	pushup(u);
}

int que(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) {
		return tr[u].ri;
	}
	int ans = -inf;
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid) {
		ans = max(ans, que(u << 1, l, r));
	}
	if (mid < r) {
		ans = max(ans, que(u << 1 | 1, l, r));
	}
	return ans;
}

void pushup1(int u) {
	tr1[u].ri = max(tr1[u << 1].ri, tr1[u << 1 | 1].ri);
}

void update1(int u, int pos, int x) {
	if (tr1[u].l == tr1[u].r && tr1[u].l == pos) {
		tr1[u].ri = max(x, tr1[u].ri);
		return;
	}
	int mid = (tr1[u].l + tr1[u].r) >> 1;
	if (pos <= mid) {
		update1(u << 1, pos, x);
	}
	if (mid < pos) {
		update1(u << 1 | 1, pos, x);
	}
	pushup1(u);
}

int que1(int u, int l, int r) {
	if (l <= tr1[u].l && tr1[u].r <= r) {
		return tr1[u].ri;
	}
	int ans = -inf;
	int mid = (tr1[u].l + tr1[u].r) >> 1;
	if (l <= mid) {
		ans = max(ans, que1(u << 1, l, r));
	}
	if (mid < r) {
		ans = max(ans, que1(u << 1 | 1, l, r));
	}
	return ans;
}

void slv() {
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	i64 ans = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], ls.insert(a[i]);
	for (int i = 1; i <= n; i++) cin >> b[i], ans += abs(a[i] - b[i]), ls.insert(b[i]);
	for (auto i : ls) {
		id[i] = ++idx;
	}
	int le_a = inf, le_b = inf;
	i64 cnt_a = 0, cnt_b = 0; //左端点分别为a,b
	vector<pair<int, int>> ve;
	for (int i = 1; i <= n; ++i) {
		ve.push_back({a[i], b[i]});
	}
	sort(ve.begin(), ve.end(), [](pair<int, int> &x, pair<int, int> &y) {
		if (max(x.first, x.second) == max(y.first, y.second)) return x.first < y.first;
		return max(x.first, x.second) < max(y.first, y.second);
	});
	build(1, 1, idx);
	build1(1, 1, idx);
	for (int i = 0; i < n; i++) {
		i64 cnt = ans;
		int aa = ve[i].first, bb = ve[i].second;
		if (aa <= bb) {
			//ai<bi
			if (le_b < aa) {
				cnt -= 2 * (que(1, 1, id[aa]) - aa);
			} else {
				cnt -= 2 * cnt_b;
			}
			update1(1, id[aa], bb);
			le_a = min(le_a, aa);
			cnt_a = max(cnt_a, (i64)(bb - aa));
		} else {
			//bi<ai
			if (le_a < bb) {
				cnt -= 2 * (que1(1, 1, id[bb]) - bb);
			} else {
				cnt -= 2 * cnt_a;
			}
			update(1, id[bb], aa);
			le_b = min(le_b, bb);
			cnt_b = max(cnt_b, (i64)(aa - bb));
		}
		ans = min(ans, cnt);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
//     cin>>_;
	while (_--) slv();
}
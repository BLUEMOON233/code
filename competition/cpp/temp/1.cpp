#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define mes(tmp, data) memset(tmp, data, sizeof tmp)
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << " = " << x << endl;
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout<<tmp[i]<<" \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout<<tmp[i]<<" \n"[i == Size]
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
template<class T>
inline T read() {
	T x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
template<class T>
inline void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
	return;
}
#define read() read<int>()
#define write(tmp) write<int>(tmp);
//#define read() read<LL>()
//#define write(tmp) write<LL>(tmp);
//#define read() read<__int128>()
//#define write(tmp) write<__int128>(tmp);

const int N = 1e6 + 7;

LL w[N], n, m;
struct Node {
	int l, r;
	LL sum, add;
} tr[N << 2];
void pushup(int u) {
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void pushdown(int u) {
	Node &rt = tr[u], &lp = tr[u << 1], &rp = tr[u << 1 | 1];
	if (rt.add) {
		lp.add += rt.add, lp.sum += (LL)(lp.r - lp.l + 1) * rt.add;
		rp.add += rt.add, rp.sum += (LL)(rp.r - rp.l + 1) * rt.add;
		rt.add = 0;
	}
}
void build(int u, int l, int r) {
	if (l == r) tr[u] = {l, r, w[l], 0};
	else {
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r, LL v) {
	if (l <= tr[u].l && tr[u].r <= r) {
		tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * v;
		tr[u].add += v;
	} else {
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if (l <= mid) modify(u << 1, l, r, v);
		if (r > mid) modify(u << 1 | 1, l, r, v);
		pushup(u);
	}
}
LL query(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	LL rs = 0;
	if (l <= mid) rs = query(u << 1, l, r);
	if (r > mid) rs += query(u << 1 | 1, l, r);
	return rs;
}

inline void solve() {
	int n, q;
	cin >> n >> q;
	rep(i, 1, n) cin >> w[i];
	build(1, 1, n);
	while (q--) {
		int opt, l, r, x;
		cin >> opt;
		if (opt == 1) {
			cin >> l >> r >> x;
			modify(1, l, r, x);
		} else {
			cin >> l >> r;
			cout << query(1, l, r) << '\n';
		}
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

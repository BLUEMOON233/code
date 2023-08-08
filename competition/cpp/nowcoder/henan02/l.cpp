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

const int N = 1e5 + 7;

int n, m;
int w[N];
struct Node {
	int l, r;
	int mx, mn;
} tr[N << 2];

//建树
void build(int d, int l, int r) {
	tr[d].l = l, tr[d].r = r;
	if (l == r) {
		tr[d].mx = w[l];
		tr[d].mn = w[l];
		return;
	}
	int mid = (l + r) / 2;
	int lc = d * 2;
	int rc = d * 2 + 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	tr[d].mx = max(tr[lc].mx, tr[rc].mx);
	tr[d].mn = min(tr[lc].mn, tr[rc].mn);
}

LL query_max(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) return tr[u].mx;
	int mid = (tr[u].l + tr[u].r) >> 1;
	LL rs = -1;
	if (l <= mid) rs = max(rs, query_max(u << 1, l, r));
	if (r > mid) rs = max(rs, query_max(u << 1 | 1, l, r));
	return rs;
}

LL query_min(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) return tr[u].mn;
	int mid = (tr[u].l + tr[u].r) >> 1;
	LL rs = 0x3f3f3f3f;
	if (l <= mid) rs = min(rs, query_min(u << 1, l, r));
	if (r > mid) rs = min(rs, query_min(u << 1 | 1, l, r));
	return rs;
}

void modify(int d, int pos, int v) {
	if (tr[d].l == tr[d].r && tr[d].l == pos) {
		tr[d].mx = tr[d].mn = v;
		return;
	}
	int mid = (tr[d].l + tr[d].r) / 2;
	int lc = d * 2;
	int rc = d * 2 + 1;
	if (pos > mid) {
		modify(rc, pos, v);
	}
	else {
		modify(lc, pos, v);
	}
	tr[d].mx = max(tr[lc].mx, tr[rc].mx);
	tr[d].mn = min(tr[lc].mn, tr[rc].mn);
}

inline void solve() {
	cin >> n >> m;
	rep(i, 1, n) {
		char c;
		cin >> c;
		w[i] = int(c - 'a' + 1);
	}
	build(1, 1, n);
	while (m--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int l, r;
			cin >> l >> r;
			int x = 1, y = r - l + 1;
			LL rsl, rsr;
			while (x < y) {
				int len = (x + y) >> 1;
				bool flag = false;
				rep(j, 1, n - len + 1) {
					int ll = j, rr = j + len - 1;
					if (query_max(1, ll, rr) == query_min(1, ll, rr)) {
						flag = true;
						rsl = ll, rsr = rr;
						break;
					}
				}
				if (!flag) y = len;
				else x = len + 1;
			}
			cout << rsl << ' ' << rsr << '\n';
		} else {
			int x;
			char c;
			cin >> x >> c;
			modify(1, x, int(c - 'a' + 1));
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

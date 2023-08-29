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

const int N = 2e5 + 7, mod = 998244353;

LL quickPow(LL a, LL b, LL mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}

int n;
vector<vector<int>> g;
vector<int> sz;
vector<int> rs;

struct DSU {
	vector<int> p;
	DSU(int n) : p(n + 1) { iota(p.begin(), p.end(), 0);}
	int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
	bool same(int x, int y) {return find(x) == find(y);}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		p[y] = x;
		return true;
	}
} dsu(1);

int dfs_sz(int now) {
	for (auto nxt : g[now]) {
		sz[now] += dfs_sz(nxt);
	}
	return sz[now];
}

void dfs(int now, LL add) {
	LL s = 0;
	if (now <= n) rs[now] = add;
	for (auto nxt : g[now]) s += sz[nxt];
	// cout << s << '\n';
	s = quickPow(s, mod - 2, mod);
	for (auto nxt : g[now]) {
		// cout << now << ' ' << nxt << ' ' << sz[nxt] << '\n';
		dfs(nxt, (add + s * sz[nxt] % mod) % mod);
	}
}

inline void solve() {
	cin >> n;
	g.resize(n << 1);
	sz.resize(n << 1, 0);
	rs.resize(n + 1);
	DSU dsuu(2 * n - 1);
	dsu = dsuu;
	rep(i, 1, n) sz[i] = 1;
	rep(i, 1, n - 1) {
		int a, b;
		cin >> a >> b;
		a = dsu.find(a), b = dsu.find(b);
		g[n + i].emplace_back(a);
		g[n + i].emplace_back(b);
		dsu.merge(n + i, a);
		dsu.merge(n + i, b);
	}
	dfs_sz(2 * n - 1);
	dfs(2 * n - 1, 0);
	rep(i, 1, n) cout << rs[i] << " \n"[i == n];
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

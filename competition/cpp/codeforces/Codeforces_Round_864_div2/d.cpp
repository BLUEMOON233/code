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
LL e[N << 1], ne[N << 1], h[N], idx = 0;
LL w[N], sum[N];
inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

LL fa[N], sz[N];
void init(int u, int father) {
	fa[u] = father;
	for (int i = h[u]; i; i = ne[i]) {
		int j = e[i];
		if (j == father) continue;
		init(j, u);
		sz[u] += sz[j];
		sum[u] += sum[j];
	}
	sz[u]++;
	sum[u] += w[u];
}

void modify(int u) {
	if (sz[u] == 1) return;
	LL father = fa[u];
	LL heavy_son = 0x3f3f3f3f, max_size = -1;
	for (int i = h[u]; i; i = ne[i]) {
		int j = e[i];
		if (j == father) continue;
		if(max_size < sz[j]) max_size = sz[j], heavy_son = j;
		if(max_size == sz[j] && j < heavy_son) max_size = sz[j], heavy_son = j;
	}
	fa[heavy_son] = father;
	fa[u] = heavy_son;
	for (int i = h[father]; i; i = ne[i]) {
		int j = e[i];
		if (j == fa[father]) continue;
		if (j == u) {
			e[i] = heavy_son;
			break;
		}
	}
	LL tmp_sz = sz[u];
	LL tmp_sum = sum[u];
	sz[u] -= sz[heavy_son];
	sum[u] -= sum[heavy_son];
	sz[heavy_son] = tmp_sz;
	sum[heavy_son] = tmp_sum;
}

inline void solve() {
	LL n, m, u, v;
	cin >> n >> m;
	rep(i, 1, n) cin >> w[i];
	rep(i, 1, n - 1) {
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	init(1, 0);
	// debug1(fa, n);
	// debug1(sum, n);
	while (m--) {
		LL opt, x;
		cin >> opt >> x;
		if (opt == 1) {
			cout << sum[x] << '\n';
		} else {
			modify(x);
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

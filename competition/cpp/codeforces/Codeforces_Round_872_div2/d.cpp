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

const int N = 2e5 + 7, mod = 1e9 + 7;

int h[N], e[N << 1], ne[N << 1], idx = 0;
int n, k, u, v;
LL sz[N], rs = 0;

LL quickPow(LL a, LL b, LL mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}

inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void dfs(int u, int fa) {
	for (int i = h[u]; i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		dfs(j, u);
		rs = (rs + sz[j] * (n - sz[j]) % mod) % mod;
		sz[u] += sz[j];
	}
}

inline void solve() {
	cin >> n >> k;
	rep(i, 1, n) sz[i] = 1;
	rep(i, 1, n - 1) {cin >> u >> v; add(u, v), add(v, u);}
	if (k == 1 || k == 3) {
		cout << 1 << '\n';
		return;
	}
	dfs(1, 0);
	cout << (rs * quickPow((LL)n * (n - 1) / 2 % mod, mod - 2, mod) + 1) % mod << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

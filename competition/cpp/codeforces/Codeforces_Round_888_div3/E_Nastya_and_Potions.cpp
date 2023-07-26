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

const int N = 2e5 + 7;
int h[N], e[N], ne[N], idx = 0;
LL d[N];
bool st[N];
inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

LL dfs(int now) {
	if (st[now]) return d[now];
	LL rs = 0;
	if (!h[now]) rs += 1e18;
	for (int i = h[now]; i; i = ne[i]) {
		int j = e[i];
		rs += dfs(j);
	}
	// cout << now << ": " << rs << '\n';
	d[now] = min(d[now], rs);
	st[now] = true;
	return d[now];
}

inline void solve() {
	idx = 0;
	int n, k;
	cin >> n >> k;
	rep(i, 1, n) h[i] = st[i] = 0;
	rep(i, 1, n) cin >> d[i];
	queue<int> q;
	while (k--) {
		int t;
		cin >> t;
		d[t] = 0;
	}
	rep(i, 1, n) {
		int sz;
		cin >> sz;
		rep(j, 1, sz) {
			int k;
			cin >> k;
			add(i, k);
		}
	}
	rep(i, 1, n) dfs(i);
	rep(i, 1, n) cout << d[i] << " \n"[i == n];
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

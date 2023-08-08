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
//#define read() read<LL>()//#define write(tmp) write<LL>(tmp);
//#define read() read<__int128>()
//#define write(tmp) write<__int128>(tmp);

const int N = 1e6 + 7;
int w[N], h[N], e[N], ne[N], idx = 0;
inline void add(int a, int b, int c) {
	e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}
bool st[N];
int d[N];
bool dfs(int now) {
	if (st[now]) return false;
	st[now] = true;
	for (int i = h[now]; i; i = ne[i]) {
		int j = e[i];
		if (dfs(j)) w[i] = 0, d[j]++;
	}
	return true;
}




inline void solve() {
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		add(a, b, 1);
	}
	rep(i, 1, n) {
		dfs(i);
	}
	cout << endl;
	int sz = n;
	vector<int> rs1(n + 1, 0);
	queue<int> q;
	// rep(i, 1, n) cout << d[i] << ' ';
	// cout << endl;
	rep(i, 1, n) if (d[i] == 0) q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		// cout << now << '\n';
		rs1[now] = sz--;
		for (int i = h[now]; i ; i = ne[i]) {
			if (w[idx] == 1) continue;
			int j = e[i];
			q.push(e[i]);
		}
	}
	rep(i, 1, n) cout << rs1[i] << ' ';
	cout << '\n';
}

int main() {
	// fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}


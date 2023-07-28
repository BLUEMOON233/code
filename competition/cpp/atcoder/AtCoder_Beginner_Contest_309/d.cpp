#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<LL, LL> PII;
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

const int N = 3e5 + 7;
int h[N], e[N << 1], ne[N << 1], idx = 0;
int n1, n2, m;
inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

LL bfs(int st) {
	queue<PII> q;
	q.push({st, 0});
	vector<bool> in(n1 + n2 + 1, false);
	in[st] = true;
	LL max_len = -1;
	while (!q.empty()) {
		auto [now, len] = q.front();
		// cout << now << ' ' << len << '\n';
		q.pop();
		max_len = max(max_len, 1LL * len);
		for (int i = h[now]; i; i = ne[i]) {
			int j = e[i];
			if (in[j]) continue;
			in[j] = true;
			q.push({j, len + 1});
		}
	}
	return max_len;
}

inline void solve() {
	cin >> n1 >> n2 >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	LL l1 = bfs(1);
	LL l2 = bfs(n1 + n2);
	// cout << l1 << ' ' << l2 << '\n';
	cout << l1 + l2 + 1 << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

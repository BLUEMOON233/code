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

const int N = 1e3 + 7, M = 1e4 + 7;

int k, n, m;
int e[M], ne[M], h[N], idx = 0;
int cnt[N];
inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void bfs(int x) {
	vector<bool> f(n + 1, false);
	queue<int> q;
	q.push(x), f[x] = true;
	cnt[x]++;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = h[now]; i; i = ne[i]) {
			int j = e[i];
			if (f[j]) continue;
			q.push(j), f[j] = true;
			cnt[j]++;
		}
	}
}

inline void solve() {
	int a, b;
	cin >> k >> n >> m;
	vector<int> cow(k + 1);
	rep(i, 1, k) cin >> cow[i];
	while (m--) {
		cin >> a >> b;
		add(a, b);
	}
	for (auto x : cow) bfs(x);
	LL rs = 0;
	rep(i, 1, n) if (cnt[i] == k) rs++;
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
// 	cin >> T;
	while (T--) solve();
}
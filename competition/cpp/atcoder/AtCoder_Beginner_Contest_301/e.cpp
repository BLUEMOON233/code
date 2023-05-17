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

inline void solve() {
	int h, w, t;
	cin >> h >> w >> t;
	vector g(h + 2, vector<char>(w + 2, '#'));
	rep(i, 1, h) rep(j, 1, w) cin >> g[i][j];
	vector<pair<int, int> > p;
	rep(i, 1, h) rep(j, 1, w) if (g[i][j] == 'S') p.push_back({i, j});
	rep(i, 1, h) rep(j, 1, w) if (g[i][j] == 'o') p.push_back({i, j});
	rep(i, 1, h) rep(j, 1, w) if (g[i][j] == 'G') p.push_back({i, j});
	int N = p.size();
	vector dis(N, vector<int>(N, -1));
	rep(i, 0, N - 1) {
		queue<pair<int, int> > q;
		vector d(h + 2, vector<int>(w + 2, -1));
		q.push(p[i]);
		d[p[i].first][p[i].second] = 0;
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			if (d[x + 1][y] == -1 && g[x + 1][y] != '#') {d[x + 1][y] = d[x][y] + 1; q.push({x + 1, y});}
			if (d[x - 1][y] == -1 && g[x - 1][y] != '#') {d[x - 1][y] = d[x][y] + 1; q.push({x - 1, y});}
			if (d[x][y + 1] == -1 && g[x][y + 1] != '#') {d[x][y + 1] = d[x][y] + 1; q.push({x, y + 1});}
			if (d[x][y - 1] == -1 && g[x][y - 1] != '#') {d[x][y - 1] = d[x][y] + 1; q.push({x, y - 1});}
		}
		rep(j, 0, N - 1) dis[i][j] = d[p[j].first][p[j].second];
	}
	vector dp(1 << N, vector(N, t + 1));
	dp[1][0] = 0;
	LL rs = -1;
	for (int s = 1; s < (1 << N); s += 2)
		rep(i, 0, N - 1) if (s >> i & 1) rep(j, 0, N - 1)
			if ((~s >> j & 1) && dis[i][j] != -1)
				dp[s | 1 << j][j] = min(dp[s | 1 << j][j], dp[s][i] + dis[i][j]);
	for (int s = 1; s < (1 << N); s += 2)
		if (dp[s][N - 1] <= t)
			rs = max(rs, __builtin_popcount(s) - 2LL);
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

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

const int N = 107;

LL dp[N][N][15][2];

inline void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
	rep(i, 0, n) rep(j, 0, n) rep(k, 0, 14) rep(kk, 0, 1) dp[i][j][k][kk] = 0x3f3f3f3f;
	rep(i, 1, n) rep(j, 1, n) cin >> g[i][j];
	dp[1][1][0][0] = dp[1][1][0][1] = g[1][1];
	rep(i, 1, n) rep(j, 1, n) rep(k, 0, min(n, 14)) {
		dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j - 1][k][0] + g[i][j]);
		dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][1] + g[i][j]);
		if (k) dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k - 1][1] + g[i][j] + (1 << (k - 1)));
		if (k) dp[i][j][k][1] = min(dp[i][j][k][1], dp[i][j - 1][k - 1][0] + g[i][j] + (1 << (k - 1)));
	}
	LL rs = 1e18 + 7;
	rep(k, 0, min(n, 14)) rs = min(rs, min(dp[n][n][k][1], dp[n][n][k][0]));
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}
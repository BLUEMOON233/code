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

const int N = 1;

inline void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> c(n + 1);
	vector<vector<int>> s(n + 1);
	rep(i, 1, n) {
		cin >> c[i];
		int t;
		cin >> t;
		s[i].resize(t + 1);
		rep(j, 1, t) cin >> s[i][j];
		s[i][0] = t;
	}
	vector<double> dp(m << 1 | 1, 1e10);
	dp[0] = 0;
	rep(i, 1, m << 1) {
		rep(j, 1, n) {
			double now = 0;
			rep(k, 1, s[j][0]) if (i >= s[j][k] && s[j][k]) now += dp[i - s[j][k]];
			int cnt = 0;
			rep(k, 1, s[j][0]) if (s[j][k] == 0) cnt++;
			now += (double)c[j] * s[j][0];
			now /= s[j][0] - cnt;
			dp[i] = min(dp[i], now);
		}
	}
	double rs = 1e10;
	rep(i, m, m << 1) rs = min(rs, dp[i]);
	cout << fixed << setprecision(18) << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

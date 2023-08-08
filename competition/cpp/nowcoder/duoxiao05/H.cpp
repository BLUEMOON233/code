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

const int N = 207;
LL dp[N][N][N];// i: times, j: get j-th object, k

inline void solve() {
	int n, m;
	cin >> n >> m;
	vector<LL> a(n + 1), b(n + 1), sz(m + 1);
	rep(i, 1, n) cin >> a[i] >> b[i];
	rep(i, 1, m) cin >> sz[i];
	rep(i, max(1, m - n + 1), m) rep(j, 0, n) rep(k, 0, 200) dp[i][j][k] = -1e18;

	rep(i, max(1, m - n + 1), m) {
		LL max_val = -1;
		rep(j, 1, n) {
			rep(k, 0, 200) max_val = max(max_val, dp[i - 1][j][k]);
			rep(k, 0, 200) dp[i][j][k] = max_val;
		}
		rep(j, 1, n) {
			per(k, sz[i], a[j]) {
				dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - 1][k - a[j]] + b[j]);
				// cout << dp[i][j][k] << '\n';
			}
		}

	}
	LL rs = 0;
	rep(k, 0, 200) rs = max(rs, dp[m][n][k]);
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

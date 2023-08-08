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

const int N = 1, mod = 998244353;

inline void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> dp(2 * m + 1, 1);
	rep(i, 2, n) {
		vector<int> g(2 * m + 1);
		rep(j, 0, 2 * m) {
			if (j < m) { // 为负数
				g[m] = (g[m] + dp[j]);
				g[m + j + 1] = (g[m + j + 1] - dp[j] + mod) % mod;
			} else {
				g[2 * m - j] = (g[2 * m - j] + dp[j]) % mod;
			}
		}
		rep(j, 1, 2 * m) g[j] = (g[j] + g[j - 1]) % mod;
		swap(dp, g);
	}
	LL rs = 0;
	rep(i, 0, 2 * m) rs = (rs + dp[i]) % mod;
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

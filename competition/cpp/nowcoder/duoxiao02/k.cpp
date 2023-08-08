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

const int N = 1e6 + 7;
LL a[N];
bool lip[N], st[N];
LL dp[N][4];

inline void solve() {
	int n;
	cin >> n;
	rep(i, 0, n) rep(j, 0, 3) dp[i][j] = -1e18;
	dp[1][0] = 0;
	bool f = true;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		cin >> lip[i];
		if (!lip[i]) f = false;
	}
	if (f) {
		LL rs = 0;
		rep(i, 1, n) rs += a[i];
		cout << rs << '\n';
		return;
	}
	int len = n;
	while (lip[n]) n--;
	rep(i, 2, n) {
		if (!lip[i - 1]) dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
		if (lip[i - 1]) {
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + a[i];
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]}) + a[i - 1];
			if (i >= 2 && lip[i - 2] == false) {
				st[i] = true;
				dp[i][3] = max({dp[i - 2][0], dp[i - 2][2], dp[i - 2][3]}) + a[i - 2];
			}
			if (i >= 3 && lip[i - 2] == true) {
				st[i] = true;
				if (!st[i - 2]) dp[i][3] = dp[i - 1][3] + a[i - 2];
				else dp[i][3] = dp[i - 2][3] + a[i - 2] + a[i - 3];
			}
		}
	}
	LL minCost = 1e18 + 7;
	rep(i, n, len) minCost = min(minCost, a[i]);
	LL rs = 0;
	rep(i, n, len) rs += a[i];
	cout << max(max({dp[n][0], dp[n][2], dp[n][3]}) + rs - minCost, dp[n][1] + rs - a[n]) << '\n';

}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

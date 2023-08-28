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

const int N = 1e4 + 7, M = 31;
double dp[N][M];

struct Node {
	double x, y;
};

vector<Node> a;

double dis(int i, int j) {
	double x = a[i].x - a[j].x;
	double y = a[i].y - a[j].y;
	return sqrt(x * x + y * y);
}

double val(int C) {
	if (C == 0) return 0;
	else return pow(2, C - 1);
}

inline void solve() {
	int n;
	cin >> n;
	a.resize(n + 1);
	rep(i, 1, n) cin >> a[i].x >> a[i].y;
	rep(i, 2, n) rep(j, 0, 30) dp[i][j] = 1e10;
	rep(i, 2, n) {
		rep(j, 0, 30) {
			rep(k, 0, j) {
				if (i - k - 1 >= 1)
					dp[i][j] = min(dp[i][j], dp[i - k - 1][j - k] + dis(i, i - k - 1) + val(j) - val(j - k));
			}
		}
	}
	double rs = 1e10;
	rep(j, 0, 30) {
		rs = min(rs, dp[n][j]);
	}
	cout << fixed << setprecision(12) << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

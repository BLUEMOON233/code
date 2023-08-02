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
	vector<vector<char> > g(n + 1, vector<char>(m + 1, '.'));
	vector<vector<int> > a(n + 1, vector<int>(m + 1, 0));
	rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
	rep(i, 1, n) rep(j, 1, m) a[i][j] = (g[i][j] == '#');
	rep(i, 1, n) rep(j, 1, m) a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	rep(i, 1, n - 8) rep(j, 1, m - 8) {
		if (a[i + 2][j + 2] + a[i - 1][j - 1] - a[i - 1][j + 2] - a[i + 2][j - 1] == 9) {
			if (a[i + 3][j + 3] + a[i - 1][j - 1] - a[i - 1][j + 3] - a[i + 3][j - 1] == 9) {
				if (a[i + 8][j + 8] + a[i + 5][j + 5] - a[i + 5][j + 8] - a[i + 8][j + 5] == 9) {
					if (a[i + 8][j + 8] + a[i + 4][j + 4] - a[i + 4][j + 8] - a[i + 8][j + 4] == 9) {
						cout << i << ' ' << j << '\n';
					}
				}
			}
		}
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

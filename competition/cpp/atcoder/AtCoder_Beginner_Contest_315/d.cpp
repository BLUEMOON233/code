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
	vector<vector<char>> g(n + 1, vector<char>(m + 1));
	rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
	vector<vector<int>> r(n + 1, vector<int>(26, 0)), c(m + 1, vector<int>(26, 0));
	rep(i, 1, n) rep(j, 1, m) r[i][g[i][j] - 'a']++, c[j][g[i][j] - 'a']++;
	bool f = true;
	while (f) {
		f = false;
		vector<PII> dr, dc;
		rep(i, 1, n) {
			int cnt = 0;
			int del = 0;
			rep(j, 0, 25) if (r[i][j]) cnt++, del = j;
			if (cnt == 1 && r[i][del] >= 2) {
				f = true;
				dr.emplace_back(i, del);
				// r[i][del] = 0;
				// rep(i, 1, m) if (c[i][del]) c[i][del]--;
			}
		}
		rep(i, 1, m) {
			int cnt = 0;
			int del = 0;
			rep(j, 0, 25) if (c[i][j]) cnt++, del = j;
			if (cnt == 1 && c[i][del] >= 2) {
				f = true;
				dc.emplace_back(i, del);
				// c[i][del] = 0;
				// rep(i, 1, n) if (r[i][del]) r[i][del]--;
			}
		}
		for (auto [i, del] : dr) {
			r[i][del] = 0;
			rep(i, 1, m) if (c[i][del]) c[i][del]--;
		}
		for (auto [i, del] : dc) {
			c[i][del] = 0;
			rep(i, 1, n) if (r[i][del]) r[i][del]--;
		}
		// rep(i, 1, n) rep(j, 0, 25) cout << r[i][j] << " \n"[j == 25];
	}
	LL rs = 0;
	rep(i, 1, n) rep(j, 0, 25) rs += r[i][j];
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

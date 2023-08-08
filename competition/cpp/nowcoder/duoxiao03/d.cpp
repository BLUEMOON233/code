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
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> tmp(n + 1, vector<int>(n + 1, 0));
	rep(i, 1, n) rep(j, 1, n) {
		char c;
		cin >> c;
		g[i][j] = c - '0';
	}
	int cnt0 = 0, cnt1 = 0;
	rep(i, 1, n) if (g[i][1] == 0) cnt0++;
	else cnt1++;

	int tar = (cnt0 < cnt1) ? 0 : 1;
	LL rs = 0;
	rs += min(cnt0, cnt1);
	rep(i, 1, n) {
		if (g[i][1] == tar) {
			rep(j, 1, n) tmp[i][j] = 1 - g[i][j];
		} else {
			rep(j, 1, n) tmp[i][j] = g[i][j];
		}
	}


	// rep(i, 1, n) {
	// 	rep(j, 1, n) cout << tmp[i][j];
	// 	cout << endl;
	// }
	// cout << endl;

	cnt0 = 0, cnt1 = 0;
	rep(i, 1, n) if (tmp[1][i] == 0) cnt0++;
	else cnt1++;
	tar = (cnt0 < cnt1) ? 0 : 1;
	rs += min(cnt0, cnt1);
	rep(i, 1, n) {
		if (tmp[1][i] == tar) {
			rep(j, 1, n) tmp[j][i] = 1 - tmp[j][i];
		} else {
			rep(j, 1, n) tmp[j][i] = tmp[j][i];
		}
	}
	rep(i, 1, n) rep(j, 1, n) {
		if (tmp[i][j] != tmp[1][1]) {
			cout << -1 << '\n';
			return;
		}
	}
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

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
	cin >> n;
	string s;
	cin >> s;
	s = '@' + s;
	int f = 0;
	cin >> m;
	vector<pair<int, char>> final;
	rep(i, 1, m) {
		int t, x;
		char c;
		cin >> t >> x >> c;
		if (t == 1) {
			s[x] = c;
			final.emplace_back(x, c);
		} else if (t == 2) {
			final.clear();
			f = -1;
		} else if (t == 3) {
			final.clear();
			f = 1;
		}
	}
	if (f == 1) rep(i, 1, n) if ('a' <= s[i] && s[i] <= 'z') s[i] += 'A' - 'a';
	if (f == -1) rep(i, 1, n) if ('A' <= s[i] && s[i] <= 'Z') s[i] += 'a' - 'A';
	for (auto [x, c] : final) s[x] = c;
	rep(i, 1, n) cout << s[i];
	cout << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

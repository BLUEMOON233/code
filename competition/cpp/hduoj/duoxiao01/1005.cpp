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

string minCycStr(string &str) {
	int i = 0, j = 1, k = 0;
	int len = str.size();
	while (i < len && j < len && k < len) {
		int t = str[(i + k) % len] - str[(j + k) % len];
		if (t == 0) k++;
		else {
			if (t > 0) i += k + 1;
			else j += k + 1;
			if (i == j) j++;
			k = 0;
		}
	}
	int minPos = i < j ? i : j;
	return str.substr(minPos, len - minPos) + str.substr(0, minPos);
}

inline void solve() {
	int n, m, q;
	cin >> n >> m;
	vector<string> str(n + 1);
	rep(i, 1, n) cin >> str[i];
	rep(i, 1, n) str[i] = minCycStr(str[i]);
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << ((str[x] == str[y]) ? "Yes\n" : "No\n");
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

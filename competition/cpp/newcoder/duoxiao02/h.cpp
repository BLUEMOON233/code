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
	LL n, q;
	cin >> n >> q;
	string opt;
	cin >> opt;
	opt = '@' + opt;
	vector<LL> pre1(n + 1, 0), pre2(n + 1, 0);
	rep(i, 1, n) pre1[i] = pre1[i - 1] + (opt[i] == 'A');
	rep(i, 1, n) pre2[i] = pre2[i - 1] + (pre1[i - 1] % 2 == 1 ? -1 : 1);
	// debug1(pre1, n);
	// debug1(pre2, n);
	LL rs = 0;
	while (q--) {
		LL ll, rr, now = 0;
		string x;
		cin >> ll >> rr >> x;
		LL l = min((rs ^ ll) % n + 1, (rs ^ rr) % n + 1);
		LL r = max((rs ^ ll) % n + 1, (rs ^ rr) % n + 1);
		for (auto c : x) {
			now <<= 1;
			now += LL(c - '0');

		};
		now += (pre2[r] - pre2[l - 1]) * (pre1[l - 1] % 2 == 1 ? -1 : 1);
		if ((pre1[r] - pre1[l - 1]) % 2 == 1) now = -now;
		LL mod = 1LL << x.size();
		rs = (now % mod + mod) % mod;
		per(i, x.size() - 1, 0) cout << ((rs >> i) & 1);
		cout << '\n';
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

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
// #define read() read<int>()
// #define write(tmp) write<int>(tmp);
//#define read() read<LL>()
//#define write(tmp) write<LL>(tmp);
#define read() read<__int128>()
#define write(tmp) write<__int128>(tmp);

const __int128 mod = 998244353;

__int128  quickPow(__int128 a, __int128 b, __int128 mod) {
	__int128 rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}

inline void solve() {
	__int128 n, x;
	n = read();
	x = read();
	x %= mod;
	if (x == 1) {
		__int128 rs = quickPow(2, n + 1, mod);
		write(rs);
		putchar('\n');
		return;
	}
	__int128 e = quickPow(2, (n + 1) % (mod - 1), mod);
	__int128 xx = quickPow(x - 1, mod - 2, mod);
	__int128 rs = (quickPow(x, e, mod) - 1 + mod) % mod * xx % mod;
	write(rs);
	putchar('\n');
}

int main() {
	fast();
	int T = 1;
	while (T--) solve();
}

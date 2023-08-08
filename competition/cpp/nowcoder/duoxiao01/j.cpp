#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(LL i=LL(j);i<=LL(k);i++)
#define per(i,j,k) for(LL i=LL(j);i>=LL(k);i--)
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
LL n, m;

LL quickPow(LL a, LL b, LL mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}

inline void solve() {
	cin >> n >> m;
	LL l, r;
	LL lst = 1;
	LL rs = 1;
	rep(k, 1, 31) {
		LL d = quickPow(pow(2, k), mod - 2, mod);
		LL q = (1 - d + mod) % mod;
		l = pow(2, k) - 1, r = pow(2, k + 1) - 2;
		if (l > n + m) break;
		l = max(l, n), r = min(r, n + m - 1);
		if (l > r) continue;
		rs = rs * quickPow(q, r - l + 1, mod) % mod;
		// cout << l << ' ' << r << '\n';
	}
	cout << rs << '\n';
	// cout << (1 - rs + mod) % mod << '\n';
}

int main() {
	// fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

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

const int N = 1e5 + 7, mod = 1e9 + 7;

LL quickPow(LL a, LL b, LL mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}

LL fact[N], infact[N];

void init() {
	fact[0] = infact[0] = 1; // long long
	for (int i = 1; i < N; i ++ )
	{
		fact[i] = fact[i - 1] * i % mod;
		infact[i] = infact[i - 1] * quickPow(i, mod - 2, mod) % mod;
	}
}

inline void solve() {
	int n, k;
	cin >> n >> k;
	// cout << fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
	vector<int> a(n + 1);
	unordered_map<int, int> mp;
	rep(i, 1, n) cin >> a[i];
	bool f = false;
	int l = -1, r = -1;
	rep(i, 1, n) if (mp[a[i]]) {
		f = true;
		l = mp[a[i]], r = i;
		break;
	} else mp[a[i]] = i;

	LL rs = fact[n] * infact[n - k] % mod * infact[k] % mod;
	LL rs2 = 0;
	if (f) {
		LL len = 0;
		len += max(0, l - 1);
		len += max(0, n - r);
		if (len >= k - 1) rs2 = fact[len] * infact[len - k + 1] % mod * infact[k - 1] % mod;
	}
	// cout << ((rs - rs2 + mod) % mod - rs3 + mod) % mod << '\n';
	cout << (rs - rs2 + mod) % mod << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	init();
	cin >> T;
	while (T--) solve();
}

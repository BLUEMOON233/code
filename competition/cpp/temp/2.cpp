#include<bits/stdc++.h>
using namespace std;
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

typedef long long ll;
typedef unsigned long long ull;
inline ll quick_multi(ll a, ll n, ll m)
{
	ll ans = 0;
	while (n)
	{
		if (n & 1) ans = (ans + a) % m;
		a = (a << 1) % m;
		n >>= 1;
	}
	return ans;
}

ll quick_pow(ll x, ll y, ll p)			//O(logn)快速幂
{
	ll sum = 1;
	x %= p;
	while (y)
	{
		if (y & 1) sum = quick_multi(sum, x, p);
		x = quick_multi(x, x, p);
		y >>= 1;
	}
	return sum;
}

inline bool mr(ll x, ll p)  // mille rabin判质数
{
	if (quick_pow(x, p - 1, p) != 1) return 0;  //费马小定理，快速幂
	ll y = p - 1, z;
	while (!(y & 1))    //二次探测
	{
		y >>= 1;
		z = quick_pow(x, y, p);
		if (z != 1 && z != p - 1) return 0;
		if (z == p - 1) return 1;
	}
	return 1;
}

inline bool mrprime(ll x)
{
	if (x < 2) return 0;  // mille rabin判质数
	if (x == 2 || x == 3 || x == 5 || x == 7 || x == 43) return 1;
	return mr(2, x) && mr(3, x) && mr(5, x) && mr(7, x) && mr(43, x);
}

int n, m = 10000;
int prime[10007], np[10007], cnt = 0;

inline void solve() {
	for (int i = 2; i <= m; i++) {
		if (!np[i]) prime[++cnt] = i;
		for (int j = 1; i * prime[j] <= m; j++) {
			np[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		ll cur, c = 0;
		cin >> cur;
		if (cur % 2 == 0) c = 1;
		rep(j, 1, cnt) {
			while (cur % prime[j] == 0) cur /= prime[j], c++;
		}
		if (cur != 1) {
			c++;
			if (!mrprime(cur)) c++;
		}
		sum ^= c;
	}
	if (sum) cout << "Xiaodu";
	else cout << "Duduxiong";
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

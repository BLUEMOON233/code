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
	LL n, q, k;
	cin >> n >> q >> k;
	k--;
	vector<LL> a(n + 1);
	vector<LL> h(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> h[i];
	int lst = -1, len = 0;
	bool flag = false;
	vector<bool> st(n + 1, false);
	rep(i, 1, n) {
		if (h[i] == lst) {
			len++;
			if (len <= k) st[i] = true;
		} else {
			len = 1, lst = h[i];
			st[i] = true;
		}
	}
	rep(i, 1, n) cout << st[i] << ' ';
	cout << endl;
	std::vector<LL> pre(n + 1, 0);
	rep(i, 1, n) {
		if (st[i]) pre[i] = pre[i - 1] + a[i];
		else if (st[i - 1]) pre[i] = pre[i - 1] - pre[i - k - 1] + a[i];
		else pre[i] = pre[i - 1] + a[i] - a[i - k - 1];
	}
	debug1(pre, n);
	while (q--) {
		int x;
		cin >> x;
		cout << pre[x] << '\n';
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

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
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1), b(n + 1);
	rep(i, 1, n) cin >> a[i];
	b[1] = 1;
	rep(i, 2, n) {
		if (a[i] > a[i - 1]) b[i] = b[i - 1] + 1;
		else if (a[i] <= a[i - 1] && a[i - 1] > a[i - 2]) b[i] = b[i - 1] + 1;
		else b[i] = b[i - 1];
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == 1) {
			cout << b[r] << "\n";
			continue;
		}
		if (l == r) {
			cout << "1\n";
			continue;
		}
		int rs = b[r] - b[l - 1];
		if (a[l - 2] >= a[l - 1] && a[l - 1] >= a[l] && a[l] >= a[l + 1]) rs += 2;
		else if (a[l - 2] >= a[l - 1] && a[l - 1] >= a[l]) rs++;
		else if (a[l - 1] >= a[l] && a[l] >= a[l + 1]) rs++;
		cout << rs << "\n";
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

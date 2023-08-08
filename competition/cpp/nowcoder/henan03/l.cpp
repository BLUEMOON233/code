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
	int n, h;
	cin >> n >> h;
	vector<PII> a(n + 1);
	rep(i, 1, n) cin >> a[i].first >> a[i].second;
	sort(a.begin() + 1, a.end(), [](PII & x, PII & y) {
		return x.second > y.second;
	});
	LL max_a = 0, pos = 0;
	rep(i, 1, n) if (max_a < a[i].first) {
		max_a = a[i].first;
		pos = i;
	}
	LL rs = 0;
	rep(i, 1, n) {
		if (a[i].second < max_a) break;
		h -= a[i].second;
		rs++;
		if (h <= 0) {
			cout << rs << '\n';
			return;
		}
	}
	cout << rs + (h - 1) / max_a + 1 << '\n';
	// sort(a.begin() + 1, a.end());
	// sort(b.begin() + 1, b.end());
	// cout << 1 + ((h - b[n] - 1) / a[n] + 1) << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

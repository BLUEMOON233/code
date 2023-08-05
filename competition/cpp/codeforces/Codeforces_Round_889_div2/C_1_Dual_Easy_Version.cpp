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
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	rep(i, 1, n) cin >> a[i];
	int cnt0 = 0, cnt1 = 0;
	rep(i, 1, n) if (a[i] > 0) cnt0++;
	else if (a[i] < 0) cnt1++;
	int max_num = -1, f = 1, pos = 0;
	rep(i, 1, n) if (abs(a[i]) > max_num) {
		max_num = abs(a[i]);
		if (a[i] > 0) f = 1;
		else f = -1;
		pos = i;
	}
	if ((f == 1 && cnt1 <= 12) || (f == -1 && cnt0 <= 12)) {
		vector<PII> rs;
		if (f == 1) {
			rep(i, 1, n) if (a[i] < 0) {
				rs.emplace_back(i, pos);
			}
			rep(i, 2, n) {
				rs.emplace_back(i, i - 1);
			}
			cout << rs.size() << '\n';
			for (auto [x, y] : rs) cout << x << ' ' << y << '\n';
		} else {
			rep(i, 1, n) if (a[i] > 0) {
				rs.emplace_back(i, pos);
			}
			per(i, n - 1, 1) {
				rs.emplace_back(i, i + 1);
			}
			cout << rs.size() << '\n';
			for (auto [x, y] : rs) cout << x << ' ' << y << '\n';
		}
	} else {
		vector<PII> rs;
		if (cnt0 > cnt1) {
			max_num = 0, pos = 0;
			rep(i, 1, n) if (max_num < a[i]) {
				max_num = a[i];
				pos = i;
			}
			rep(i, 1, 5) rs.emplace_back(pos, pos);
			rep(i, 1, n) if (a[i] < 0) rs.emplace_back(i, pos);
			rep(i, 2, n) {
				rs.emplace_back(i, i - 1);
			}
			cout << rs.size() << '\n';
			for (auto [x, y] : rs) cout << x << ' ' << y << '\n';
		} else {
			max_num = 0, pos = 0;
			rep(i, 1, n) if (max_num > a[i]) {
				max_num = a[i];
				pos = i;
			}
			rep(i, 1, 5) rs.emplace_back(pos, pos);
			rep(i, 1, n) if (a[i] > 0) rs.emplace_back(i, pos);
			per(i, n - 1, 1) {
				rs.emplace_back(i, i + 1);
			}
			cout << rs.size() << '\n';
			for (auto [x, y] : rs) cout << x << ' ' << y << '\n';
		}
	}

}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

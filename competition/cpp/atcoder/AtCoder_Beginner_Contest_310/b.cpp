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

struct Node {
	int price;
	int cnt;
	bitset<107> fuc;
};

inline void solve() {
	int n, m;
	cin >> n >> m;
	vector<Node> a(n + 1);
	rep(i, 1, n) {
		int now;
		cin >> a[i].price >> a[i].cnt;
		rep(j, 1, a[i].cnt) {
			cin >> now;
			a[i].fuc[now] = 1;
		}
	}
	sort(a.begin() + 1, a.end(), [](Node & u, Node & v) {
		if (u.price != v.price) return u.price < v.price;
		else return u.cnt > v.cnt;
	});
	// cout << a[1].price	<< '\n';
	// rep(i, 1, n) {
	// 	cout << a[i].price << ' ';
	// 	rep(j, 1, m) if (a[i].fuc[j]) cout << j << ' ';
	// 	cout << endl;
	// }
	rep(i, 1, n) rep(j, i + 1, n) if ((a[j].fuc & a[i].fuc).count() == a[j].fuc.count()) {
		if ((a[i].price == a[j].price) && a[i].cnt > a[j].cnt)  {
			// cout << 1;
			Yes;
			return;
		} else if ((a[i].price < a[j].price) && a[i].cnt >= a[j].cnt) {
			// cout << a[i].cnt << ' ' << a[j].cnt << '\n';
			// cout << 2;
			Yes;
			return;
		}
	}
	No;
}



int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

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

const int N = 1e6 + 7;

struct DSU {
	vector<int> p, Size;
	DSU(int n) : p(n + 1), Size(n + 1, 1) { iota(p.begin(), p.end(), 0);}
	int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
	bool same(int x, int y) {return find(x) == find(y);}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		Size[x] += Size[y], p[y] = x;
		return true;
	}
	int size(int x) {return Size[find(x)];}
};

struct Node {
	double x, y;
	double v;
};

struct action {
	int i, j;
	double t;
} act[N];

inline void solve() {
	int n;
	cin >> n;
	vector<Node> a(n + 1);
	rep(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].v;
	int cnt = 0;
	rep(i, 1, n) rep(j, i + 1, n) {
		double dis = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
		act[++cnt].t = sqrt(dis) / (a[i].v + a[j].v);
		act[cnt].i = i, act[cnt].j = j;
	}
	sort(act + 1, act + 1 + cnt, [](action & x, action & y) {
		return x.t < y.t;
	});
	vector<int> rs(1001);
	int idx = 0;
	DSU dsu(n);
	rep(i, 0, 1000) {
		double now = i;
		while (idx + 1 <= cnt && act[idx + 1].t <= now) {
			idx++;
			dsu.merge(act[idx].i, act[idx].j);
		}
		LL num = 0;
		rep(i, 1, n) if (dsu.find(i) == i) num++;
		rs[i] = num;
	}
	int q;
	cin >> q;
	while (q--) {
		int ask;
		cin >> ask;
		cout << rs[ask] << '\n';
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

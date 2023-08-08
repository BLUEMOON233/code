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

const int N = 1e3 + 7;

struct op {
	int l;
	int r;
	int w;
};

struct itv {
	int l;
	int r;
	int max_pos;
	int min_pos;
	int val;
};

inline void solve() {
	int n, m;
	cin >> n >> m;
	vector<op> opt(m + 1);
	vector<int> rs(n + 1);
	vector<itv> lr;
	rep(i, 1, n) lr.push_back({i, i, i, i, 0});
	rep(i, 1, n) rs[i] = i;
	rep(i, 1, m) {
		int l, r, w;
		cin >> l >> r >> w;
		opt[i] = {l, r, w};
	}
	sort(opt.begin() + 1, opt.end(), [](op & x, op & y) {
		if (x.r - x.l + 1 == y.r - y.l + 1) return x.l < y.l;
		else return x.r - x.l + 1 < y.r - y.l + 1;
	});

	rep(i, 1, m) {
		int l = opt[i].l, r = opt[i].r, w = opt[i].w;
		// cout << l << ' ' << r << ' ' << w << '\n';
		int lp = 0, rp = lr.size() - 1;
		while (lr[lp].l != l) lp++;
		while (lr[rp].r != r) rp--;
		// cout << lr[lp].l << ' ' << lr[rp].r << '\n';
		int tw = 0, tmax = 0, tmin = 0, max_num = -1, min_num = 0x3f3f3f3f;
		rep(j, lp, rp) {
			tw += lr[j].val;
		}
		if (tw % 2 == w % 2) {
			rep(j, lp, rp) {
				if (rs[lr[j].max_pos] > max_num) max_num = rs[lr[j].max_pos], tmax = lr[j].max_pos;
				if (rs[lr[j].min_pos] < min_num) min_num = rs[lr[j].min_pos], tmin = lr[j].min_pos;
			}
			lr.erase(lr.begin() + lp, lr.begin() + rp + 1);
			itv now = {l, r, tmax, tmin, tw % 2};
			lr.insert(lr.begin() + lp, now);
		} else {
			if (lp == rp) {
				cout << "-1\n";
				return;
			} else {
				swap(rs[lr[lp].max_pos], rs[lr[lp + 1].min_pos]);
				// swap(lr[lp].max_pos, lr[lp + 1].min_pos);
				rep(j, lp, rp) {
					if (rs[lr[j].max_pos] > max_num) max_num = rs[lr[j].max_pos], tmax = lr[j].max_pos;
					if (rs[lr[j].min_pos] < min_num) min_num = rs[lr[j].min_pos], tmin = lr[j].min_pos;
				}
				lr.erase(lr.begin() + lp, lr.begin() + rp + 1);
				itv now = {l, r, tmax, tmin, (tw + 1) % 2 };
				lr.insert(lr.begin() + lp, now);
			}
		}
	}
	debug1(rs, n);
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

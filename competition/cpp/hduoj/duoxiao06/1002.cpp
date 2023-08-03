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

const int N = 1e5 + 7, mod = 998244353;
vector<int> num;

void init() {
	rep(i, 1, sqrt(2e5)) {
		num.push_back(i * i);
	}
}


inline void solve() {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	vector<int> prel(n + 2), prer(n + 2);
	unordered_map<int, int> mp;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) mp[p[i]] = i;

	vector<PII> bug;
	rep(i, 1, n) for (auto x : num) {
		int l = i, r = mp[x - p[i]];
		if (mp[x - p[i]] == 0) continue;
		if (l >= r) continue;
		// cout << l << ' ' << r << '\n';
		bug.emplace_back(l, r);
	}
	cout << bug.size() << '\n';
	sort(bug.begin(), bug.end(), [](PII & a, PII & b) {
		if (a.second - a.first == b.second - b.first) return a.first < b.first;
		return a.second - a.first < b.second - b.first;
	});
	for (auto [x, y] : bug) cout << x << ' ' << y << '\n';
	// YES;
	// debug1(prel, n);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		// cout << query(1, l, r) << '\n';
		// cout << min(prel[l], prer[r]) << '\n';
	}
}

int main() {
	// fast();
	int T = 1;
	//	T = read();
	init();
	cin >> T;
	while (T--) solve();
}

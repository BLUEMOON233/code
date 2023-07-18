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

const int N = 11;
LL rs = 0;
vector<int> mp[N];
int n, t, m;
void dfs(int x, vector<string> &now, int sz) {
	// rep(i, 1, t) cout << now[i] << '\n';
	// cout << endl;
	if (x == n + 1) {
		string zero = "";
		rep(i, 1, n) zero += '0';
		rep(i, 1, t) if (now[i] == zero) return;
		rs ++ ;
		return;
	}
	rep(i, 1, min(sz + 1, t)) {
		bool f = false;
		for (auto u : mp[x]) if (now[i][u - 1] == '1') {
				f = true;
				break;
			}
		if (f) continue;
		now[i][x - 1] = '1';
		if (i != sz + 1) dfs(x + 1, now, sz);
		else dfs(x + 1, now, sz + 1);
		now[i][x - 1] = '0';
	}

}

inline void solve() {
	cin >> n >> t >> m;
	// vector<vector<int>> mp(n + 1);
	// rep(i, 1, m) cin >> ucp[i].first >> ucp[i].second;
	rep(i, 1, m) {
		int x, y;
		cin >> x >> y;
		mp[x].emplace_back(y);
		mp[y].emplace_back(x);
	}
	if (t == 1) {
		if (m) cout << 0 << '\n';
		else cout << 1 << '\n';
		return;
	}
	vector<string> now(t + 1, "");
	rep(i, 1, t) rep(j, 1, n) now[i] += '0';
	dfs(1, now, 1);
	cout << rs / t << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

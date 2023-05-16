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
	int h, w, t;
	cin >> h >> w >> t;
	pair<int, int> goal, start;
	vector<vector<char> > a(h + 2, vector<char>(w + 2, '#'));
	vector<vector<bool> > st(h + 2, vector<bool>(w + 2, '#'));
	vector<vector<PII> > fa(h + 1, vector<PII>(w + 1));
	vector<PII> paths;
	rep(i, 1, h) rep(j, 1, w) cin >> a[i][j];
	rep(i, 1, h) rep(j, 1, w) if (a[i][j] == 'G') {goal = {i, j}; break;}
	queue<tuple<int, int, int>> q;
	rep(i, 1, h) rep(j, 1, w) if (a[i][j] == 'S') {q.push({i, j, 0}); start = {i, j}; break;}
	while (!q.empty()) {
		int x = get<0>(q.front()), y = get<1>(q.front()), path = get<2>(q.front());
		q.pop();
		if (x == goal.first && y == goal.second) {
			while (x != start.first && y != start.second) {
				paths.push_back({x, y});
				PII tmp = fa[x][y];
				x = tmp.first, y = tmp.second;
			}
			paths.push_back(start);
			reverse(paths.begin(), paths.end());
			return;
		}
		if (path == t) continue;
		if (a[x + 1][y] != '#' && !st[x + 1][y]) q.push({x + 1, y, path + 1}), fa[x + 1][y] = {x, y};
		if (a[x][y + 1] != '#' && !st[x][y + 1]) q.push({x, y + 1, path + 1}), fa[x][y + 1] = {x, y};
		if (a[x - 1][y] != '#' && !st[x - 1][y]) q.push({x - 1, y, path + 1}), fa[x - 1][y] = {x, y};
		if (a[x][y - 1] != '#' && !st[x][y - 1]) q.push({x, y - 1, path + 1}), fa[x][y + 1] = {x, y};
	}
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

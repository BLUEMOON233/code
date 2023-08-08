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

const int N = 3e3 + 7;
int n;
int g[N][2];
LL dp[N][2];
int h[N], e[N << 1], ne[N << 1], w[N], idx = 0;
inline void add(int a, int b, int c) {
	e[++idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx;
}
int st[N];
LL now01 = 0;

void dfs(int now, int fa, LL &rew, int ew) {
	if (st[now] == 3) {
		dp[now][0] = g[now][0] + ew;
		dp[now][1] = g[now][1] + ew;

	} else if (st[now] == 0) {
		dp[now][1] = g[now][1] + ew;

	} else {
		dp[now][0] = g[now][0] + ew;

	}
	rew += dp[now][1 - now01];
	for (int i = h[now]; i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		dfs(j, now, rew, ew + w[i]);
	}
}

LL rs_dfs(int now, int fa) {
	for (int i = h[now]; i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		rs_dfs(j, now);
	}
}

inline void solve() {
	cin >> n;
	vector<int> bw(n + 1), cost(n + 1);
	rep(i, 1, n) cin >> bw[i];
	rep(i, 1, n) cin >> cost[i];
	rep(i, 1, n) g[i][bw[i]] = 0, g[i][1 - bw[i]] = -cost[i];
	rep(i, 1, n) st[i] = 3;
	rep(i, 1, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
	}
	rep(i, 1, n) {
		LL rs0 = g[i][0], rs1 = g[i][1];
		now01 = 0;
		dfs(i, 0, rs0, 0);
		now01 = 1;
		dfs(i, 0, rs1, 0);
		cout << rs0 << ' ' << rs1 << '\n';
		st[i] = (rs0 > rs1) ? 0 : 1;
	}
	debug1(st, n);
	LL rs = 0;
}

int main() {
	// fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}


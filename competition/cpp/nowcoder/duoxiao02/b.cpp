#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i,j,k) for(int i = int(j);i<=int(k);i++)
#define per(i,j,k) for(int i = int(j);i>=int(k);i--)
#define llrep(i,j,k) for(LL i = LL(j);i<=LL(k);i++)
#define llper(i,j,k) for(LL i = LL(j);i>=LL(k);i--)

const int N = 1e4 + 7, INF = 0x3f3f3f3f;

int n, m;
int fa[N];
int f[N][20], d[N];
long long dis[N];
int ver[2 * N], nxt[2 * N], head[N], ed[N];
queue<int> q;
int tot = 0, t;

void add(int x, int y, int z) {
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	ed[tot] = z;
}

void bfs() {
	q.push(1);
	d[1] = 1;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i], z = ed[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			dis[y] = dis[x] + z;
			f[y][0] = x;
			for (int j = 1; j <= t; j++) {
				f[y][j] = f[f[y][j - 1]][j - 1];
			}
			q.push(y);
		}
	}
}

int lca(int x, int y) {
	if (d[x] > d[y]) swap(x, y);
	for (int i = t; i >= 0; i--) {
		if (d[f[y][i]] >= d[x]) y = f[y][i];
	}
	if (x == y) return x;
	for (int i = t; i >= 0; i--) {
		if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	}
	return f[x][0];
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	t = (int)(log(n) / log(2)) + 1;
	for (int i = 1; i < n; i++) {
		LL u, v, z;
		cin >> u >> v >> z;
		add(u, v, z);
		add(v, u, z);
	}
	bfs();
	//dis[1]=1;
	LL ans = 0;
	for (int i = 1; i <= m; i++) {
		long long a, b, x, y;
		cin >> a >> b >> x >> y;
		ans += max((LL)0, x - dis[a] - dis[b] + 2LL * (long long)dis[lca(a, b)] - y);
	}
	cout << ans << '\n';
	return 0;
}
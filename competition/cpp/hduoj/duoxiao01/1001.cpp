#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<LL, LL> PII;
#define endl '\n'
#define rep(i,j,k) for(LL i=LL(j);i<=LL(k);i++)
#define per(i,j,k) for(LL i=LL(j);i>=LL(k);i--)
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
int e[N << 1], ne[N << 1], h[N], idx = 0;

inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

int sa, ta, sb, tb;
LL k1, k2;
int n, m;

PII C1[N], C2[N];

bool A_dfs(int now, int fa, vector<bool> &st) {
	if (st[ta]) return false;
	if (now == ta) {
		st[now] = true;
		k1++;
		C1[now].second = k1;
		return true;
	}
	for (int i = h[now]; i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		if (A_dfs(j, now, st)) {
			k1++;
			C1[now].second = k1;
			st[now] = true;
			return true;
		}
	}
	return false;
}

bool bf = false;
bool B_dfs(int now, int fa, vector<bool> &st, vector<bool> &re) {
	if (bf) return false;
	if (now == tb) {
		bf = true;
		k2++;
		C2[now].second = k2;
		if (st[tb]) re[now] = true;
		return true;
	}
	for (int i = h[now]; i; i = ne[i]) {
		int j = e[i];
		if (j == fa) continue;
		if (B_dfs(j, now, st, re)) {
			k2++;
			C2[now].second = k2;
			if (st[now]) re[now] = true;
			return true;
		}
	}
	return false;
}

struct Node {
	int now;
	int path;
};

void A_bfs(vector<bool> &st) {
	queue<Node> q;
	vector<int> fa(n + 1, 0);
	q.push({sa, 1});
	while (!q.empty()) {
		auto [now, path] = q.front();
		if (now == ta) {
			int idx = ta;
			while (idx != sa) {
				k1++;
				C1[idx].second = k1;
				st[idx] = true;
				idx = fa[idx];
			}
			k1++;
			C1[idx].second = k1;
			st[idx] = true;
			break;
		}
		q.pop();
		for (int i = h[now]; i; i = ne[i]) {
			int j = e[i];
			if (j == fa[now]) continue;
			q.push({j, path + 1});
			fa[j] = now;
		}
	}
}


void B_bfs(vector<bool> &st, vector<bool> &re) {
	queue<Node> q;
	vector<int> fa(n + 1, 0);
	q.push({sb, 1});
	while (!q.empty()) {
		auto [now, path] = q.front();
		if (now == tb) {
			int idx = tb;
			while (idx != sb) {
				k2++;
				C2[idx].second = k2;
				if (st[idx]) re[idx] = true;
				idx = fa[idx];
			}
			k2++;
			C2[idx].second = k2;
			if (st[idx]) re[idx] = true;
			break;
		}
		q.pop();
		for (int i = h[now]; i; i = ne[i]) {
			int j = e[i];
			if (j == fa[now]) continue;
			q.push({j, path + 1});
			fa[j] = now;
		}
	}
}

void extend_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
	if (!b) { d = a; x = 1; y = 0; }
	else { extend_gcd(b, a % b, d, y, x); y -= x * (a / b);}
}

inline void solve() {
	// cin >> n >> m;
	scanf(" %d%d", &n, &m);
	rep(i, 1, n - 1) {
		int x, y;
		// cin >> x >> y;
		scanf(" %d%d", &x, &y);
		add(x, y), add(y, x);
	}
	while (m--) {
		// cout << m << ": \n";
		bf = false;
		k1 = k2 = 0;
		vector<bool> st(n + 1, false);
		// cin >> sa >> ta >> sb >> tb;
		scanf(" %d%d%d%d", &sa, &ta, &sb, &tb);
		// A_dfs(sa, 0, st);
		A_bfs(st);
		// debug1(st, n);
		vector<bool> re(n + 1, false);
		// B_dfs(sb, 0, st, re);
		B_bfs(st, re);
		// debug1(re, n);
		// cout << k1 << ' ' << k2 << '\n';
		// if ((__gcd(k1, k2) == k1 || __gcd(k1, k2) == k2) && sa != sb) {
		// 	cout << -1 << '\n';
		// 	continue;
		// }
		// if ((gcd(k1, k2) == k1 || gcd(k1, k2) == k2) && sa != sb) {
		// 	cout << -1 << '\n';
		// 	continue;
		// }
		// if (k1 == k2 && sa != sb) {
		// 	cout << -1 << '\n';
		// 	continue;
		// }

		rep(i, 1, n) if (st[i]) {
			C1[i].first = k1 - C1[i].second + 1;
			C1[i].second += k1 - 1;
		}
		C1[sa].second = C1[ta].first = -1;

		rep(i, 1, n) if (re[i]) {
			C2[i].first = k2 - C2[i].second + 1;
			C2[i].second += k2 - 1;
		}
		C2[sb].second = C2[tb].first = -1;
		// rep(i, 1, n) cout << i << ": " << C1[i].first << ' ' << C1[i].second << '\n';
		// rep(i, 1, n) cout << i << ": " << C2[i].first << ' ' << C2[i].second << '\n';

		LL minTime = 1e18 + 7;
		LL rsPoint = -1;
		rep(i, 1, n) if (re[i]) {
			LL x, y, x1, y1, C, d;
			if (C1[i].first != -1 && C2[i].first != -1) {
				C = C2[i].first - C1[i].first;
				extend_gcd(k1, -k2, d, x, y);
				// cout << k1 << ' ' << -k2 << ' ' << C << ' ' << d << '\n';
				if (C % d == 0) {
					LL b1 = k2 / d;
					x1 = (x + b1) * (C / d);
					x1 = (x1 % b1 + b1) % b1;
					y1 = (C - k1 * x1) / k2;
					if (x1 >= 0 && y1 >= 0 && k1 * x + C1[i].first < minTime) {
						// cout << x1 << ' ' << y1 << ' ' << "cost: ";
						// cout << k1 * x + C1[i].first << '\n';
						minTime = k1 * x + C1[i].first;
						rsPoint = i;
					}
				}
			}
			if (C1[i].first != -1 && C2[i].second != -1) {
				C = C2[i].second - C1[i].first;
				extend_gcd(k1, -k2, d, x, y);
				// cout << k1 << ' ' << -k2 << ' ' << C << ' ' << d << '\n';
				if (C % d == 0) {
					LL b1 = k2 / d;
					x1 = (x + b1) * (C / d);
					x1 = (x1 % b1 + b1) % b1;
					y1 = (C - k1 * x1) / k2;
					if (x1 >= 0 && y1 >= 0 && k1 * x + C1[i].first < minTime) {
						// cout << k1 * x + C1[i].first << '\n';
						minTime = k1 * x + C1[i].first;
						rsPoint = i;
					}
				}
			}
			if (C1[i].second != -1 && C2[i].first != -1) {
				C = C2[i].first - C1[i].second;
				extend_gcd(k1, -k2, d, x, y);
				// cout << k1 << ' ' << -k2 << ' ' << C << ' ' << d << '\n';
				if (C % d == 0) {
					LL b1 = k2 / d;
					x1 = (x + b1) * (C / d);
					x1 = (x1 % b1 + b1) % b1;
					y1 = (C - k1 * x1) / k2;
					if (x1 >= 0 && y1 >= 0 && k1 * x + C1[i].second < minTime) {
						// cout << x1 << ' ' << y1 << ' ' << "cost: ";
						// cout << k1 * x + C1[i].second << '\n';
						minTime = k1 * x + C1[i].second;
						rsPoint = i;
					}
				}

			}
			if (C1[i].second != -1 && C2[i].second != -1) {
				C = C2[i].second - C1[i].second;
				extend_gcd(k1, -k2, d, x, y);
				// cout << k1 << ' ' << -k2 << ' ' << C << ' ' << d << '\n';
				if (C % d == 0) {
					LL b1 = k2 / d;
					x1 = (x + b1) * (C / d);
					x1 = (x1 % b1 + b1) % b1;
					y1 = (C - k1 * x1) / k2;
					if (x1 >= 0 && y1 >= 0 && k1 * x + C1[i].second < minTime) {
						// cout << x1 << ' ' << y1 << ' ' << "cost: ";
						// cout << k1 * x + C1[i].second << '\n';
						minTime = k1 * x + C1[i].second;
						rsPoint = i;
					}
				}

			}
		}
		// cout << rsPoint << '\n';
		printf("%lld\n", rsPoint);
		// cout << endl;
	}
}

int main() {
	// fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	scanf("%d", &T);
	while (T--) solve();
}

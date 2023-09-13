#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

struct Node {
	LL x, y;
};

inline void solve() {
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<Node> c(n + 1);
	rep(i, 1, n) cin >> c[i].x >> c[i].y;
	LL rs1 = abs(c[a].x - c[b].x) + abs(c[a].y - c[b].y);
	LL rs2 = 1e18 + 7, rs3 = 1e18 + 7;
	rep(i, 1, k) rs2 = min(rs2, abs(c[a].x - c[i].x) + abs(c[a].y - c[i].y));
	rep(i, 1, k) rs3 = min(rs3, abs(c[b].x - c[i].x) + abs(c[b].y - c[i].y));
	cout << min(rs1, rs2 + rs3) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 107;
int d[N][N], ori[N][N];
inline void add(int x1, int y1, int x2, int y2, int val) {
	d[x1][y1] += val, d[x2 + 1][y2 + 1] += val, d[x2 + 1][y1] -= val, d[x1][y2 + 1] -= val;
} //在{[x1, y1], [x2, y2]}区间内+=val

void solve() {
	int n;
	cin >> n;
	rep(i, 1, n) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		add(a + 1, c + 1, b, d, 1);
	}
	rep(i, 1, 101) rep(j, 1, 101) ori[i][j] = d[i][j] + ori[i - 1][j] + ori[i][j - 1] - ori[i - 1][j - 1];
	LL rs = 0;
	// rep(i, 1, 10) rep(j, 1, 10) cout << ori[i][j] << " \n"[j == 10];
	rep(i, 1, 101) rep(j, 1, 101) if (ori[i][j]) rs++;
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
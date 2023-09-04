#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 107;

void solve() {
	int n, d, p;
	cin >> n >> d >> p;
	vector<LL> f(n + 1), pre(n + 1);
	rep(i, 1, n) cin >> f[i];
	sort(f.begin() + 1, f.end());
	rep(i, 1, n) pre[i] = f[i] + pre[i - 1];
	LL rs = pre[n] - pre[0];
	for (int i = n; i > 0; i -= d) {
		LL t = pre[i] - pre[max(i - d, 0)];
		if (t > p) rs += p - t;
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
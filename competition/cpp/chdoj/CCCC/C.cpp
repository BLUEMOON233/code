#include<bits/stdc++.h>
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
using namespace std;

void solve() {
	int l, m;
	cin >> l >> m;
	vector<bool> tr(l + 1, true);
	while (m--) {
		int x, y;
		cin >> x >> y;
		rep(i, x, y) tr[i] = false;
	}
	int rs = 0;
	rep(i, 0, l) rs += tr[i];
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
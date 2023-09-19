#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	if (k - 1 > x || n < k) {
		cout << -1 << '\n';
		return;
	}
	if (x == k) x--;
	LL rs = 0;
	rep(i, 0, k - 1) rs += i;
	rep(i, 1, n - k) rs += x;
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	rep(i, 1, l - 1) cout << i << ' ';
	per(i, r, l) cout << i << ' ';
	rep(i, r + 1, n) cout << i << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while(_--) solve();
	return 0;
}
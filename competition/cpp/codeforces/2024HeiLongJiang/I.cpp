#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int x;
	cin >> x;
	int rs = 0;
	rep(i, 0, 31) if ((x >> i) & 1) rs++;
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
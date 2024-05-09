#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	if (x > y) swap(x, y);
	cout << (x <= z && z <= y) ? "YES\n" : "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}
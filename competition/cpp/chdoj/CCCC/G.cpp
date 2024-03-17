#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	rep(i, 1, n) cin >> a[i];
	LL rs = 0;
	rep(i, 1, n) {
		if (a[i] > a[i - 1]) rs += a[i] - a[i - 1];
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
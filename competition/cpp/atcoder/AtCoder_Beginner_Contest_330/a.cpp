#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, l;
	cin >> n >> l;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	int rs = 0;
	rep(i, 1, n) if (a[i] >= l) rs++;
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

inline void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	if (n & 1) {
		cout << 4 << '\n';
		cout << 1 << ' ' << n - 1 << '\n';
		cout << 1 << ' ' << n - 1 << '\n';
		cout << 2 << ' ' << n << '\n';
		cout << 2 << ' ' << n << '\n';
	} else {
		cout << 2 << '\n';
		cout << 1 << ' ' << n << '\n';
		cout << 1 << ' ' << n << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
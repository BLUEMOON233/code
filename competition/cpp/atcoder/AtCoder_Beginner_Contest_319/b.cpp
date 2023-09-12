#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	rep(i, 0, n) {
		bool f = true;
		rep(j, 1, 9) if (n % j == 0 && i % (n / j) == 0) {
			cout << j;
			f = false;
			break;
		}
		if (f) cout << '-';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
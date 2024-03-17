#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)
using namespace std;
/*很讨厌某些没有品味的模拟题*/

void solve() {
	int n;
	cin >> n;
	per(i, n, 0) {
		int now;
		cin >> now;
		if (now == 0) continue;
		if (now > 0 && i != n) cout << '+';
		if (now < 0) cout << '-';
		now = abs(now);
		if (i != 0 && now != 1) cout << now;
		if (i != 0 && i != 1) cout << "x^" << i;
		else if (i == 1) cout << 'x';
		else if (i == 0) cout << now;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
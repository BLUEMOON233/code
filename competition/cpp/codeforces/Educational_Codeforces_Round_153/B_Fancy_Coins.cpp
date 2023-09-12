#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int m, k, a, b, t;
	cin >> m >> k >> a >> b;
	int B = m / k, A = m % k;
	// cout << A << ' ' << B << '\n';
	t = max(a - A, 0);
	A = max(A - a, 0);
	a = t;
	b += a / k;
	a %= k;
	// cout << A << ' ' << B << ' ' << a << ' ' << b << '\n';
	B = max(B - b, 0);
	if (A) {
		cout << A + B << '\n';
		return;
	}
	cout << min(B, B - 1 + k - a) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

const int mod = 998244353;

LL quickPow(LL a, LL b, LL p = mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % p;
		b >>= 1, a = a * a % p;
	}
	return rs % p;
}

void solve() {
	LL n;
	cin >> n;
	LL x = (quickPow(2, n - 1, mod - 1) - n + mod - 1) % (mod - 1);
	cout << quickPow(2, x) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
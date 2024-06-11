#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const LL mod = 1e9 + 7;

LL quickPow(LL a, LL b, LL mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}

void solve() {
	LL l, r, k;
	cin >> l >> r >> k;
	if (k > 10) {
		cout << 0 << '\n';
		return;
	}
	LL x = 9 / k + 1;
	cout << (quickPow(x, r, mod) - quickPow(x, l, mod) + mod ) % mod<< '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
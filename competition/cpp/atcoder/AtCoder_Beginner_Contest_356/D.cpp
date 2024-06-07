#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const LL mod = 998244353;

void solve() {
	LL n, m;
	cin >> n >> m;
	LL rs = 0;
	rep(bit, 0, 59) if (((m >> bit) & 1)) {
		LL cnt = n / (1LL << (bit + 1));
		rs = (rs + cnt * (1LL << bit)) % mod;
		rs = (rs + max(n % (1LL << (bit + 1)) + 1LL - (1LL << bit), 0LL)) % mod;
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
	return 0;
}
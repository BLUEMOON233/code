#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	LL x, y, z, mul;
	cin >> x >> y >> z >> mul;
	if (y > z) swap(y, z);
	if (x > y) swap(x, y);
	if (y > z) swap(y, z);
	LL rs = 0;
	for (LL i = 1; i <= x; i++) {
		for (LL j = 1; j <= y; j++) {
			if (mul % (i * j) != 0) continue;
			LL k = mul / (i * j);
			rs = max(rs, (x - i + 1) * (y - j + 1) * (z - k + 1));
		}
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
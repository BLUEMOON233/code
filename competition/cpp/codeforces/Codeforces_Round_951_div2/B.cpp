#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	LL x, y;
	cin >> x >> y;
	int cnt = 0;
	rep(i, 0, 32) {
		if (((x >> i) & 1) == ((y >> i) & 1)) {
			cnt++;
			continue;
		}
		break;
	}
	LL rs = 1;
	rep(i, 1, cnt) rs *= 2LL;
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	LL maxVal = -1;
	int rs = 2;
	rep(i, 2, n) {
		LL x = i;
		LL now = 0;
		while (x <= n) {
			now += x;
			x += i;
		}
		if(now > maxVal) {
			maxVal = now;
			rs = i;
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
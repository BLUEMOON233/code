#include<bits/stdc++.h>
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)
using namespace std;

void solve() {
	ULL n, k;
	cin >> n >> k;
	vector<int> bit;
	while (k) {
		bit.emplace_back(k & 1);
		k >>= 1;
	}
	rep(i, bit.size() + 1, n) cout << 0;
	ULL lst = 0;
	per(i, bit.size() - 1, 0) {
		LL now = bit[i];
		cout << (now ^ lst);
		lst = now;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
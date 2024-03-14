#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void init() {
}

void solve() {
	int n;
	cin >> n;
	int rs = n;
	map<int, int> mp;
	rep(i, 1, n) {
		int x;
		cin >> x;
		if(mp[int(~(x+2147483648))]) {
			mp[int(~(x+2147483648))]--;
			rs--;
		}else {
			mp[x]++;
		}
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T = 1;
	cin >> T;
	while (T--) solve();
}
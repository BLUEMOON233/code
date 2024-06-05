#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, m;
	cin >> n >> m;
	map<char, int> mp;
	string s;
	cin >> s;
	rep(i, 0, n - 1) {
		mp[s[i]]++;
	}
	LL rs = 0;
	rep(c, 'A', 'G') {
		if(mp[c] < m) rs += m - mp[c];
	}
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
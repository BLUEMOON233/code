#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	unordered_map<char, int> mp;
	for (const auto &c : s) {
		mp[c]++;
	}
	int rs = 0;
	rep(i, 'a', 'z') rs = max(rs, mp[i]);
	if (rs > n / 2) cout << 2 * rs - n << '\n';
	else cout << (n & 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
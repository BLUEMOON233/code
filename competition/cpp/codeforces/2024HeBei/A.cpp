#include<bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	unordered_map<char, int> mp;
	int rs = 0;
	for (char c : s) {
		if (c == 'i') continue;
		if (!mp[c]) {
			mp[c]++;
			rs++;
		}
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
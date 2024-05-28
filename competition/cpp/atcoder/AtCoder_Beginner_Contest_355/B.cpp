#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> c(n + m + 1);
	rep(i, 1, n) cin >> c[i];
	rep(i, n + 1, n + m) cin >> c[i];
	unordered_map<int, char> mp;
	rep(i, 1, n) mp[c[i]] = 'a';
	rep(i, n + 1, n + m) mp[c[i]] = 'b';
	sort(c.begin() + 1, c.end());
	rep(i, 2, n + m) {
		if (mp[c[i - 1]] == mp[c[i]] && mp[c[i]] == 'a') {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
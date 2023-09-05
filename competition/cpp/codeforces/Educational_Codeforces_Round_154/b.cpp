#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.length();
	unordered_map<int, bool> mp;
	rep(i, 0, n - 1) if (s[i] == t[i] && s[i] == '0') mp[i] = true;
	rep(i, 1, n - 1) if (s[i] == t[i] && s[i] == '1' && mp[i - 1]) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
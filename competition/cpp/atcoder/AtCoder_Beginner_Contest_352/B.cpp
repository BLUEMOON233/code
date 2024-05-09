#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.length() - 1, m = t.length() - 1;
	for (int i = 0, j = 0; i <= n && j <= m; j++) {
		if (s[i] == t[j]) {
			cout << j + 1 << ' ';
			i++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}
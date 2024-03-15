#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	string s;
	cin >> s;
	rep(i, 1, 8) if (i != s[1] - '0') cout << s[0] << i << '\n';
	rep(c, 'a', 'h') if (c != s[0]) cout << char(c) << s[1] << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
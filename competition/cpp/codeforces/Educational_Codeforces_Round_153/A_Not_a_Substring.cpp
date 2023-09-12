#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	string s;
	cin >> s;
	if (s == "()") {
		cout << "NO\n";
		return;
	}
	int n = s.length();
	string rs = "";
	rep(i, 1, n) rs += "()";
	bool a = false, b = false;
	rep(i, 0, n - 1) if (s[i] != rs[i]) a = true;
	rep(i, 0, n - 1) if (s[i] != rs[i + 1]) b = true;
	if (a && b) {
		cout << "YES\n";
		cout << rs << '\n';
		return;
	}
	rs = "";
	rep(i, 1, n) rs += '(';
	rep(i, 1, n) rs += ')';
	cout << "YES\n";
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
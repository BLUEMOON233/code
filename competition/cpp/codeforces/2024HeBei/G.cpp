#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int ta, tb, tc;
	cin >> ta >> tb >> tc;
	int a = ta, b = tb, c = tc;
	string s;
	cin >> s;
	int n = s.length();
	if (n == 1) {
		cout << 0 << '\n';
		return;
	}
	if (n == 2) {
		if (s == "00" && a) cout << 2 << '\n';
		else if ((s == "01" || s == "10") && b) cout << 2 << '\n';
		else if (s == "11" && c) cout << 2 << '\n';
		else cout << 0 << '\n';
		return;
	}
	int len = 0;
	int rs = 0;
	for (int i = 0; i <= n - 1; i += 2) {
		// cerr << i << ' ' << len << '\n';
		if (i  && len >= 2) {
			int x = s[i - 2] - '0';
			int y = s[i - 1] - '0';
			if (x && y) c++;
			else if (x || y) b++;
			else a++;
			len -= 2;
		}
		while (true) {
			if (s[(i + len) % n] == '0' && s[(i + len + 1) % n] == '0') {
				if (a) a--;
				else break;
				len += 2;
			} else if (s[(i + len) % n] == '0' && s[(i + len + 1) % n] == '1') {
				if (b) b--;
				else break;
				len += 2;
			} else if (s[(i + len) % n] == '1' && s[(i + len + 1) % n] == '0') {
				if (b) b--;
				else break;
				len += 2;
			} else if (s[(i + len) % n] == '1' && s[(i + len + 1) % n] == '1') {
				if (c) c--;
				else break;
				len += 2;
			}
			// cerr << i << ' ' << len << '\n';
			// cerr << (i + len + 1) % n << ' ' << i << '\n';
			if ((i + len + 1) % n == i || (i + len + 1) % n == (i + 1) % n) break;
		}
		rs = max(rs, len);
	}
	a = ta, b = tb, c = tc;
	len = 0;
	for (int i = 1; i <= n - 1; i += 2) {
		// cerr << i << ' ' << len << '\n';
		if (i != 1 && len >= 2) {
			int x = s[i - 2] - '0';
			int y = s[i - 1] - '0';
			if (x && y) c++;
			else if (x || y) b++;
			else a++;
			len -= 2;
		}
		while (true) {
			if (s[(i + len) % n] == '0' && s[(i + len + 1) % n] == '0') {
				if (a) a--;
				else break;
				len += 2;
			} else if (s[(i + len) % n] == '0' && s[(i + len + 1) % n] == '1') {
				if (b) b--;
				else break;
				len += 2;
			} else if (s[(i + len) % n] == '1' && s[(i + len + 1) % n] == '0') {
				if (b) b--;
				else break;
				len += 2;
			} else if (s[(i + len) % n] == '1' && s[(i + len + 1) % n] == '1') {
				if (c) c--;
				else break;
				len += 2;
			}
			// cerr << i << ' ' << len << '\n';
			// cerr << (i + len + 1) % n << ' ' << i << '\n';
			if ((i + len + 1) % n == i || (i + len + 1) % n == (i + 1) % n) break;
		}
		rs = max(rs, len);
	}
	cout << rs << '\n';
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
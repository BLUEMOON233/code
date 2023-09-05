#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int pos = 0, edge = 0, cnt = 0;
	rep(i, 0, n - 1) {
		if (s[i] == '+') {
			pos++;
			if (cnt) cnt++;
			if (pos == 1) edge = 1, cnt = 0;
		}
		if (s[i] == '-') {
			pos--;
			if (cnt) cnt--;
			if (edge > pos) edge--;
			if (pos == 1) edge = 1, cnt = 0;
			if (pos == 0) edge = 0, cnt = 0;
		}
		if (s[i] == '0') {
			if (pos < 2) {
				cout << "NO\n";
				return;
			}
			if (edge == pos) {
				cout << "NO\n";
				return;
			}
			if (cnt == 0) cnt++;
		}
		if (s[i] == '1') {
			if (cnt) {
				cout << "NO\n";
				return;
			}
			edge = pos;
		}
		// cout << i << ": " << s[i] << ' ' << pos << ' ' << edge << ' ' << cnt << '\n';
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	s = '@' + s + 'A';
	vector<int> pre(n + 3, 0);
	int rs = -1;
	int need = -1;
	per(i, n + 1, 1) {
		pre[i] = pre[i + 1] + (s[i] == 'B');
		if (pre[i] == k) rs = i - 1;
		need = k - pre[i];
	}
	if (rs == 0) {
		cout << 0 << '\n';
		return;
	}
	if (rs == -1) {
		cout << 1 << '\n';
		int p = 1;
		while (p <= n && need) {
			if (s[p] == 'B') { p++; continue;}
			p++; need--;
		}
		cout << p - 1 << ' ' << 'B' << '\n';
		return;
	}
	cout << 1 << '\n';
	cout << rs << ' ' << 'A' << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
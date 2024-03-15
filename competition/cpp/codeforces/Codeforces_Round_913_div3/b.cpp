#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	string s;
	cin >> s;
	vector<pair<char, int>> a, b, rs;
	rep(i, 0, s.length() - 1) {
		char c = s[i];
		if (c == 'b') {
			if (a.size()) a.pop_back();
			continue;
		}
		if (c == 'B') {
			if (b.size()) b.pop_back();
			continue;
		}
		if ('a' <= c && c <= 'z') {
			a.emplace_back(c, i);
		} else {
			b.emplace_back(c, i);
		}
	}
	for (auto x : a) rs.emplace_back(x);
	for (auto x : b) rs.emplace_back(x);
	sort(rs.begin(), rs.end(), [](const pair<char, int> &x, const pair<char, int> &y) {
		return x.second < y.second;
	});
	for (const auto &[x, y] : rs) cout << x;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
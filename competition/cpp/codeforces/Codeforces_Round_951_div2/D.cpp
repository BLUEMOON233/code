#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<PII> pos1, pos0;
	char lst = s[0];
	int now = 0;

	if (s[n - 1] == '1') {
		rep(i, 1, k) s += '0';
	} else {
		rep(i, 1, k) s += '1';
	}

	rep(i, 0, n + k - 1) {
		if (s[i] == lst) {
			now++;
		}
		else {
			if (now != k) {
				if (lst == '1') pos1.emplace_back(now - k, i);
				else pos0.emplace_back(now - k, i);
			}
			now = 1;
			lst = s[i];
			continue;
		}
	}
	// cout << "k: " << k << '\n';
	// cout << "line1:\n";
	// for (auto [x, y] : pos1) {
	// 	cout << "test" << y << ": " << x << '\n';
	// }
	// cout << "line0:\n";
	// for (auto [x, y] : pos0) {
	// 	cout << "test" << y << ": " << x << '\n';
	// }

	if (pos0.size() && pos1.size()) {
		cout << -1 << '\n';
		return;
	}

	if (pos0.size() > 2 || pos1.size() > 2) {
		cout << -1 << '\n';
		return;
	}
	if (pos0.size() == 0 && pos1.size() == 0) {
		cout << n << '\n';
		return;
	}

	if (pos0.size() == 1 && pos0[0].first == k && s[n - 1] == '1') {
		cout << pos0[0].second - k << '\n';
		return;
	}

	if (pos1.size() == 1 && pos1[0].first == k && s[n - 1] == '0') {
		cout << pos1[0].second - k << '\n';
		return;
	}


	if (pos0.size() == 2) {
		if (pos0[1].second != n) {
			cout << -1 << '\n';
			return;
		}
		if (pos0[0].first + pos0[1].first == 0 && s[n - 1] == '0') {
			if (pos0[0].first > 0) {
				cout << pos0[0].second - k << '\n';
				return;
			} else {
				cout << pos0[0].second << '\n';
				return;
			}
		}
		if (pos0[0].first + pos0[1].first == -k && s[n - 1] == '0') {
			cout << pos0[0].second << '\n';
			return;
		}
	}

	if (pos1.size() == 2) {
		if (pos1[1].second != n) {
			cout << -1 << '\n';
			return;
		}
		if (pos1[0].first + pos1[1].first == 0 && s[n - 1] == '1') {
			if (pos1[0].first > 0) {
				cout << pos1[0].second - k << '\n';
				return;
			} else {
				cout << pos1[0].second << '\n';
				return;
			}
		}
		if (pos1[0].first + pos1[1].first == -k && s[n - 1] == '1') {
			cout << pos1[0].second << '\n';
			return;
		}
	}
	cout << -1 << '\n';
	// cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
	return 0;
}
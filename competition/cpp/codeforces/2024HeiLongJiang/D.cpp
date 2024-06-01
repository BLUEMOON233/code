#include<bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, ha, hb, t;
	cin >> n >> ha >> hb;
	vector<int> at_a, at_b;
	int de_a = 0, de_b = 0;
	rep(i, 1, n) {
		cin >> t;
		if (t == -1) {de_a++; continue;}
		at_a.emplace_back(t);
	}
	rep(i, 1, n) {
		cin >> t;
		if (t == -1) {de_b++; continue;}
		at_b.emplace_back(t);
	}
	sort(at_a.begin(), at_a.end(), [](int x, int y) {
		return x > y;
	});
	sort(at_b.begin(), at_b.end());

	rep(i, 0, n - 1) {
		if (i + 1 <= at_a.size() && i + 1 <= at_b.size()) {
			hb -= at_a[i];
			ha -= at_b[i];
			if (ha <= 0) {
				cout << "no\n";
				return;
			}
			if (hb <= 0) {
				cout << "yes\n";
				return;
			}
		}
	}
	cout << "no\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
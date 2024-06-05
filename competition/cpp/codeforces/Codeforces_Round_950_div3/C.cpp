#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];

	map<int, int> need;
	map<int, bool> mp;
	int sum = 0;
	// bool flag = true;
	rep(i, 1, n) {
		if (a[i] != b[i]) {
			sum++;
			need[b[i]]++;
			// flag = false;
		}
		mp[b[i]] = true;
	}

	int m;
	cin >> m;
	vector<int> d(m + 1);
	rep(i, 1, m) cin >> d[i];
	if (!mp[d[m]]) {
		cout << "NO\n";
		return;
	}

	rep(i, 1, m) {
		if (need[d[i]]) {
			need[d[i]]--;
			sum--;
		}
	}
	cout << (sum == 0 ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)


void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	sort(a.begin() + 1, a.end());
	int x = -1;
	rep(i, 2, n) {
		if (a[i] % a[1] == 0 || (x != -1 && a[i] % x == 0)) continue;
		if (x == -1) {
			x = a[i];
			continue;
		}
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
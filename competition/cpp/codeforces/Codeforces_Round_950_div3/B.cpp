#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, f, k;
	cin >> n >> f >> k;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];

	int fav = a[f];
	sort(a.begin() + 1, a.end(), [](int x, int y){
		return x > y;
	});
	if (a[k] > fav) {
		cout << "NO\n";
		return;
	}
	if (k != n && a[k + 1] == fav) {
		cout << "MAYBE\n";
		return;
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
	return 0;
}
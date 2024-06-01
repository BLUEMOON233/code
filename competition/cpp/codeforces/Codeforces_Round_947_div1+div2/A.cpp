#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, 0, n - 1) cin >> a[i];
	rep(i, 0, n - 1) {
		bool flag = true;
		rep(j, 0, n - 2) {
			int p1 = (i + j) % n;
			int p2 = (i + j + 1) % n;
			if (a[p1] > a[p2]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
}
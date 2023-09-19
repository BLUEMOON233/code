#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector<PII>	lr(n + 1, {n + 1, 0});
	unordered_map<int, int> mp;
	set<int> nums;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) nums.insert(a[i]);
	int now = 0;
	for (auto it = nums.begin(); it != nums.end(); it++) {
		// cout << *it << '\n';
		mp[*it] = ++now;
	}
	rep(i, 1, n) a[i] = mp[a[i]];
	rep(i, 1, n) if (a[i]) lr[a[i]].first = min(lr[a[i]].first, i), lr[a[i]].second = max(lr[a[i]].second, i);
	per(i, now - 1, 1) lr[i].first = min(lr[i + 1].first, lr[i].first), lr[i].second = max(lr[i + 1].second, lr[i].second);
	rep(i, 1, k) {
		if (mp[i]) cout << 2LL * (lr[mp[i]].second - lr[mp[i]].first + 1) << ' ';
		else cout << 0 << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
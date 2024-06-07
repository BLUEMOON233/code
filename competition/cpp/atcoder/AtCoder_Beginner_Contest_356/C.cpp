#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int k, n, m;
	cin >> n >> m >> k;
	// unordered_map<int, bool> p;
	set<int> st;
	rep(i, 0, (1 << n) - 1) st.insert(i);
	rep(times, 1, m) {
		int size;
		cin >> size;
		vector<int> a(size + 1);
		rep(i, 1, size) cin >> a[i];
		rep(i, 1, size) a[i]--;
		char r;
		cin >> r;
		vector<int> fail;
		for (auto it = st.begin(); it != st.end(); it++) {
			int now = *it;
			int cnt = 0;
			rep(i, 1, size) if ((now >> a[i]) & 1) cnt++;
			if ((cnt < k && r == 'x') || (cnt >= k && r == 'o')) continue;
			fail.emplace_back(now);
		}
		for(int now : fail) st.erase(now);
	}

	cout << st.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
	return 0;
}
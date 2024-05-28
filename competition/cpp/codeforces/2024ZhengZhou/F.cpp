#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	int rs = 0;
	vector<string> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		if (a[i].size() != 5) continue;
		if (a[i][2] != a[i][4]) continue;
		set<char> st;
		rep(j, 0, 3) st.insert(a[i][j]);
		if (st.size() == 4) rs++;
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
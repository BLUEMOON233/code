#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	vector<LL> a(n + 1), pre(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
	LL maxVal = -1;
	int rs = 0;
	rep(i, 1, n) {
		maxVal = max(maxVal, a[i]);
		if(maxVal == pre[i] - maxVal) rs++;
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while(_--) solve();
}
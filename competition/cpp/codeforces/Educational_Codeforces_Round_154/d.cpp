#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2, 0x3f3f3f3f);
	rep(i, 1, n) cin >> a[i];
	vector<int> inc(n + 1), dec(n + 2);
	rep(i, 1, n) if (a[i] <= a[i - 1]) inc[i] = 1;
	rep(i, 1, n) inc[i] += inc[i - 1];
	per(i, n, 1) if (a[i] <= a[i + 1]) dec[i] = 1;
	per(i, n, 1) dec[i] += dec[i + 1];
	LL rs = min(inc[n] - inc[1], dec[1] - dec[n] + 1);
	rep(i, 1, n - 1) {
		LL t = dec[1] - dec[i] + 1 + inc[n] - inc[i + 1];
		rs = min(rs, t);
	}
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
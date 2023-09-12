#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 3e5 + 1;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	vector<bool> f(n + 1, false);
	rep(i, 1, n) cin >> a[i];
	int rs = 0, now = a[1];
	rep(i, 1, n) if (a[i] <= now) f[i] = true, now = a[i];
	rep(i, 1, n) if (!f[i]) {now = a[i]; break;}
	rep(i, 1, n) if (!f[i] && a[i] <= now) rs++, now = a[i];
	cout << rs << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
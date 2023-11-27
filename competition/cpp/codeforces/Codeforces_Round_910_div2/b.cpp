#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	int now = a[n];
	LL rs = 0;
	per(i, n - 1, 1) {
		if (a[i] > now) {
			LL l = 1, r = 1e9 + 7;
			while (l < r) {
				LL mid = (l + r) >> 1;
				if (a[i] / mid + bool(a[i] % mid) <= now) r = mid;
				else l = mid + 1;
			}
			rs += l - 1;
			now = a[i] / l;
		}
		else now = a[i];
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
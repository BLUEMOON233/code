#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	LL n;
	cin >> n;
	vector<LL> c(n + 1), pos(n + 1);
	rep(i, 1, n) cin >> c[i];
	vector<LL> rs(n + 2, 0);
	per(i, n - 1, 1) c[i] = min(c[i], c[i + 1]);
	per(i, n, 2) c[i] -= c[i - 1];
	LL k;
	cin >> k;
	// rep(i, 1, n) cout << pos[i] << " \n"[i == n];
	LL lst = 1e9;
	rep(i, 1, n) {
		if (c[i] == 0) cout << lst << ' ';
		else {
			if (k / c[i] < lst) {
				lst = k / c[i];
				k %= c[i];
			} else {
				k -= lst * c[i];
			}
			cout << lst << ' ';
		}
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
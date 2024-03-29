#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void init() {
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (c != a + 1) {
		std::cout << -1 << "\n";
		return;
	}
	queue<int> q;
	q.push(0);
	int ans = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ans = x;
		if (a) {
			a--;
			q.push(x + 1);
			q.push(x + 1);
		} else if (b) {
			b--;
			q.push(x + 1);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	init();
	while (T--) solve();
	return 0;
}
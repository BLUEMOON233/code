#include<bits/stdc++.h>
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> cnt(10, 0);
	auto get_cnt = [&](int x) -> void{
		while (x) {
			cnt[x % 10]++;
			x /= 10;
		}
	};
	rep(i, 1, n) {
		get_cnt(i);
	}
	cout << cnt[x] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
}
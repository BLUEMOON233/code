#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

const int N = 2e5 + 7;
vector<int> pre(N, 0);
void init() {
	auto get_sum = [](int x) -> int {
		int ret = 0;
		while (x) {
			ret += x % 10;
			x /= 10;
		}
		return ret;
	};
	rep(i, 1, N) pre[i] = get_sum(i) + pre[i - 1];
}

void solve() {
	int x;
	cin >> x;
	cout << pre[x] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int T = 1;
	cin >> T;
	while (T--) solve();
}
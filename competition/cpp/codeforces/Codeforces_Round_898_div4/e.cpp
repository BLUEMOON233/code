#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
const int N = 1;

inline void solve() {
	LL n, x;
	cin >> n >> x;
	vector<LL> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	LL l = 0, r = 2e9 + 7;
	auto check = [&](LL h) -> bool {
		LL rs = 0;
		rep(i, 1, n) if (h > a[i]) rs += h - a[i];
		return rs <= x;
	};
	while (l < r) {
		LL mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

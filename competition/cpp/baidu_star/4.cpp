#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

void solve() {
	LL p, q, a, b, c;
	cin >> p >> q >> a >> b >> c;
	bool f = false;
	LL rs1 = 0x3f3f3f3f;
	LL rs2 = -1;
	if (c == a) {
		if (q % c == 0) {
			if (q / c == p) {
				cout << 0 << ' ' << p << '\n';
			} else {
				cout << -1 << '\n';
			}
		} else {
			cout << -1 << '\n';
		}
		return;
	}
	rep(y, 0, p) {
		LL t = q - a * p - (b - a) * y;
		if (t >= 0 && t % (c - a) == 0) {
			LL z = t / (c - a);
			if (z + y <= p && z >= 0) {
				f = true;
				rs1 = min(rs1, z);
				rs2 = max(rs2, z);
			}
		}
	}
	if (f) cout << rs1 << ' ' << rs2 << '\n';
	else cout << -1 << '\n';
}

int main() {
	fast();
	solve();
	return 0;
}
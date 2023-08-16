#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

void solve() {
	int n;
	cin >> n;
	vector<int> x(n + 1), y(n + 1), z(n + 1);
	rep(i, 1, n) cin >> x[i] >> y[i] >> z[i];
	sort(x.begin() + 1, x.end());
	sort(y.begin() + 1, y.end());
	sort(z.begin() + 1, z.end());
	if (n & 1) {
		int pos = n / 2 + 1;
		LL xx = 0, yy = 0, zz = 0;
		rep(i, 1, n) xx += abs(x[i] - x[pos]);
		rep(i, 1, n) yy += abs(y[i] - y[pos]);
		rep(i, 1, n) zz += abs(z[i] - z[pos]);
		LL dx = 0, dy = 0, dz = 0;
		rep(i, 1, pos - 1) dx += abs(x[i] - (x[pos] - pos + i));
		rep(i, pos + 1, n) dx += abs(x[i] - (x[pos] - pos + i));
		rep(i, 1, pos - 1) dy += abs(y[i] - (y[pos] - pos + i));
		rep(i, pos + 1, n) dy += abs(y[i] - (y[pos] - pos + i));
		rep(i, 1, pos - 1) dz += abs(z[i] - (z[pos] - pos + i));
		rep(i, pos + 1, n) dz += abs(z[i] - (z[pos] - pos + i));
		cout << min({xx + yy + dz, xx + dy + zz, dx + yy + zz}) << '\n';
	} else {
		int pos = n / 2;
		LL xx = 0, yy = 0, zz = 0;
		rep(i, 1, n) xx += abs(x[i] - x[pos]);
		rep(i, 1, n) yy += abs(y[i] - y[pos]);
		rep(i, 1, n) zz += abs(z[i] - z[pos]);
		LL dx = 0, dy = 0, dz = 0;
		rep(i, 1, pos - 1) dx += abs(x[i] - (x[pos] - pos + i));
		rep(i, pos + 1, n) dx += abs(x[i] - (x[pos] - pos + i));
		rep(i, 1, pos - 1) dy += abs(y[i] - (y[pos] - pos + i));
		rep(i, pos + 1, n) dy += abs(y[i] - (y[pos] - pos + i));
		rep(i, 1, pos - 1) dz += abs(z[i] - (z[pos] - pos + i));
		rep(i, pos + 1, n) dz += abs(z[i] - (z[pos] - pos + i));
		LL rs = min({xx + yy + dz, xx + dy + zz, dx + yy + zz});
		// cout << min({xx + yy + dz, xx + dy + zz, dx + yy + zz}) << '\n';
		pos++;
		xx = 0, yy = 0, zz = 0;
		rep(i, 1, n) xx += abs(x[i] - x[pos]);
		rep(i, 1, n) yy += abs(y[i] - y[pos]);
		rep(i, 1, n) zz += abs(z[i] - z[pos]);
		dx = 0, dy = 0, dz = 0;
		rep(i, 1, pos - 1) dx += abs(x[i] - (x[pos] - pos + i));
		rep(i, pos + 1, n) dx += abs(x[i] - (x[pos] - pos + i));
		rep(i, 1, pos - 1) dy += abs(y[i] - (y[pos] - pos + i));
		rep(i, pos + 1, n) dy += abs(y[i] - (y[pos] - pos + i));
		rep(i, 1, pos - 1) dz += abs(z[i] - (z[pos] - pos + i));
		rep(i, pos + 1, n) dz += abs(z[i] - (z[pos] - pos + i));
		rs = min({rs, xx + yy + dz, xx + dy + zz, dx + yy + zz});
		cout << rs << '\n';
	}
}

int main() {
	fast();
	solve();
	return 0;
}
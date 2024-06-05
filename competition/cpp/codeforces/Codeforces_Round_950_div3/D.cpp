#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n - 1) b[i] = __gcd(a[i], a[i + 1]);
	rep(i, 1, n - 1) cerr << b[i] << " \n"[i == n - 1];
	b[0] = -1, b[n] = 0x3f3f3f3f;

	bool flag = true;

	if (b[1] > b[2]) {
		if (b[2] <= b[3]) {
			flag = false;
		}
	}
	// cout << flag << '\n';
	per(i, 2, n - 2) {
		if (b[i] > b[i + 1] && flag) {
			//remove next
			if (i != n - 2 && __gcd(a[i], a[i + 2]) <= b[i + 2] && b[i - 1] <= b[i + 2] && b[i - 1] <= __gcd(a[i], a[i + 2])) {
				flag = false;
				i++;
				continue;
			}
			//remove now
			// cout << __gcd(a[i - 1], a[i + 1]) << ' ' << b[i + 1] << '\n';
			if (__gcd(a[i - 1], a[i + 1]) <= b[i + 1] && b[i - 2] <= b[i + 1] && b[i - 2] <= __gcd(a[i - 1], a[i + 1])) {
				flag = false;
				continue;
			}

			if (i == n - 2) {
				if (b[i - 1] <= b[i]) {
					cout << "YES\n";
					return;
				}
				else {
					cout << "NO\n";
					return;
				}
			}
			// cerr << __gcd(a[i], a[i + 2]) << b[i + 2] << '\n';
			cout << "NO\n";
			return;
		}
	}

	if(b[n - 2] > b[n - 1]) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) solve();
	return 0;
}
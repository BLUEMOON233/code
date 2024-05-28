#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
const int mod = 998244353;

ll quickPow(ll a, ll b, ll mod) {
	ll rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}
ll quickPow(ll a, ll mod) {
	return quickPow(a, mod - 2, mod);
}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	ll n;
	cin >> n;

	vector<ll> op(2 * n);
	vector<ll> ve;

	for (int i = 0; i < 2 * n; i += 1) {
		cin >> op[i];
		if (op[i] != -1) {
			ve.push_back(op[i]);
		}
	}

	sort(ve.begin(), ve.end());

	ll ans = 1;
	ll cur = 0;
	map<ll, ll> cnt;
	for (int i = 0, p = 0; i < 2 * n; i += 1) {
		if (op[i] == -1) {
			if (cnt.count(ve[p]) == 0) {
				cout << 0 << '\n';
				return 0;
			}
			ans = ans * cnt[ve[p]] % mod;
			ans = ans * quickPow(cur, mod) % mod;
			cnt[ve[p]] -= 1;
			cur -= 1;
			p += 1;
		} else {
			cnt[op[i]] += 1;
			cur += 1;
			//p+=1;
		}
	}

	cout << ans << '\n';


	return 0;

}
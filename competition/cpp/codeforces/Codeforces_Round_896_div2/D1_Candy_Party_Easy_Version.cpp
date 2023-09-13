#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

inline void solve() {
	int n;
	cin >> n;
	vector<LL> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	LL sum = 0;
	rep(i, 1, n) sum += a[i];
	if (sum % n) {
		cout << "NO\n";
		return;
	}
	LL avg = sum / n;
	unordered_map<LL, int> in, out;
	// vector<LL> chk;
	set<LL> st;
	rep(i, 1, n) {
		LL dis = avg - a[i];
		if (dis == 0) {
			// cout << a[i] << ' ' << 0 << ' ' << 0 << '\n';
		} else if (dis > 0) {
			LL lb = dis & -dis;
			LL tmp = dis, big = 1;
			while (tmp) tmp >>= 1, big *= 2;
			if (big - lb != dis) {
				cout << "NO\n";
				return;
			}
			in[lb]++;
			out[big]++;
			st.insert(big), st.insert(lb);
			// cout << a[i] << ' ' << lb << ' ' << big << '\n';
		} else {
			dis = -dis;
			LL lb = dis & -dis;
			LL tmp = dis, big = 1;
			while (tmp) tmp >>= 1, big *= 2;
			if (big - lb != dis) {
				cout << "NO\n";
				return;
			}
			in[big]++;
			out[lb]++;
			st.insert(big), st.insert(lb);
			// cout << a[i] << ' ' << big << ' ' << lb << '\n';
		}
	}
	// cout << '\n';
	for (auto it = st.begin(); it != st.end(); it++) {
		if (in[*it] != out[*it]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
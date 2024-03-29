#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void init() {
}

void solve() {
	int n;
	string str;
	cin >> n >> str;

	auto check = [&](int len) -> bool {
		unordered_map<string, int> mp;
		vector<string> strs;
		for (int i = 0; i <= n - 1; i += len) {
			string sub_str = str.substr(i, len);
			if (mp[sub_str] == 0) strs.emplace_back(sub_str);
			mp[sub_str]++;
		}
		if (strs.size() == 1) {
			cout << strs[0].size() << '\n';
			return true;
		}
		if (strs.size() > 2) return false;
		if (mp[strs[0]] > 1 && mp[strs[1]] > 1) return false;
		int cnt = 0;
		rep(i, 0, len - 1) if (strs[0][i] != strs[1][i]) cnt++;
		if (cnt >= 2) return false;
		cout << strs[0].size() << '\n';
		return true;
	};

	rep(p, 1, sqrt(n)) if (n % p == 0) {
		bool flag = check(p);
		if (flag) return;
	}
	per(p, sqrt(n), 1) if (n % p == 0) {
		bool flag = check(n / p);
		if (flag) return;
	}
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
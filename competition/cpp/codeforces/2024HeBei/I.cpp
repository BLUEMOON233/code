#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)
struct Net {
	string ipv4 = "";
	int cidr = 0;
};

void solve() {
	string s;
	cin >> s;
	auto format = [](string s) -> Net {
		string ret = "";
		int now = 0;
		bool flag = true;
		for (int i = 0; i <= s.length() - 1; i++) {
			if (s[i] == '.') {
				per(bit, 7, 0) ret += ((now >> bit) & 1) ? '1' : '0';
				now = 0;
				continue;
			}
			if (s[i] == '/') {
				per(bit, 7, 0) ret += ((now >> bit) & 1) ? '1' : '0';
				now = 0;
				flag = false;
				continue;
			}
			now = (now << 3) + (now << 1) + s[i] - '0';
		}
		if (flag) {
			per(bit, 7, 0) ret += ((now >> bit) & 1) ? '1' : '0';
			return {ret, -1};
		}
		// cerr << "ipv4: " << ret << ' ' << now << '\n';
		return {ret, now};
	};
	auto [net, range] = format(s);
	int n;
	cin >> n;
	vector<string> nets(n + 1);
	rep(i, 1, n) cin >> nets[i];
	auto check = [&](string subnet) -> bool {
		rep(i, 0, range - 1) {
			if (subnet[i] != net[i]) {
				return false;
			}
		}
		return true;
	};
	rep(i, 1, n) {
		auto [subnet, temp] = format(nets[i]);
		cout << (check(subnet) ? "YES\n" : "NO\n");

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
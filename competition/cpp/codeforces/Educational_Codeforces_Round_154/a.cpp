#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
	string s;
	cin >> s;
	for (auto c : s) if (c == '1') {
			cout << "13\n";
			return;
		} else if (c == '3') {
			cout << "31\n";
			return;
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
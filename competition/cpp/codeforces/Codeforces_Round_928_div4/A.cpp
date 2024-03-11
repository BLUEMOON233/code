#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	string s;
	cin >> s;
	int a = 0, b = 0;
	rep(i, 0, 4) if (s[i] == 'A') a++;
	else b++;
	cout << (a > b ? 'A' : 'B') << '\n';
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
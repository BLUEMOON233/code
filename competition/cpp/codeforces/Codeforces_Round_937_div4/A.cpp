#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a < b && b < c) cout << "STAIR\n";
	else if (a < b && b > c) cout << "PEAK\n";
	else cout << "NONE\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
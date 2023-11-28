#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	if (n % 3) cout << "First\n";
	else cout << "Second\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
}
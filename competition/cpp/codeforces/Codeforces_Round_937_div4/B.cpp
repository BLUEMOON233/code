#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n;
	cin >> n;
	vector<char> line(n * 2, '.');
	for (int i = 0; i <= n * 2 - 1; i += 4)
		line[i] = line[i + 1] = '#';
	// for (char c : line) cout << c;
	rep(i, 1, n) {
		if (i % 2 == 1) {
			for (char c : line) cout << c;
			cout << '\n';
			for (char c : line) cout << c;
			cout << '\n';
		} else {
			rep(i, 2, n * 2 - 1) cout << line[i];
			cout << line[n * 2 - 3] << line[n * 2 - 3] << '\n';
			rep(i, 2, n * 2 - 1) cout << line[i];
			cout << line[n * 2 - 3] << line[n * 2 - 3] << '\n';
		}
	}
	// cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
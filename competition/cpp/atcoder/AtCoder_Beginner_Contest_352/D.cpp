#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> p;
	rep(i, 1, n) {
		int key, val;
		cin >> key >> val;
		p[key] = val;
	}
	priority_queue<int, vector<int>, greater<int>> minVal;
	priority_queue<int, vector<int>, less<int>> maxVal;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	// cin >> T;
	while (T--) solve();
	return 0;
}
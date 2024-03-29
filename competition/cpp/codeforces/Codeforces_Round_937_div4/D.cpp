#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

unordered_map<int, bool> mp;
vector<int> nums;


void init() {
	queue<string> q;
	q.push("0");
	q.push("1");
	while (!q.empty()) {
		string now = q.front();
		q.pop();
		int num = atoi(now.c_str());
		if (num != 0 && num != 1)
			nums.emplace_back(num);
		if (now.size() < 6) q.push(now + '0');
		if (now.size() < 6) q.push(now + '1');
	}
	for (int number : nums)
		mp[number] = true;
	mp[0] = mp[1] = true;
}

void solve() {
	int n;
	cin >> n;
	while (!mp[n]) {
		bool f = false;
		for (int number : nums) if (n % number == 0) {
				n /= number;
				f = true;
				break;
			}
		if (!f) {
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
	init();
	while (T--) solve();
	return 0;
}
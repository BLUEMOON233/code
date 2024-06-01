#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	string s;
	cin >> s;
	vector<char> stack;
	rep(i, 0, s.length() - 1) {
		if (stack.size() >= 2) {
			if (stack[stack.size() - 1] == stack[stack.size() - 2] && s[i] == stack[stack.size() - 1]) {
				stack.pop_back();
				stack.pop_back();
				continue;
			}
		}
		stack.emplace_back(s[i]);
	}
	if (stack.size() == 0) {cout << "NAN\n"; return;}
	for (char c : stack) cout << c;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) solve();
}
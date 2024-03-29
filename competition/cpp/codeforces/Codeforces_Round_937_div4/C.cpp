#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)

void solve() {
	string str;
	cin >> str;
	string tmp = "";
	tmp += str[0];
	tmp += str[1];
	int hour = atoi(tmp.c_str());
	// cout << tmp << '\n';
	string apm = (hour >= 12) ? "PM" : "AM";
	if (hour == 0) hour += 12;
	if (hour > 12) hour -= 12;
	if (hour >= 10) cout << hour << ":";
	else cout << '0' << hour << ":";
	cout << str[3] << str[4] << ' ' << apm << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
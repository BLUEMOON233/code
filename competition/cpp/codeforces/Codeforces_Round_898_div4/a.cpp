#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
const int N = 1;

inline void solve() {
	string s;
	string t = "abc";
	cin >> s;
	int cnt = 0;
	rep(i, 0, 2) if (s[i] == t[i]) cnt++;
	if (cnt == 3 || cnt == 1) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

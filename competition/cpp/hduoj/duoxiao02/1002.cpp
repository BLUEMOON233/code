#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define mes(tmp, data) memset(tmp, data, sizeof tmp)
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << " = " << x << endl;
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout<<tmp[i]<<" \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout<<tmp[i]<<" \n"[i == Size]
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"

const int N = 1;

inline void solve() {
	LL n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (n == 1) {
		cout << 1 - (k % 2) << '\n';
		return;
	}
	bool f = true;
	bool ff = true;
	rep(i, 0, s.size() - 1) {
		if (s[i] == '0') {
			ff = false; break;
		}
	}
	// cout << ff << '\n';
	if (ff) {
		if (k == 1) s[s.size() - 1] = '0';
		cout << s << '\n';
		return;
	}
	rep(i, 0, s.size() - 1) {
		if (s[i] == '1') {f = true; continue;}
		if (f && s[i] == '0' && k) {
			k--;
			f = false;
		}
		if (!f) s[i] = '1';
	}
	// k %= 2;
	// cout << k << '\n';
	// if (k == 1) {
	// 	k--;
	// 	s[s.size() - 1] = '0';
	// }
	cout << s << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

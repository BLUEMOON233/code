#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
const int N = 1;

inline void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	LL rs1 = 0, rs2 = 0;
	rep(i, 0, n - 1) if (s[i] == 'B') rs1++, i += k - 1;
	per(i, n - 1, 0) if (s[i] == 'B') rs2++, i -= k - 1;
	cout << min(rs1 , rs2) << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

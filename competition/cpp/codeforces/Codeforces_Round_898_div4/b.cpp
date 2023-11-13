#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
const int N = 1;

inline void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	rep(i, 1, n) cin >> a[i];
	sort(a.begin() + 1, a.end());
	a[1]++;
	LL rs = 1;
	rep(i, 1, n) rs *= a[i];
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

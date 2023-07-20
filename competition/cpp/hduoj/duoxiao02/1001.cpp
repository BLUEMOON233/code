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
	cin >> k >> n;
	if (n == 0) {
		cout << "Bob\n";
		return;
	}
	// LL now = k + 1;
	// vector<LL> lose;
	// while (now <= n) {
	// 	lose.push_back(now);
	// 	for (auto x : lose) if (x + now + k <= n) lose.push_back(x + now + k);
	// }
	// map<int, bool> mp;
	LL now = 1;
	while ((now * 2 - 1) * k + now <= n) {
		if (n == (now * 2 - 1) * k + now) {
			cout << "Bob\n";
			return;
		}
		now++;
	}
	cout << "Alice\n";
	// if (mp[n]) cout << "Bob\n";
	// else cout << "Alice\n";
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

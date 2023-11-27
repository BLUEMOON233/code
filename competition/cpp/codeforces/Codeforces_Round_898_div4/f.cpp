#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
const int N = 1;

inline void solve() {
	LL n, k;
	cin >> n >> k;
	vector<LL> a(n + 1), h(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> h[i];
	queue<LL> que;
	LL rs = 0, sum = 0;
	rep(i, 1, n) {
		if (que.empty()) {
			que.push(i);
			sum += a[i];
		}
		else {
			if (h[que.back()] % h[i] != 0) {
				que = queue<LL>();
				sum = 0;
			}
			que.push(i);
			sum += a[i];
		}
		while (sum > k) sum -= a[que.front()], que.pop();
		rs = max(rs, (LL)que.size());
	}
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

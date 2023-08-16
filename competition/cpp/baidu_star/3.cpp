#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)

const int N = 2e5 + 7, M = 6e5 + 21;

int dist[N], h[N], e[M], ne[M], idx = 0;
bool st[N];
inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}
int n;


int djk(int s) {
	priority_queue<PII, vector<PII>, greater<PII> > heap;
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	heap.push({0, s});
	while (!heap.empty()) {
		auto [d, v] = heap.top();
		heap.pop();
		if (st[v]) continue;
		st[v] = true;
		for (int i = h[v]; i; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[v] + 1) {
				dist[j] = dist[v] + 1;
				heap.push({dist[j], j});
			}
		}
	}
	return dist[n];
}

void solve() {
	cin >> n;
	vector<int> a(n + 1);
	vector<int> mp(1e6 + 1, -1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) {
		if (i == 1) add(i, i + 1);
		else if (i == n) add(i, i - 1);
		else add(i, i - 1), add(i, i + 1);
		if (mp[a[i]] != -1) add(mp[a[i]], i);
		mp[a[i]] = i;
	}
	// cout << "yes\n";
	cout << djk(1) << '\n';
}

int main() {
	fast();
	solve();
	return 0;
}
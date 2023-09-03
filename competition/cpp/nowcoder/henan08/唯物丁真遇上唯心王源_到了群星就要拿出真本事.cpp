#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

struct DSU {
    vector<int> p, Size;
    DSU(int n) : p(n + 1), Size(n + 1, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        Size[x] += Size[y], p[y] = x;
        return true;
    }
    int size(int x) { return Size[find(x)]; }
};

inline void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    DSU dsu(n);
    rep(i, 1, n) cin >> dsu.Size[i];
    vector<int> con(n + 1);
    rep(i, 1, n) cin >> con[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (con[x] == con[y] && con[x] == 1) {
            dsu.merge(x, y);
        }
    }
    priority_queue<int> pq;
    unordered_map<int, bool> mp;
    rep(i, 1, n) if (con[i] == 1 && mp[dsu.find(i)] == false) {
        LL now = dsu.size(i);
        mp[dsu.find(i)] = true;
        pq.push(now);
    }
    LL rs = 0;
    while (pq.size() && k) {
        k--;
        // cout << pq.top() << '\n';
        rs += pq.top();
        pq.pop();
    }
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
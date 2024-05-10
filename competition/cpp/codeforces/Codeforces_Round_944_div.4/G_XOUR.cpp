#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) b[i] = (a[i] >> 2);
    map<int, bool> inList;
    vector<int> blist;
    rep(i, 1, n) {
        if (inList[b[i]]) continue;
        inList[b[i]] = true;
        blist.emplace_back(b[i]);
    }

    map<int, vector<int>> mp;
    map<int, int> pos;
    rep(i, 1, n) mp[b[i]].emplace_back(a[i]);
    for (int val : blist) {
        sort(mp[val].begin(), mp[val].end());
    }
    vector<int> rs(n + 1);
    rep(i, 1, n) {
        int p = pos[b[i]];
        pos[b[i]]++;
        rs[i] = mp[b[i]][p];
    }
    rep(i, 1, n) cout << rs[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
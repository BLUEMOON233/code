#include<bits/stdc++.h>
using ll = long long;
using db = double;
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 7;
const db eps = 1e-6;

set<int> sq;
int pos[maxn], a[maxn];
int pre[maxn];
set<int> ri[maxn];
set<pair<int, int>> cnt[maxn];

void pre_cal() {
    for (int i = 1; i * i <= 200000; i++) sq.insert(i * i);
}

inline void slv() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = 0;
        ri[i].clear();
        cnt[i].clear();
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (auto j : sq) {
            if (j - a[i] > 0 && j - a[i] <= n) {
                if (pos[j - a[i]] > i) {
                    ri[i].insert(pos[j - a[i]]);
                    pre[pos[j - a[i]]]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
        for (auto j : cnt[i - 1]) {
            if (j.second > i) {
                cnt[i].insert(j);
            }
        }
        for (auto j : ri[i]) {
            cnt[i].insert({i, j});
        }
    }
    vector<vector<int>> fin_r(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto j : cnt[i]) {
            if (j.first < i && j.second > i) fin_r[i].emplace_back(j.second);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = pre[r] - pre[l];
        int q = 0, p = fin_r[l].size() - 1;
        while (q < p) {
            int m = q + p + 1 >> 1;
            if (fin_r[l][m] > r) {
                p = m - 1;
            } else {
                q = m;
            }
        }
        if (min(p, q) >= 0 && max(p, q) < fin_r[l].size()) {
            if (fin_r[l][q] <= r) ans -= q + 1;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    pre_cal();
    cin >> _;
    while (_--) slv();
}
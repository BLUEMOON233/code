#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 5e5 + 7, mod = 1e9 + 7;
LL quickPow(LL a, LL b, LL mod) {
    LL rs = 1;
    while (b) {
        if (b & 1) rs = rs * a % mod;
        b >>= 1, a = a * a % mod;
    }
    return rs % mod;
}

inline void solve() {
    int n;
    cin >> n;
    vector<PII> l1(n + 1), l2(n + 1);
    rep(i, 1, n) cin >> l1[i].first >> l1[i].second >> l2[i].first >> l2[i].second;
    // build(1, 1, 5e5);
    vector<int> dis(N, 0);
    vector<PII> pls;
    rep(i, 1, n) {
        auto [a, b] = l1[i];
        auto [c, d] = l2[i];
        if (a > c) swap(a, c), swap(b, d);
        dis[a] += 1, dis[b + 1] -= 1;
        dis[c] += 1, dis[d + 1] -= 1;

        // modify(1, a, b, 1), modify(1, c, d, 1);
        if (b >= c) {
            // modify(1, c, min(b, d), -1);
            pls.emplace_back(c, min(b, d));
            dis[c] -= 1, dis[min(b, d) + 1] += 1;
        }
    }
    rep(i, 1, 5e5) dis[i] += dis[i - 1];
    // rep(i, 1, 4) cout << dis[i] << ' ';
    // cout << '\n';
    vector<bool> st(5e5 + 1);
    rep(i, 1, 5e5) if (dis[i] == n) st[i] = true;
    per(i, 5e5, 1) dis[i] = dis[i] - dis[i - 1];
    // build(1, 1, 5e5);
    for (auto [l, r] : pls) dis[l] += 1, dis[r + 1] -= 1;
    rep(i, 1, 5e5) dis[i] += dis[i - 1];
    // rep(i, 1, 4) cout << dis[i] << ' ';
    // cout << '\n';
    LL rs = 0;
    rep(i, 1, 5e5) if (st[i]) {
        rs = (rs + quickPow(2, dis[i] - n, mod)) % mod;
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
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), rs(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rs[i] = n + 1 - a[i];
    int f = -1;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 2; i <= n - 2; i += 2) {
        if (rs[i] == n) {
            f = i;
            int temp = rs[i];
            rep(j, i, n - 1) rs[j] = rs[j + 1];
            rs[n] = temp;
        }
        rs[i] += 1;
        pq.push(rs[i]);
    }
    vector<PII> rec(n + 1);
    rep(i, 1, n) rec[i] = {rs[i], i};
    sort(rec.begin() + 1, rec.end(), [&](PII a, PII b) {
        return a.first > b.first;
    });
    rep(i, 1, n) {
        auto [val, pos] = rec[i];
        if (pos != n && pos % 2 == 0) continue;
        while (val == pq.top()) {
            pq.pop();
            val -= 1;
        }
        rec[i] = {val, pos};
    }
    sort(rec.begin() + 1, rec.end(), [&](PII a, PII b) {
        return a.second < b.second;
    });
    if (f != -1) {
        PII temp = rec[n];
        per(i, n - 1, f) rec[i + 1] = rec[i];
        rec[f] = temp;
    }
    rep(i, 1, n) cout << rec[i].first << " \n"[i == n];
    // rep(i, 1, n) cout << rec[i].first + a[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
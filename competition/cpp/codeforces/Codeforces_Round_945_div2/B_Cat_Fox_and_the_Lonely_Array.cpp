#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int tar = 0;
    rep(i, 1, n) tar |= a[i];
    auto check = [&](int k) -> bool {
        vector<int> bit(20, 0);
        rep(i, 1, k) rep(j, 0, 19) {
            bit[j] += (a[i] >> j) & 1;
        }
        int now = 0;
        rep(j, 0, 19) if (bit[j] > 0) now |= (1 << j);
        if (now != tar) return false;

        for (int i = 2; i + k - 1 <= n; i++) {
            rep(j, 0, 19) {
                bit[j] -= (a[i - 1] >> j) & 1;
                bit[j] += (a[i + k - 1] >> j) & 1;
            }
            int now = 0;
            rep(j, 0, 19) if (bit[j] > 0) now |= (1 << j);
            if (now != tar) return false;
        }
        return true;
    };
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
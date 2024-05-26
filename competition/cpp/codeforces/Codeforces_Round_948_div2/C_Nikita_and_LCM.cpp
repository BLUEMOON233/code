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
    unordered_map<int, bool> mp;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) mp[a[i]] = true;
    LL val = 1;
    rep(i, 1, n) {
        val = lcm(val, 1LL * a[i]);
        if (val > 1E9)
            break;
    }
    auto it = find(a.begin() + 1, a.end(), val);
    if (it == a.end()) {
        cout << n << '\n';
        return;
    }
    int rs = 0;
    auto op = [&](int x) {
        if (mp[x]) return;
        int now = 0;
        int val = 1;
        rep(i, 1, n) if (x % a[i] == 0) {
            val = lcm(val, a[i]);
            now++;
        }
        if (val == x) rs = max(now, rs);
    };
    rep(i, 1, val / i) if (val % i == 0) op(i), op(val / i);
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), b(n + 2);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    LL rs = 0;
    bool flag = false;
    rep(i, 1, n) {
        rs += abs(a[i] - b[i]);
        LL minVal = min(a[i], b[i]);
        LL maxVal = max(a[i], b[i]);
        if (minVal <= b[n + 1] && b[n + 1] <= maxVal) {
            flag = true;
        }
    }
    if (!flag) {
        LL cost = 1e18 + 7;
        rep(i, 1, n) {
            cost = min(cost, abs(a[i] - b[n + 1]));
            cost = min(cost, abs(b[i] - b[n + 1]));
        }
        rs += cost;
    }
    cout << rs + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    vector<int> a(3, 0);
    rep(i, 0, 2) cin >> a[i];
    int sum = a[0] + a[1] + a[2];
    sort(a.begin(), a.end());
    if (sum & 1) {
        cout << -1 << '\n';
        return;
    }
    if (a[2] <= a[0] + a[1]) {
        cout << sum / 2 << '\n';
    } else {
        cout << a[0] + a[1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
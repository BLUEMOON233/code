#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

constexpr int mod = 1E8;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    LL sum = 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) sum += a[i] * (n - 1);
    sort(a.begin() + 1, a.end());
    for (int l = 1, r = n; l <= n - 1; l++) {
        while (a[r] + a[l] >= mod && l < r) {
            r--;
        }
        sum -= 1LL * (n - max(r, l)) * mod;
    }

    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
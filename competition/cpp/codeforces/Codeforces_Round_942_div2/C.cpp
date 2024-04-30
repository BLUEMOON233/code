#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
vector<LL> a;
LL n, k;
bool check(LL x) {
    LL sum = 0;
    rep(i, 1, n) {
        sum += max(x - a[i], 0LL);
        if (sum > k) return false;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    a.resize(n + 1);
    rep(i, 1, n) cin >> a[i];
    LL l = 0, r = 1e18;
    while (l < r) {
        LL mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    int ex = 0;
    rep(i, 1, n) if (a[i] > l - 1) ex++;
    else k -= (l - 1 - a[i]);
    cout << n * (l - 2) + 1 + ex + k << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
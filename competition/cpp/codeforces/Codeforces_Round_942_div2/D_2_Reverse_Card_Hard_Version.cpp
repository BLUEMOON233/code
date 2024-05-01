#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)

void solve() {
    LL n, m, rs = 0;
    cin >> n >> m;
    rep(x, 1, n / x) rep(y, 1, m / y) if(__gcd(x, y) == 1) {
        rs += min(n / x, m / y) / (x + y);
    }
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
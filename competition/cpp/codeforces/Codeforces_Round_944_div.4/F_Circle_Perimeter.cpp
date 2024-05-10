#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    LL r;
    cin >> r;
    LL rs = 0;
    rep(y, 1, r) {
        LL x1 = ceil(sqrt(r * r - 1LL * y * y));
        LL x2 = ceil(sqrt((r + 1) * (r + 1) - 1LL * y * y)) - 1;
        // cout << y << ' ' << x1 << ' ' << x2 << '\n';
        rs += x2 - x1 + 1;
    }
    cout << rs * 4 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
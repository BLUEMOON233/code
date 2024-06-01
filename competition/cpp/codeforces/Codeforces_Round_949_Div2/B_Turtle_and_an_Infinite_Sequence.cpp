#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    LL n, m;
    cin >> n >> m;
    LL rs = n;
    rep(i, 0, 31) if (!((n >> i) & 1)) {
        LL tar = n >> i;
        tar++;
        tar <<= i;
        if (tar - n <= m) {
            rs += (1 << i);
            continue;
        }

        if ((n >> i) == 0) continue;
        tar = 0;
        rep(j, 0, i - 1) {
            tar += ((n >> j) & 1) << j;
        }
        if (tar + 1 <= m) {
            rs += (1 << i);
        }
    }
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    LL l, r;
    cin >> l >> r;
    LL now = 1;
    int rs = 0;
    while (true) {
        if ((now << 1) > r) break;
        now <<= 1;
        rs++;
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
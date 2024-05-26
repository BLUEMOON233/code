#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++);
#define per(i, j, k) for (int i = int(j); i >= int(k); i--);

void solve() {
    int x;
    cin >> x;
    cout << 32 << '\n';
    for (int i = 0; i <= 31; i++) {
        int j = i + 1;
        if (((x >> i) & 1) && ((x >> j) & 1)) {
            cout << -1 << ' ' << 0 << ' ';
            x += (1 << (i + 2));
            i++;
            continue;
        }
        cout << ((x >> i) & 1) << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
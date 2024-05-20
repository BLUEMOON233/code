#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int x, y;
    cin >> x >> y;
    int cnt = y / 2;
    x -= (y / 2) * 7;
    if (y % 2) {
        cnt++;
        x -= 11;
    }
    if (x > 0) {
        cnt += x / 15 + (x % 15 != 0);
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
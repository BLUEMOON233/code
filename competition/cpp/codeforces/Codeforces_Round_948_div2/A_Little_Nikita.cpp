#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++);
#define per(i, j, k) for (int i = int(j); i >= int(k); i--);

void solve() {
    int x, y;
    cin >> x >> y;
    if (x < y) {
        cout << "No\n";
        return;
    }
    if ((y - x) & 1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
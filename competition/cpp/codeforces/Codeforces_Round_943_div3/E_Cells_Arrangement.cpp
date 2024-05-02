#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        cout << '\n';
        return;
    }
    if (n == 3) {
        cout << 2 << ' ' << 1 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        cout << 3 << ' ' << 1 << '\n';
        cout << '\n';
        return;
    }
    if (n == 4) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 3 << '\n';
        cout << 4 << ' ' << 3 << '\n';
        cout << 4 << ' ' << 4 << '\n';
        cout << '\n';
        return;
    }
    cout << 1 << ' ' << 1 << '\n';
    cout << n << ' ' << 1 << '\n';
    cout << n << ' ' << n << '\n';
    rep(i, 3, n - 1) cout << 1 << ' ' << i << '\n';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = j; i <= int(k); i++)

void solve() {
    int l, r;
    cin >> l >> r;
    if (l == r) {
        rep(i, 2, sqrt(r)) {
            if (r % i == 0) {
                cout << i << ' ' << r - i << '\n';
                return;
            }
        }
        cout << -1 << '\n';
        return;
    }
    if (r > 3) {
        if (r & 1) r--;
        cout << r / 2 << ' ' << r / 2 << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
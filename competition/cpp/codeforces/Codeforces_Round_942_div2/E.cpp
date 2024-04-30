#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)

void solve() {
    LL n, m;
    cin >> n >> m;
    LL rs = 0;
    rep(k, 2, max(n, m)) {
        int a = n, b = m;
        rs += min(2 * a, b) / k;
        swap(a, b);
        rs += min(2 * a, b) / k;
    }
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
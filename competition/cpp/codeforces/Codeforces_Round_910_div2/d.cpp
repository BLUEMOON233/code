#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int n, y;
    cin >> n;
    int n1 = 0, n2 = 0;
    vector<int> a(n);
    rep(i, 0, n - 1) cin >> a[i];
    int mn1 = 1e9 + 7, mx1 = 0;
    int mn2 = 1e9 + 7, mx2 = 0;
    LL rs = 0;
    for (int i = 0; i < n; ++i) {
        cin >> y;
        if (a[i] >= y) {
            mn1 = min(mn1, a[i]);
            mx1 = max(mx1, y);
        }
        if (a[i] <= y) {
            mn2 = min(mn2, y);
            mx2 = max(mx2, a[i]);
        }
        rs += abs(a[i] - y);
    }
    int tmp = max(mx1 - mn1, mx2 - mn2);
    int tmp2 = max(mx2 - mn1, mx1 - mn2);
    tmp = max(tmp, tmp2);
    if (tmp > 0) {
        rs += 2LL * tmp;
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
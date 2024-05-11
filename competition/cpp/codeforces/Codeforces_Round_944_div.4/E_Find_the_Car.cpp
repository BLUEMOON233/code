#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    LL n, k, q;
    cin >> n >> k >> q;
    vector<LL> a(k + 1, 0), b(k + 1, 0);
    rep(i, 1, k) cin >> a[i];
    rep(i, 1, k) cin >> b[i];
    while (q--) {
        LL x;
        cin >> x;
        int p = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (a[p] == x) {
            cout << b[p] << ' ';
            continue;
        }
        cout << LL((x - a[p - 1]) * (b[p] - b[p - 1]) / (a[p] - a[p - 1]) + b[p - 1]) << ' ';
    }
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
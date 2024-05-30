#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + m + 1), b(n + m + 1);
    LL x{n}, y{m};
    vector<LL> v(n + m);
    rep(i, 0, n + m) cin >> a[i];
    rep(i, 0, n + m) cin >> b[i];
    LL sum = 0;
    rep(i, 0, n + m - 1) {
        if (x == 0) {
            v[i] = 1;
            sum += b[i];
            y--;
        } else if (y == 0) {
            v[i] = 0;
            sum += a[i];
            x--;
        } else {
            if (a[i] > b[i]) {
                v[i] = 0;
                sum += a[i];
                x--;
            } else {
                v[i] = 1;
                sum += b[i];
                y--;
            }
        }
    }
    vector<LL> ans(n + m + 1);
    ans[n + m] = sum;
    x = -1, y = -1;
    per(i, n + m - 1, 0) {
        if (v[i] == 1) {
            if (y == -1) {
                ans[i] = sum - b[i] + b[n + m];
            } else {
                ans[i] = sum - b[i] + b[y] - a[y] + a[n + m];
            }

        } else {
            if (x == -1) {
                ans[i] = sum - a[i] + a[n + m];
            } else {
                ans[i] = sum - a[i] + a[x] - b[x] + b[n + m];
            }
        }

        if (v[i] == 0) {
            if (b[i] > a[i]) {
                y = i;
            }

        } else {
            if (a[i] > b[i]) {
                x = i;
            }
        }
    }
    rep(i, 0, n + m) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) solve();
}
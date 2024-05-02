#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<int> x(n + 1), a(n + 1);
    rep(i, 2, n) cin >> x[i];
    a[1] = 501;
    rep(i, 2, n) a[i] = x[i] + a[i - 1];
    rep(i, 1, n) cout << a[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
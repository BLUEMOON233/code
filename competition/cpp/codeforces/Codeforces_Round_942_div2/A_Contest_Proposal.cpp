#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    int i, j;
    for (i = 1, j = 1; i <= n && j <= n;) {
        if (a[i] <= b[j])
            i++, j++;
        else
            j++;
    }
    cout << n - i + 1<< '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int i, j;
    for (i = 0, j = 0; i <= n - 1 && j <= m - 1;) {
        if (a[i] == b[j]) i++, j++;
        else j++;
    }
    cout << i << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
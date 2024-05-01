#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '@' + s;
    int cnt = 0;
    rep(i, 1, n) if (s[i] == 'U') cnt++;
    if (cnt & 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
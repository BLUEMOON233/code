#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 2, vector<int>(n + 1, 0)), b(n + 2, vector<int>(n + 1, 0));
    rep(i, 1, n) {
        string s; cin >> s;
        rep(j, 1, n) a[i][j] = s[j - 1] - '0';
    }
    int rs = 0;
    rep(i, 1, n) rep(j, 1, n) {
        a[i][j] ^= b[i][j];
        rs += a[i][j];
        b[i][j] ^= a[i][j];
        if (b[i][j]) {
            a[i + 1][j] ^= b[i][j];
            if (j - 1 >= 1) b[i + 1][j - 1] ^= b[i][j];
            else if (i + 2 <= n) b[i + 2][j] ^= b[i][j];
            if (j + 1 <= n)  b[i + 1][j + 1] ^= b[i][j];
            else if (i + 2 <= n)  b[i + 2][j] ^= b[i][j];
            if (i + 2 <= n) b[i + 2][j] ^= b[i][j];
        }
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
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = j; i <= int(k); i++)

void solve() {
    int n;
    cin >> n;
    vector<int> t(n + 1);
    rep(i, 1, n) {
        int a, b;
        cin >> a >> b;
        t[i] = a + a + b - 1;
        t[i] >>= 1;
    }
    // rep(i, 1, n) cout << t[i] << " \n"[i == n];
    int rs = 0x3f3f3f3f;
    rep(i, 1, n) rs = min(rs, t[i]);
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = j; i <= int(k); i++)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) pre[i] = pre[i - 1] ^ a[i];
    string s;
    cin >> s;
    s = '@' + s;
    int z = 0, o = 0;
    rep(i, 1, n) if (s[i] == '0') z ^= a[i];
    rep(i, 1, n) if (s[i] == '1') o ^= a[i];
    int q;
    cin >> q;
    while (q--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r;
            cin >> l >> r;
            o ^= pre[r] ^ pre[l - 1];
            z ^= pre[r] ^ pre[l - 1];
        }
        else {
            int x;
            cin >> x;
            if (x == 1) cout << o << ' ';
            else cout << z << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

inline void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    int now = m, cnt = 0;
    rep(i, 0, q - 1) if (s[i] == '+') cnt++;
    if (cnt + m < n) {
        cout << "NO\n";
        return;
    }
    if (now >= n) {
            cout << "YES\n";
            return;
        }
    rep(i, 0, q - 1) {
        if (s[i] == '-') now--;
        if (s[i] == '+') now++;
        if (now >= n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "MAYBE\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
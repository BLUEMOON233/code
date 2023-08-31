#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<string> s(n + 1);
    rep(i, 1, n) cin >> s[i];
    rep(i, 1, n) rep(j, i + 1, n) {
        string now = s[i] + s[j];
        bool f = true;
        for (int l = 0, r = now.length() - 1; l < r; l++, r--) {
            if (now[l] != now[r]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "Yes\n";
            return;
        }
        f = true;
        now = s[j] + s[i];
        for (int l = 0, r = now.length() - 1; l < r; l++, r--) {
            if (now[l] != now[r]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
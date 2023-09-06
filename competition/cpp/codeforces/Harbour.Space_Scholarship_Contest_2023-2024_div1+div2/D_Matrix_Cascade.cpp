#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<int> row(n + 1, 0);
    vector<int> inv(n + 1, 0);
    int rs = 0;
    rep(i, 1, n) {
        vector<int> nxt(n + 1, 0);
        rep(j, 1, n) {char t; cin >> t; row[j] = t - '0';}
        rep(j, 1, n) if (inv[j]) row[j] = 1 - row[j];
        rep(j, 1, n) cout << inv[j] << " \n"[j == n];
        rep(j, 1, n) if (row[j]) {
            rs++;
            if (j - 1 >= 1) {
                if (nxt[j - 1] == 0) nxt[j - 1] = 1;
                else nxt[j - 1] = 0;
            }
            if (j + 1 <= n) {
                if (nxt[j + 1] == 0) nxt[j + 1] = 3;
                else nxt[j + 1] = 0;
            }
            if (nxt[j] == 0) nxt[j] = 2;
            else nxt[j] = 0;
        }
        rep(j, 1, n) {
            if (inv[j] == 1) {
                if (j - 1 >= 1) {
                    if (nxt[j - 1] == 0) nxt[j - 1] = 1;
                    else nxt[j - 1] = 0;
                }
            } else if (inv[j] == 2) {
                if (j - 1 >= 1) {
                    if (nxt[j - 1] == 0) nxt[j - 1] = 1;
                    else nxt[j - 1] = 0;
                }
                if (j + 1 <= n) {
                    if (nxt[j + 1] == 0) nxt[j + 1] = 3;
                    else nxt[j + 1] = 0;
                }
                if (nxt[j] == 0) nxt[j] = 2;
                else nxt[j] = 0;
            } else if (inv[j] == 3) {
                if (j + 1 <= n) {
                    if (nxt[j + 1] == 0) nxt[j + 1] = 3;
                    else nxt[j + 1] = 0;
                }
            }
        }
        inv = nxt;
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
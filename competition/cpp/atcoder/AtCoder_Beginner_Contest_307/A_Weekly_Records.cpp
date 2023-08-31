#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    rep(i, 1, n) {
        LL sum = 0, t;
        rep(j, 1, 7) {
            cin >> t;
            sum += t;
        }
        cout << sum << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
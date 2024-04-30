#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)

void solve() {
    LL n, m;
    cin >> n >> m;
    LL rs = n;
    rep(b, 2, m) {
        if(b > n) break;
        LL l = 0, r = n;
        while(l < r) {
            LL mid = (l + r) >> 1;
            if(mid * b * b - b > n) r = mid;
            else l = mid + 1;
        }
        rs += l - 1;
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
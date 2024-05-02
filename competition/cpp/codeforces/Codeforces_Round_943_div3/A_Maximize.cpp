#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int maxVal = -1, maxNum = 1;
    int x;
    cin >> x;
    rep(i, 1, x - 1) {
        if(__gcd(i, x) + i > maxVal) {
            maxVal = __gcd(i, x) + i;
            maxNum = i;
        }
    }
    cout << maxNum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
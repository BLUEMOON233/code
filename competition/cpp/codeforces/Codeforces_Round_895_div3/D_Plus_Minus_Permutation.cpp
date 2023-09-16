#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = j; i <= int(k); i++)

void solve() {
    LL n, x, y;
    cin >> n >> x >> y;
    LL lcm = x * y / __gcd(x, y);
    int no = n / lcm;
    LL xx = n / x - no;
    LL yy = n / y - no;
    LL pos = (n + n - xx + 1) * xx / 2;
    LL neg = (1 + yy) * yy / 2;
    cout << pos - neg << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
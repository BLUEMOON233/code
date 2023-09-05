#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    int sz = n * (n - 1) / 2;
    if (y - x < sz) {
        cout << -1 << '\n';
        return;
    }
    vector<int> rs;
    rs.emplace_back(y);
    rep(i, 1, n - 1) rs.emplace_back(y - i), y -= i;
    reverse(rs.begin(), rs.end());
    rs[0] = x;
    for (auto t : rs) cout << t << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
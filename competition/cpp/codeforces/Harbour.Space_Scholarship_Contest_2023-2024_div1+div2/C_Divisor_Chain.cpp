#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

inline int lowbit(int x) {
    return x & -x;
}

void solve() {
    int x;
    cin >> x;
    vector<int> rs;
    rs.emplace_back(x);
    while (__builtin_popcount(x) != 1) {
        x -= lowbit(x);
        rs.emplace_back(x);
    }
    while (x != 1) {
        x >>= 1;
        rs.emplace_back(x);
    }
    cout << rs.size() << '\n';
    for (int t : rs) cout << t << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
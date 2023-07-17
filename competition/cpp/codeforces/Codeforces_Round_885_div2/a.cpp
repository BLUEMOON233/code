#include<bits/stdc++.h>
using namespace std;

inline void solve() {
    int n, m, k, x, y;
    int tx, ty;
    bool f = true;
    cin >> n >> m >> k >> x >> y;
    int flag = (x + y) % 2;
    while (k--) {
        cin >> tx >> ty;
        if ((tx + ty) % 2 == flag) f = false;
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<LL> p(n + 1), a(n + 1);
    rep(i, 1, n) cin >> p[i];
    rep(i, 1, n) cin >> a[i];
    LL now = pb;
    LL rsa = 0, sum = 0;
    vector<int> st(n + 1, 0);
    per(i, k, 1) {
        if(st[now]) break;
        st[now] = 1;
        rsa = max(rsa, a[now] * i + sum);
        sum += a[now];
        now = p[now];
    }
    now = ps, sum = 0;
    LL rsb = 0;
    rep(i, 1, n) st[i] = 0;
    per(i, k, 1) {
        if(st[now]) break;
        st[now] = 1;
        rsb = max(rsb, a[now] * i + sum);
        sum += a[now];
        now = p[now];
    }
    if(rsa > rsb) cout << "Bodya\n";
    else if(rsa < rsb) cout << "Sasha\n";
    else cout << "Draw\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
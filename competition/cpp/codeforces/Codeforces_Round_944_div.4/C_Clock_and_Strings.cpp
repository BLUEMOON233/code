#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c || a == d || b == c || b == d) {
        cout << "YES\n";
        return;
    }
    int cnt = 0;
    for(int i = a % 12 + 1; i != b; i = i % 12 + 1) {
        if(i == c) cnt++;
        if(i == d) cnt++;
    }
    if(cnt == 2 || cnt == 0) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
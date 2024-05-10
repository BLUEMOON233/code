#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    string s;
    cin >> s;
    bool flag = true;
    rep(i, 1, s.length() - 1) if (s[i] != s[0]) flag = false;
    if(flag) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << s.substr(1) << s[0] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
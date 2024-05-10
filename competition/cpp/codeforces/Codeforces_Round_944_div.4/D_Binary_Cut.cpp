#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s = '0' + s;
    int rs = 1;
    bool flag = true;
    rep(i, 2, n) {
        if(s[i] != s[i - 1]) rs++;
        if(flag && s[i] == '1' && s[i - 1] == '0') flag = false, rs--;
    }
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
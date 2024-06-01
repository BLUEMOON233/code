#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    string s;
    cin >> s;
    map<int, int> high;
    int n = s.length();
    LL now = 0, rs = 0;
    rep(i, 0, n - 1) {
        if (s[i] == '(') now++;
        else now--;
        rs += high[now];
        high[now]++;
        if(now) high[(now - 1) / 2] = 0;
    }
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) solve();
}
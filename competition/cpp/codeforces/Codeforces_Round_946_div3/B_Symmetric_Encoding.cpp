#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    string r = "";
    rep(c, 'a', 'z') {
        if (mp[c]) r += char(c);
    }
    string rr = r;
    reverse(rr.begin(), rr.end());
    map<char, char> mp2;
    rep(i, 0, r.length() - 1) {
        mp2[r[i]] = rr[i];
    }
    rep(i, 0, s.length() - 1) {
        s[i] = mp2[s[i]];
    }
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
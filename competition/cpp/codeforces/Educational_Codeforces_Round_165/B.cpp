#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)


void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pre(n + 1, 0);
    s = '@' + s;
    rep(i, 1, n) pre[i] += pre[i - 1] + (s[i] == '1');
    LL rs = 0;
    rep(i, 1, n) if(s[i] == '0' && pre[i] != 0) rs += pre[i] + 1;
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) solve();
}
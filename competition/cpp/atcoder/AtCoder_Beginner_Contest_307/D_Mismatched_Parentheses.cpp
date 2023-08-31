#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '@' + s;
    rep(i, 1, n) {
        if (s[i] == '(') {
            stack<char> stk;
            int pos = i + 1;
            stk.push(s[i]);
            while (stk.size() && pos <= n) {
                if (s[pos] != ')') stk.push(s[pos++]);
                else {
                    while (stk.top() != '(') stk.pop();
                    stk.pop();
                    pos++;
                }
            }
            string tl = "";
            while (stk.size()) tl += stk.top(), stk.pop();
            reverse(tl.begin(), tl.end());
            if (tl.size()) cout << tl << '\n';
            i = pos - 1;
        }
        else {
            cout << s[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
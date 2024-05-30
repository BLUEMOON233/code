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
    char bef = s[0];
    for (int i = 1; i <= n - 1; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            if ('a' <= bef && bef <= 'z') {
                cout << "NO\n";
                return;
            }
            if (s[i] < bef) {
                cout << "NO\n";
                return;
            }
            bef = s[i];
        } else if ('a' <= s[i] && s[i] <= 'z') {
            if ('0' <= bef && bef <= '9') {
                bef = s[i];
                continue;
            }
            if (s[i] < bef) {
                cout << "NO\n";
                return;
            }
            bef = s[i];
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) solve();
}
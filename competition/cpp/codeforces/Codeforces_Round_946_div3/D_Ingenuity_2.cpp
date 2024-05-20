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
    vector<int> op(5, 0);
    for (char c : s) {
        if (c == 'N') op[1]++;
        if (c == 'S') op[2]++;
        if (c == 'E') op[3]++;
        if (c == 'W') op[4]++;
    }
    if ((op[1] % 2 != op[2] % 2) || (op[3] % 2 != op[4] % 2)) {
        cout << "NO\n";
        return;
    }
    vector<int> cntR(5, 0);
    vector<int> cntH(5, 0);
    rep(i, 1, 4) {
        cntR[i] = cntH[i] = op[i] / 2;
    }
    vector<char> rs(s.length(), '#');
    bool f_R = true, f_H = true;
    rep(i, 0, s.length() - 1) {
        if (s[i] == 'N') {
            if (cntR[1]-- > 0) rs[i] = 'R', f_R = false;
            else if (cntH[1]-- > 0) rs[i] = 'H', f_H = false;
        } else if (s[i] == 'S') {
            if (cntR[2]-- > 0) rs[i] = 'R', f_R = false;
            else if (cntH[2]-- > 0) rs[i] = 'H', f_H = false;
        } else if (s[i] == 'E') {
            if (cntR[3]-- > 0) rs[i] = 'R', f_R = false;
            else if (cntH[3]-- > 0) rs[i] = 'H', f_H = false;
        } else {
            if (cntR[4]-- > 0) rs[i] = 'R', f_R = false;
            else if (cntH[4]-- > 0) rs[i] = 'H', f_H = false;
        }
    }

    bool f_1 = false, f_2 = false;
    // vector<int> flag(5, 0);
    f_1 = (op[1] % 2 == 1);
    f_2 = (op[3] % 2 == 1);

    if (f_R && !f_1 && !f_2) {
        cout << "NO\n";
        return;
    }

    if (f_H && !f_1 && !f_2) {
        cout << "NO\n";
        return;
    }

    if (f_R && f_H && ((!f_1) || (!f_2))) {
        cout << "NO\n";
        return;
    }

    if (f_1) {
        if (f_R) {
            rep(i, 0, s.length() - 1) {
                if (s[i] == 'E' || s[i] == 'W') continue;
                if (rs[i] == '#' && f_1) {
                    rs[i] = 'R';
                    f_1 = false;
                } else if (rs[i] == '#') {
                    rs[i] = 'R';
                    break;
                }
            }
            f_R = false;
        } else {
            rep(i, 0, s.length() - 1) {
                if (s[i] == 'E' || s[i] == 'W') continue;
                if (rs[i] == '#' && f_1) {
                    rs[i] = 'H';
                    f_1 = false;
                } else if (rs[i] == '#') {
                    rs[i] = 'H';
                    break;
                }
            }
        }
    }

    if (f_2) {
        if (f_R) {
            rep(i, 0, s.length() - 1) {
                if (s[i] == 'S' || s[i] == 'N') continue;
                if (rs[i] == '#' && f_2) {
                    rs[i] = 'R';
                    f_2 = false;
                } else if (rs[i] == '#') {
                    rs[i] = 'R';
                    break;
                }
            }
        } else {
            rep(i, 0, s.length() - 1) {
                if (s[i] == 'S' || s[i] == 'N') continue;
                if (rs[i] == '#' && f_2) {
                    rs[i] = 'H';
                    f_2 = false;
                } else if (rs[i] == '#') {
                    rs[i] = 'H';
                    break;
                }
            }
        }
    }

    for (char c : rs) cout << c;
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
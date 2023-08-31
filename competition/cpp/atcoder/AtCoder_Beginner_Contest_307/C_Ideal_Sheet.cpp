#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int ha, wa;
    cin >> ha >> wa;
    vector<vector<char> > A(ha + 1, vector<char>(wa + 1, '.'));
    rep(i, 1, ha) rep(j, 1, wa) cin >> A[i][j];
    int hb, wb;
    cin >> hb >> wb;
    vector<vector<char> > B(hb + 1, vector<char>(wb + 1, '.'));
    rep(i, 1, hb) rep(j, 1, wb) cin >> B[i][j];
    int hx, wx;
    cin >> hx >> wx;
    vector<vector<char> > X(hx + 1, vector<char>(wx + 1, '.'));
    rep(i, 1, hx) rep(j, 1, wx) cin >> X[i][j];

    int cnt1 = 0;
    rep(i, 1, hx) rep(j, 1, wx) if (X[i][j] == '#') cnt1++;

    rep(bi, 1, 41) rep(bj, 1, 41) {
        vector<vector<char> > g(61, vector<char>(61, '.'));
        rep(i, 21, 20 + ha) rep(j, 21, 20 + wa)
            if (A[i - 20][j - 20] == '#') g[i][j] = '#';
        rep(i, 1, hb) rep(j, 1, wb)
            if (B[i][j] == '#') g[bi + i - 1][bj + j - 1] = '#';
        int cnt2 = 0;
        rep(i, 1, 60) rep(j, 1, 60) if (g[i][j] == '#') cnt2++;
        if (cnt1 != cnt2) continue;
        rep(i, 1, 60 - hx + 1) rep(j, 1, 60 - wx + 1) {
            bool f = true;
            rep(xi, 1, hx) rep(xj, 1, wx) if (g[i + xi - 1][j + xj - 1] != X[xi][xj]) {
                f = false;
            }
            if (f) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
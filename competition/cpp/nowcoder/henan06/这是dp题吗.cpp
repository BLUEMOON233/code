#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define mes(tmp, data) memset(tmp, data, sizeof tmp)
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << " = " << x << endl;
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout<<tmp[i]<<" \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout<<tmp[i]<<" \n"[i == Size]
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"

const int N = 307;

inline void solve() {
    int n, k, kk;
    cin >> n >> kk;
    k = n - 1;
    vector<vector<LL> > a(n + 1, vector<LL>(n * 2, -1e18));
    vector<vector<LL> > dp(2 * n, vector<LL>(2 * k + 1, -1e18));
    rep(i, 1, n) rep(j, 1, i * 2 - 1) cin >> a[i][j];
    LL rs = -1e18;
    dp[1][k] = a[1][1];
    rep(t, 2, n) {
        vector<vector<LL> > g(2 * n, vector<LL>(2 * k + 1, -1e18));
        rep(i, 1, 2 * t - 1) {
            rep(j, 0, 2 * k) {
                if (i >= 3 && j >= 1) g[i][j] = max(g[i][j], a[t][i] + dp[i - 2][j - 1]);
                if (2 <= i && i <= 2 * t - 2) g[i][j] = max(g[i][j], a[t][i] + dp[i - 1][j]);
                if (i <= 2 * t - 3 && j <= 2 * k - 1) g[i][j] = max(g[i][j], a[t][i] + dp[i][j + 1]);
                // cout << i << ' ' << j << ' '<< g[i][j] << '\n';
                if (t == n && abs(j - n + 1) <= kk) rs = max(rs, g[i][j]);
            }
        }
        dp = g;
    }
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

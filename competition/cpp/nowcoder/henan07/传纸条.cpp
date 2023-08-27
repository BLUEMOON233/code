#include <bits/stdc++.h>
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

const int N = 51;
int dp[N][N][N][N];
int g[N][N];

inline void solve() {
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    rep(i, 1, n) rep(j, 1, m) rep(k, 1, n) rep(l, j + 1, m) {
        dp[i][j][k][l] = max({ dp[i][j - 1][k - 1][l], dp[i - 1][j][k][l - 1], dp[i][j - 1][k][l - 1], dp[i - 1][j][k - 1][l] }) + g[i][j] + g[k][l];
    }
    cout << dp[n][m - 1][n - 1][m] << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

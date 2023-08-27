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

const int N = 57;
bool dp[N][N][65];
vector<vector<LL>> dist;
LL n, m;

LL floyd() {
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) dist[i][k] = min(dist[i][k], dist[i][j] + dist[j][k]);
    return dist[1][n];
}

inline void solve() {
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, n) rep(e, 0, 64) dp[i][j][e] = false;
    dist.resize(n + 1, vector<LL>(n + 1, LLONG_MAX / 2));
    rep(i, 1, m) {
        int a, b;
        cin >> a >> b;
        dp[a][b][0] = true;
        dist[a][b] = 1;
    }
    rep(e, 1, 64) rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
        if (dp[i][j][e - 1] && dp[j][k][e - 1]) {
            dp[i][k][e] = true;
            dist[i][k] = 1;
        }
    }
    rep(i, 1, n) dist[i][i] = 0;
    cout << floyd() << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

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

const int N = 1;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

struct Node {
    int x, y;
    int d;
};


inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n + 2, vector<char>(m + 2, '#'));
    rep(i, 1, n) rep(j, 1, m) cin >> g[i][j];
    PII s, e;
    rep(i, 1, n) rep(j, 1, m) if (g[i][j] == 'S') {
        s = { i, j };
        g[i][j] = '.';
        break;
    }
    rep(i, 1, n) rep(j, 1, m) if (g[i][j] == 'G') {
        e = { i, j };
        g[i][j] = '.';
        break;
    }
    rep(i, 1, n) rep(j, 1, m) if (g[i][j] == '^') {
        int p = i - 1;
        while (g[p][j] == '.' || g[p][j] == '!') g[p][j] = '!', p--;
    }
    rep(i, 1, n) rep(j, 1, m) if (g[i][j] == 'v') {
        int p = i + 1;
        while (g[p][j] == '.' || g[p][j] == '!') g[p][j] = '!', p++;
    }
    rep(i, 1, n) rep(j, 1, m) if (g[i][j] == '<') {
        int p = j - 1;
        while (g[i][p] == '.' || g[i][p] == '!') g[i][p] = '!', p--;
    }
    rep(i, 1, n) rep(j, 1, m) if (g[i][j] == '>') {
        int p = j + 1;
        while (g[i][p] == '.' || g[i][p] == '!') g[i][p] = '!', p++;
    }
    // rep(i, 1, n) rep(j, 1, m) cout << g[i][j] << " \n"[j == m];
    vector<vector<int> > rs(n + 1, vector<int>(m + 1, 0));
    queue<Node> q;
    q.push({ s.first, s.second, 0 });
    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();
        if (g[x][y] != '.' || rs[x][y]) continue;
        rs[x][y] = d;
        rep(i, 0, 3) {
            q.push({ x + dx[i], y + dy[i], d + 1 });
        }
    }
    if(rs[e.first][e.second] == 0) cout << -1 << '\n';
    else cout << rs[e.first][e.second] << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

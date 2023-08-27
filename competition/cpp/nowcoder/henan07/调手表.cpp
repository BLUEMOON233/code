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

inline void solve() {
    LL n, k;
    cin >> n >> k;
    vector<int> rs(n, -1);
    queue<PII> q;
    q.push({ 0, 0 });
    rs[0] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (rs[(x + 1) % n] == -1) rs[(x + 1) % n] = y + 1, q.push({ (x + 1) % n, y + 1 });
        if (rs[(x + k) % n] == -1) rs[(x + k) % n] = y + 1, q.push({ (x + k) % n, y + 1 });
    }
    LL ans = -1;
    rep(i, 0, n - 1) ans = max(ans, (LL)rs[i]);
    cout << ans << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

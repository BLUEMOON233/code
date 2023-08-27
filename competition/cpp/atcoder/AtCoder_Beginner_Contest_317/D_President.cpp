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
    int n;
    cin >> n;
    vector<PII> s(n + 1);
    LL sum = 0;
    rep(i, 1, n) {
        LL a, b, c;
        cin >> a >> b >> c;
        LL cost = (a + b + 1) / 2 - a;
        cost = max(cost, 0LL);
        s[i] = { cost, c };
        sum += c;
    }
    vector<LL> dp(sum + 1, 1e18 + 7);
    dp[0] = 0;
    rep(i, 1, n) per(j, sum, s[i].second) {
        dp[j] = min(dp[j], dp[j - s[i].second] + s[i].first);
    }
    LL rs = 1e18 + 7;
    rep(i, sum / 2 + 1, sum) rs = min(rs, dp[i]);
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

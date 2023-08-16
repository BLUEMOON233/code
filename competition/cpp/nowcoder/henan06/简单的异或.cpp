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

const int N = 1;

inline void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<vector<int> > pre(n + 1, vector<int>(32, 0));
    rep(i, 1, n) rep(j, 0, 30) pre[i][j] = pre[i - 1][j] + ((a[i] >> j) & 1);
    int q;
    cin >> q;
    while (q--) {
        LL res = 0;
        int l, r;
        cin >> l >> r;
        vector<LL> rs(32, 0);
        rep(i, 0, 30) rs[i] = pre[r][i] - pre[l - 1][i];
        rep(i, 0, 30) if (rs[i] < (r - l + 1 - rs[i])) res += (1LL << i);
        cout << res << '\n';
    }
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

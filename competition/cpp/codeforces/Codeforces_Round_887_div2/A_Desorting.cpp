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
    vector<int> a(n + 1, 0), d(n + 1, 0);
    rep(i, 1, n) cin >> a[i];
    rep(i, 2, n) d[i] = a[i] - a[i - 1];
    LL rs = 1e18;
    // debug1(d, n);
    rep(i, 2, n) if (d[i] < 0) {
        rs = min(rs, 0LL);
    }
    else {
        rs = min(rs, LL(d[i]) / 2 + 1);
    }
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //  T = read();
    cin >> T;
    while (T--) solve();
}

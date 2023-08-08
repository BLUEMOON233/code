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
    vector<LL> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) a[i] -= b[i];
    vector<pair<LL, int> > rs(n + 1);
    rep(i, 1, n) rs[i] = pair<LL, int>{ a[i], i };
    sort(rs.begin() + 1, rs.end());
    vector<int> pos;
    per(i, n, 1) if(rs[i].first== rs[n].first) pos.push_back(rs[i].second);
    cout << pos.size() << '\n';
    sort(pos.begin(), pos.end());
    for(auto p : pos) cout << p << ' ';
    cout << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

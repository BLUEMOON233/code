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
    vector<LL> xx(n + 1);
    rep(i, 1, n) cin >> xx[i];
    vector<LL> x(xx);
    sort(x.begin() + 1, x.end());
    // vector<LL> pre(n + 1);
    // rep(i, 1, n) pre[i] = pre[i - 1] + x[i];
    LL now = 0;
    rep(i, 1, n) now += x[i] - x[1] + 1;
    map<LL, LL> mp;
    mp[x[1]] = now;
    rep(i, 2, n) {
        now -= (x[i] - x[i - 1]) * (n - i);
        now += (x[i] - x[i - 1]) * (i - 2);
        mp[x[i]] = now;
    }
    rep(i, 1, n) cout << mp[xx[i]] << " \n"[i == n];
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

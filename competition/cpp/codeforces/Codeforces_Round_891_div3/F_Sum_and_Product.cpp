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
    int n, q;
    cin >> n;
    vector<LL> a(n + 1);
    map<int, LL> mp;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) mp[a[i]]++;
    cin >> q;
    while (q--) {
        LL x, y;
        cin >> x >> y;
        LL delta = x * x - 4LL * y;
        if (delta < 0) {
            cout << 0 << ' ';
            continue;
        }
        if (sqrt(delta) != int(sqrt(delta))) {
            cout << 0 << ' ';
            continue;
        }
        delta = sqrt(delta);
        LL x1 = (x + delta) / 2, x2 = (x - delta) / 2;
        if (x1 + x2 != x || x1 * x2 != y) {
            cout << 0 << ' ';
            continue;
        }
        if (x1 == x2) {
            cout << mp[x1] * (mp[x1] - 1) / 2 << ' ';
        }
        else {
            cout << mp[x1] * mp[x2] << ' ';
        }
    }
    cout << endl;
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

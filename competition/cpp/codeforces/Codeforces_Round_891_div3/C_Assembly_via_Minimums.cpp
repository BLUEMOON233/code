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
    int sz = n * (n - 1) / 2;
    vector<int> a(sz + 1);
    rep(i, 1, sz) cin >> a[i];
    // cout << sz << '\n';
    sort(a.begin() + 1, a.end());
    int now = n;
    vector<int> rs;
    for (int i = 1, cnt = 1; cnt <= n - 1; i += now, cnt++) {
        now--;
        rs.emplace_back(a[i]);
    }
    for (auto x : rs) cout << x << ' ';
    cout << (int)1e9 << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

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
LL n, k;

bool check(LL x, vector<LL> &a) {
    LL r = n;
    rep(i, 1, k) {
        while (r > 0 && a[r] > x) r--;
        x -= r;
    }
    return x >= 1;
}

inline void solve() {
    cin >> n >> k;
    vector<LL> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    if (a[1] > 1) {
        cout << 1 << '\n';
        return;
    }
    LL l = 1, r = 1e18;
    while (l < r) {
        LL mid = (l + r) >> 1;
        if (check(mid, a)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    fast();
    int T = 1;
    //  T = read();
    cin >> T;
    while (T--) solve();
}

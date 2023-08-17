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

const int N = 1, mod = 1e9 + 7;

LL quickPow(LL a, LL b, LL mod) {
    LL rs = 1;
    while (b) {
        if (b & 1) rs = rs * a % mod;
        b >>= 1, a = a * a % mod;
    }
    return rs % mod;
}

LL mult(LL x) {
    LL rs = 1;
    rep(i, 1, x) rs = (rs * i) % mod;
    return rs;
}

LL mult2(LL n, LL k) {
    LL rs = 1;
    rep(i, 2, n) {
        if ((i - 1) <= k) rs = (rs * (i - 1)) % mod;
        else rs = (rs * k) % mod;
    }
    return rs;
}

inline void solve() {
    LL n, k;
    cin >> n >> k;
    cout << mult(n) * mult2(n, k) % mod << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

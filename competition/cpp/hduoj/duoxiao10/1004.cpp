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

const int N = 1, mod = 998244353;

LL quickPow(LL a, LL b, LL mod) {
    LL rs = 1;
    while (b) {
        if (b & 1) rs = rs * a % mod;
        b >>= 1, a = a * a % mod;
    }
    return rs % mod;
}

inline void solve() {
    LL n;
    cin >> n;
    LL d = quickPow(3, mod - 2, mod);
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    cout << (n * 2 - 1) * d % mod << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

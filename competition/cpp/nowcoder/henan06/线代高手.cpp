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
    int n, m, x;
    cin >> n >> m;
    vector<LL> A(n + 1), B(m + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, m) cin >> B[i];
    rep(i, 1, n) A[i] = A[i - 1] + A[i];
    rep(i, 1, m) B[i] = B[i - 1] + B[i];
    cin >> x;
    LL rs = 0;
    rep(i, 1, n) rep(j, i, n) rep(l, 1, m) rep(r, l, m) {
        if ((A[j] - A[i - 1]) * (B[r] - B[l - 1]) <= x) rs = max(rs, (LL)(j - i + 1) * (r - l + 1));
    }
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

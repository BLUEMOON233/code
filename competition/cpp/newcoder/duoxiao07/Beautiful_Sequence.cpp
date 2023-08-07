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

const int N = 1;

inline void solve() {
    LL n, k;
    cin >> n >> k;
    vector<LL> b(n + 1), pre(n + 1);
    rep(i, 1, n - 1) cin >> b[i];
    if (n == 1) {
        cout << k - 1 << '\n';
        return;
    }
    vector<int> st(30, 3);
    rep(i, 1, n - 1) pre[i + 1] = pre[i] ^ b[i];
    rep(i, 1, n - 1) if (b[i] != 0) {
        int pos = -1;
        per(j, 29, 0) if ((b[i] >> j) & 1) {
            pos = j;
            break;
        }
        int flag = (pre[i] >> pos) & 1;
        if (st[pos] == 3) st[pos] = flag;
        else if (st[pos] != flag) {
            cout << -1 << '\n';
            return;
        }
    }
    // debug0(st, 29);
    vector<int> c(30, 0);
    LL cnt = 0;
    rep(i, 0, 29) if (st[i] == 3) c[cnt++] = i;
    if (k > (1 << cnt)) {
        cout << -1 << '\n';
        return;
    }
    k--;
    LL rs = 0;
    rep(i, 0, cnt - 1) if (k & (1 << i)) rs |= (1 << c[i]);
    rep(i, 0, 29) if (st[i] == 1) rs |= (1 << i);
    rep(i, 1, n) cout << (pre[i] ^ rs) << " \n"[i == n];
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

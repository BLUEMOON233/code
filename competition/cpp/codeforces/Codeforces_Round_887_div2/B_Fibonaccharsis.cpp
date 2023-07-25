#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(LL i=LL(j);i<=LL(k);i++)
#define per(i,j,k) for(LL i=LL(j);i>=LL(k);i--)
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
    LL n, k, rs = 0;
    cin >> n >> k;
    if (k > 57) {
        cout << 0 << '\n';
        return;
    }
    rep(i, 0, n) {
        LL lst = n, now = i, cnt = 1;
        while (lst - now >= 0) {
            int tmp = now;
            now = lst - now;
            lst = tmp;
            cnt++;
            if (cnt == k && now >= 0) {
                rs++;
                break;
            }
        }
    }
    cout << rs << endl;
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

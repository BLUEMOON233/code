#include <bits/stdc++.h>
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
    set<int> st;
    int n, t;
    cin >> n;
    rep(i, 1, n) {
        cin >> t;
        st.insert(t);
    }
    int lst = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (lst != 0 && lst + 1 != *it) {
            cout << lst + 1 << '\n';
            return;
        }
        else {
            lst = *it;
        }
    }
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

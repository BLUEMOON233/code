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
    int m, n;
    cin >> m >> n;
    if (n == 0) {
        if (m % 3 == 0) cout << "Bob\n";
        else cout << "Alice\n";
    }                                                       
    if (n && m % 3 == 0) {
        cout << "Alice\n";
    }
    else if (n == 1) {
        if (m % 3 == 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
    else if (n > 1) {
        if (m % 3 == 2 && n == 2) cout << "Bob\n";
        else cout << "Alice\n";
    }
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

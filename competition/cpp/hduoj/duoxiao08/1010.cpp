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

bool divide(int n) {
    rep(i, 2, n / i) if (!(n % i)) {
        int s = 0;
        while (!(n % i)) n /= i, s++;
        // cout << i << ' ' << s << '\n';
        if (i % 4 == 3 && s % 2 == 1) return false;
    } //i -> prime | s -> count of this prime
    if (n > 1) {
        if (n % 4 == 3) return false;
    }
    return true;
}

inline void solve() {
    LL a, b;
    cin >> a >> b;
    LL dis = abs(a - b);
    LL t = sqrt(dis);
    if (t * t == dis) {
        cout << 1 << '\n';
    }
    else if (dis % 2 == 1) {
        cout << 2 << '\n';
    }
    else if (dis % 4 == 0) {
        cout << 2 << '\n';
    }
    else {
        if (divide(dis)) {
            cout << 2 << '\n';
        }
        else {
            cout << 3 << '\n';
        }
    }
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

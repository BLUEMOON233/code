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
template<class T>
inline T read() {
    T x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
template<class T>
inline void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
#define read() read<int>()
#define write(tmp) write<int>(tmp);
//#define read() read<LL>()
//#define write(tmp) write<LL>(tmp);
//#define read() read<__int128>()
//#define write(tmp) write<__int128>(tmp);

const int N = 1;

inline void solve() {
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n) {
        if (a[i] == 0 && b[i] == 0) {
            f[i] = -1;
            continue;
        }
        while (a[i] != 0) {
            // cout << i << ": " << a[i] << ' ' << b[i] << '\n';
            // if (a[i] >= b[i]) {
            //     f[i] = (f[i] + 1) % 3;
            //     int t = b[i];
            //     b[i] = abs(a[i] - b[i]);
            //     a[i] = t;
            // }
            // else {
            //     b[i] %= (2LL * a[i]);
            //     f[i] = (f[i] + 1) % 3;
            //     int t = b[i];
            //     b[i] = abs(a[i] - b[i]);
            //     a[i] = t;
            // }
            b[i] %= (2LL * a[i]);
            f[i] = (f[i] + 1) % 3;
            int t = b[i];
            b[i] = abs(a[i] - b[i]);
            a[i] = t;
        }
    }
    // debug1(f, n);
    int flag = -1;
    rep(i, 1, n) if (f[i] != -1) {
        flag = f[i];
        break;
    }
    if (flag == -1) {
        YES;
        return;
    }
    // cout << flag << '\n';
    rep(i, 1, n) if (f[i] != flag && f[i] != -1) {
        NO;
        return;
    }
    YES;
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

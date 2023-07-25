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
    int n, x;
    cin >> n >> x;
    vector<vector<char>> g(n + 1, vector<char>(n + 1));
    rep(i, 1, n) rep(j, 1, n) cin >> g[i][j];
    int y = 100;
    int t = gcd(x, y);
    x /= t, y /= t;
    // cout << x << ' ' << y << '\n';
    // cout << endl;
    if (n % y != 0) {
        cout << "error\n";
        return;
    }
    vector<vector<char>> gg(n / y + 1, vector<char>(n / y + 1));
    for (int i = 1; i <= n; i += y) {
        for (int j = 1; j <= n; j += y) {
            // cout <<  i << ' ' << j << '\n';
            rep(ii, i, i + y - 1) rep(jj, j, j + y - 1) {
                // cout << ii << ' ' << jj << '\n';
                if (g[ii][jj] != g[i][j]) {
                    cout << "error" << '\n';
                    return;
                }
            }
            // cout << (i - 1) / y + 1 << ' ' << (j - 1) / y + 1 << '\n';
            gg[(i - 1) / y + 1][(j - 1) / y + 1] = g[i][j];
        }
    }
    rep(i, 1, n / y) {
        rep(tt, 1, x) {
            rep(j, 1, n / y) rep(t, 1, x) cout << gg[i][j];
            cout << '\n';
        }
    }
    // cout << endl;
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}
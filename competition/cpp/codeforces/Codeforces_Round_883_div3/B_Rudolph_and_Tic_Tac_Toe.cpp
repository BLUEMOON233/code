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
    bool flag = false;
    vector<vector<char> > g(3, vector<char>(3, '.'));
    rep(i, 0, 2) rep(j, 0, 2) cin >> g[i][j];
    int i, j;
    i = 1, j = 1;
    if (g[i][j] != '.') {
        char s = g[i][j];
        if (g[(i + 1) % 3][j] == s && g[(i + 2) % 3][j] == s) flag = true;
        if (g[i][(j + 1) % 3] == s && g[i][(j + 2) % 3] == s) flag = true;
        if (g[(i + 1) % 3][(j + 1) % 3] == s && g[(i + 2) % 3][(j + 2) % 3] == s) flag = true;
        if (g[(i + 1) % 3][(j + 2) % 3] == s && g[(i + 2) % 3][(j + 1) % 3] == s) flag = true;
        if (flag) {
            cout << s << '\n';
            return;
        }
    }
    i = 0, j = 0;
    if (g[i][j] != '.') {
        char s = g[i][j];
        if (g[(i + 1) % 3][j] == s && g[(i + 2) % 3][j] == s) flag = true;
        if (g[i][(j + 1) % 3] == s && g[i][(j + 2) % 3] == s) flag = true;
        if (flag) {
            cout << s << '\n';
            return;
        }
    }
    i = 2, j = 2;
    if (g[i][j] != '.') {
        char s = g[i][j];
        if (g[(i + 1) % 3][j] == s && g[(i + 2) % 3][j] == s) flag = true;
        if (g[i][(j + 1) % 3] == s && g[i][(j + 2) % 3] == s) flag = true;
        if (flag) {
            cout << s << '\n';
            return;
        }
    }
    if (!flag) cout << "DRAW" << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

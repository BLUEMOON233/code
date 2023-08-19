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

const int N = 1e3 + 7, M = 1e6 + 7;
int h[N], e[M], ne[M], idx = 0;
inline void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

struct color {
    int r, g, b;
    int depth;
};

vector<color> c;

bool f = false;

void dfs(int now, int dep) {
    if (dep > 255) f = true;
    if (f) return;
    c[now].depth = max(c[now].depth, dep);
    for (int i = h[now]; i; i = ne[i]) {
        int j = e[i];
        if (c[j].depth > c[now].depth) continue;
        dfs(j, dep + 1);
    }
}

inline void solve() {
    int n;
    cin >> n;
    c.resize(n + 1);
    rep(i, 1, n) cin >> c[i].r >> c[i].g >> c[i].b;
    rep(i, 1, n) c[i].depth = -1;
    vector<bool> st(n + 1);
    rep(i, 1, n) rep(j, 1, n) if (i != j) {
        if (c[i].r < c[j].r && c[i].g < c[j].g && c[i].b < c[j].b) {
            add(i, j);
            st[j] = true;
        }
    }
    rep(i, 1, n) if (!st[i]) dfs(i, 0);
    if (f) {
        cout << -1 << '\n';
        return;
    }
    if (c[1].depth != c[2].depth) {
        dfs(1, max(c[1].depth, c[2].depth));
        dfs(2, max(c[1].depth, c[2].depth));
    }
    if (c[1].depth != c[2].depth || f) {
        cout << -1 << '\n';
        return;
    }
    rep(i, 1, n) cout << c[i].depth << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

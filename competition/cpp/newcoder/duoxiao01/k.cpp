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

const int N = 1e5 + 7;
int e[N << 1], ne[N << 1], h[N], idx = 0;
inline void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx++;
}

inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> st(n + 1, false);
    queue<int> q;
    rep(i, 1, m) {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    q.push(1);
    LL rs = 0;
    while (!q.empty()) {
        int now = q.front();
        for (int i = h[now]; i; i++) {
            int j = e[i];
            st[j] = true;
        }
    }
}

int main() {
    // fast();
    int T = 1;
    //  T = read();
    // cin >> T;
    while (T--) solve();
}

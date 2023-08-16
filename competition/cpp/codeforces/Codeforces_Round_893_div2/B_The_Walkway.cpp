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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m + 2);
    rep(i, 1, m) cin >> a[i];
    a[0] = 1, a[m + 1] = n + 1;
    int tot = 1;
    for (int i = 1;i <= m + 1;i++) {
        tot += (a[i] - a[i - 1] - 1) / d;
        if (a[i] != 1 && a[i] != n + 1) tot++;
    }
    int rs = INT_MAX, num = 0;
    rep(i, 1, m) {
        int now = tot;
        now -= (a[i] - a[i - 1] - 1) / d + (a[i + 1] - a[i] - 1) / d;
        if (a[i] != 1) now -= 1;
        now += (a[i + 1] - a[i - 1] - 1) / d;
        if (rs > now) rs = now, num = 1;
        else if (rs == now) num++;
    }
    cout << rs << " " << num << "\n";
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

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

const int N = 1, mod = 1e9 + 7;

inline void solve() {
    int n;
    cin >> n;
    vector<LL> x(n + 1, 0);
    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1));
    unordered_map<int, int> mp;
    rep(i, 1, n) cin >> x[i];
    sort(x.begin() + 1, x.end());
    int cnt = 0;
    rep(i, 1, n) cnt += (x[i] != x[i - 1]), mp[cnt] = i;
    rep(i, 1, cnt) dp[i][0] = 1;
    rep(i, 1, cnt) rep(j, 1, mp[i]) dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
    rep(i, 1, n) cout << dp[cnt][i] << '\n';
}

int main() {
    fast();
    int T = 1;
    //  T = read();
    cin >> T;
    while (T--) solve();
}

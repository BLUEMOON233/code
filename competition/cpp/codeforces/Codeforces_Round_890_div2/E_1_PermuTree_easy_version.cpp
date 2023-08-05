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

const int N = 5e3 + 7;
int h[N], e[N], ne[N], idx = 0;
LL sz[N];
inline void add(int a, int b) {
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}
LL rs = 0;

LL dfs(int now) {
    sz[now] = 1;
    for (int i = h[now]; i; i = ne[i]) {
        int j = e[i];
        sz[now] += dfs(j);
    }
    return sz[now];
}

int solution(vector<LL>& data) {
    LL sum = 0;
    for (auto x : data) {
        sum += x;
    }
    vector<vector<LL>> dp;
    for (int i = 0; i <= data.size(); i++) {
        vector<LL> tmp;
        for (int j = 0; j <= sum / 2; j++) tmp.push_back(0);
        dp.push_back(tmp);
    }

    for (int i = 1; i <= data.size(); i++) {
        for (int j = 1; j <= sum / 2; j++)
            if (j >= data[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - data[i - 1]] + data[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
    }
    return (sum - dp[data.size()][sum / 2]) * dp[data.size()][sum / 2];
}

void getrs(int now) {
    vector<LL> son;
    for (int i = h[now]; i; i = ne[i]) {
        int j = e[i];
        son.emplace_back(sz[j]);
    }
    sort(son.begin(), son.end());
    rs += solution(son);
}

inline void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    rep(i, 2, n) cin >> p[i];
    rep(i, 2, n) add(p[i], i);
    dfs(1);
    rep(i, 1, n) getrs(i);
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

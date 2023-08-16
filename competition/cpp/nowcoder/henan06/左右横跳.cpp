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

const int N = 1e3 + 7, M = 2e3 + 7;

int dist[N], h[N], e[M], ne[M], w[M], idx = 0;
int n, m, k;
vector<int> a;
bool st[N];
inline void add(int a, int b, int c) {
    w[++idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx;
}
void spfa(int s, int n) {
    queue<int>q;
    mes(dist, 0x3f), dist[s] = -a[s], st[s] = true, q.push(s);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) q.push(j), st[j] = true;
            }
        }
    }
    cout << -dist[n] << '\n';
}

inline void solve() {
    cin >> n >> m >> k;
    a.resize(n + 1, -1);
    rep(i, 1, n) {
        vector<int> t(m + 1);
        rep(j, 1, m) cin >> t[j];
        rep(j, 1, m) a[i] = max(a[i], t[j]);
    }
    rep(i, 1, n - 1) {
        add(i, i + 1, 0);
        if (i + k <= n) add(i, i + k, -a[i + k]);
    }
    spfa(1, n);
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

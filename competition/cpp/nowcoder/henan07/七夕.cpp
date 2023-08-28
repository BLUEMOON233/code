#include <bits/stdc++.h>
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

const int N = 1e4 + 7;

struct Edge {
    int a, b, w;
    bool operator<(const Edge& W) const {
        return w < W.w;
    }
};
vector<Edge> edges;
int p[N];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}
int kruskal(int n, int m) {
    int rs = 0, cnt = 0;
    sort(edges.begin() + 1, edges.begin() + 1 + m);
    rep(i, 1, n) p[i] = i;
    rep(i, 1, m) {
        int a = find(edges[i].a), b = find(edges[i].b), w = edges[i].w;
        if (a != b) p[a] = b, rs += w, cnt++;
    }
    if (cnt < n - 1) return 0x3f3f3f3f;
    else return rs;
}

inline void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    edges.resize(k + m + 1);
    rep(i, 1, k) {
        int u, v;
        cin >> u >> v;
        edges[i].a = u, edges[i].b = v, edges[i].w = 0;
    }
    rep(i, k + 1, k + m) {
        int u, v;
        cin >> u >> v;
        edges[i].a = u, edges[i].b = v, edges[i].w = 1;
    }
    cout << kruskal(n, k + m) << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

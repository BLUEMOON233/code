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
const int N = 1;

struct DSU {
    vector<int> p, Size;
    DSU(int n) : p(n + 1), Size(n + 1, 1) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        Size[x] += Size[y], p[y] = x;
        return true;
    }
    int size(int x) { return Size[find(x)]; }
};

inline void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }
    int k;
    cin >> k;
    vector<int> x(k + 1);
    rep(i, 1, k) cin >> x[i];
    rep(i, 2, k) {
        if (!dsu.same(x[1], x[i])) {
            NO;
            return;
        }
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

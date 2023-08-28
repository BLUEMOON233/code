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

const int N = 1e6 + 7;
int w[N], n, m;
struct Node {
    int l, r;
    LL sum, add;
} tr[N << 2];

void pushup(int u) {
    tr[u].sum = min(tr[u << 1].sum, tr[u << 1 | 1].sum);
}

void pushdown(int u) {
    Node& rt = tr[u], & lp = tr[u << 1], & rp = tr[u << 1 | 1];
    if (rt.add) {
        // lp.add += rt.add, lp.sum += (LL)(lp.r - lp.l + 1) * rt.add;
        // rp.add += rt.add, rp.sum += (LL)(rp.r - rp.l + 1) * rt.add;
        lp.add += rt.add, lp.sum -= rt.add;
        rp.add += rt.add, rp.sum -= rt.add;
        rt.add = 0;
    }
}
void build(int u, int l, int r) {
    if (l == r) tr[u] = { l, r, w[l], 0 };
    else {
        tr[u] = { l, r };
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int l, int r, LL v) {
    if (l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum -= v;
        tr[u].add += v;
    }
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}
LL query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL rs = 1e18 + 7;
    if (l <= mid) rs = query(u << 1, l, r);
    if (r > mid) rs = min(rs, query(u << 1 | 1, l, r));
    return rs;
}

inline void solve() {
    cin >> n >> m;
    rep(i, 1, n) cin >> w[i];
    build(1, 1, n);
    rep(i, 1, m) {
        LL d, l, r;
        cin >> d >> l >> r;
        modify(1, l, r, d);
        // rep(i, 1, n) cout << query(1, i, i) << ' ';
        // cout << '\n';
        // cout << query(1, l, r) << '\n';
        if (query(1, l, r) < 0) {
            cout << -1 << '\n';
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

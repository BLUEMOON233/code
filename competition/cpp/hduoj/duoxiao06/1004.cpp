#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <stack>
#include <iomanip>
#include <numeric>

#define x first
#define y second
#define endl '\n'
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<char, int> PCI;

const int N = 1e6 + 10;

vector<int> adj[N];
int n, sz[N], mxsz[N];
bool vis[N];
string s;

long long solve(int u, int tree_sz) // u is the root of the tree, tree_sz is the size of the tree
{
    int rt = u;
    auto get_rt = [&](auto self, int u, int fa) -> void
    {
        sz[u] = 1, mxsz[u] = 0;
        for (auto v : adj[u])
        {
            if (vis[v] || v == fa)
                continue;

            self(self, v, u);
            sz[u] += sz[v];     // iterate mp children & get size
            mxsz[u] = max(mxsz[u], sz[v]);  // get max size
        }
        mxsz[u] = max(mxsz[u], tree_sz - sz[u]);    // get max size of the other subtree
        if (mxsz[u] <= tree_sz / 2)     // change root if possible
        {
            rt = u;
        }
    };
    get_rt(get_rt, u, 0);   // get centroid

    long long res = 0;
    vis[u = rt] = true;

    map<array<int, 3>, int> mp;
    int cnt_a = -1, cnt_b = -1, cnt_c = -1;
    if (s[u] == 'a')
        cnt_a += 3;
    if (s[u] == 'b')
        cnt_b += 3;
    if (s[u] == 'c')
        cnt_c += 3;

    for (auto v : adj[u])
    {
        if (vis[v])
            continue;

        map<array<int, 3>, int> sub;
        auto get_info =
            [&](auto self, int u, int fa, int a, int b, int c) -> void
        {
            a--, b--, c--;
            if (s[u] == 'a')
                a += 3;
            if (s[u] == 'b')
                b += 3;
            if (s[u] == 'c')
                c += 3;

            if (!a && !b && !c)
                res++;

            sub[{a, b, c}]++;
            sz[u] = 1;

            for (auto v : adj[u])
            {
                if (vis[v] || v == fa)
                    continue;

                self(self, v, u, a, b, c);
                sz[u] += sz[v];
            }
        };

        get_info(get_info, v, u, cnt_a, cnt_b, cnt_c);
        for (auto [x, cnt] : sub)
        {
            auto [a, b, c] = x;
            res += cnt * mp[ { -a, -b, -c}];
        }
        for (auto [x, cnt] : sub)
        {
            auto &[a, b, c] = x;
            mp[ {a - cnt_a, b - cnt_b, c - cnt_c}] += cnt;
        }
    }

    for (auto v : adj[u])   // iterate mp children
    {
        if (vis[v])
            continue;   //  if visited, skip

        res += solve(v, sz[v]); // get the answer of the subtree
    }
    return res;
}

signed main()
{
    fast();
    cin >> n;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cout << solve(1, n) << endl;
    cout.flush();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Node {
    LL cost;
    int idx;
};

inline void solution() {
    int n;
    cin >> n;
    vector<Node> nodes(n + 1);
    vector<LL> res(n + 1);
    for (int i = 1; i <= n; i++) cin >> nodes[i].cost;
    for (int i = 1; i <= n; i++) nodes[i].idx = i;
    sort(nodes.begin() + 1, nodes.end(), [](Node & x, Node & y) {
        return x.cost > y.cost;
    });
    LL cnt = 0, siz = n, l = 1, r = n;
    while (l <= r) {
        if (nodes[l].cost - cnt == siz) {
            res[nodes[l].idx] = siz;
            cnt++, siz--, l++;
        }
        else if (nodes[r].cost - cnt == 0) {
            res[nodes[r].idx] = -siz;
            siz--, r--;
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t_ = 1;
    cin >> t_;
    while (t_--) solution();
}

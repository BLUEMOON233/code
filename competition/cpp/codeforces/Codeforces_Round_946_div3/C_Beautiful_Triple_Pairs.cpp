#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

struct Node {
    int val_1;
    int val_2;
    int val_3;
    const bool operator<(Node node) const {
        if (val_1 != node.val_1) return val_1 < node.val_1;
        if (val_2 != node.val_2) return val_2 < node.val_2;
        return val_3 < node.val_3;
    }
};

void solve() {
    map<PII, int> mp_1;
    map<PII, int> mp_2;
    map<PII, int> mp_3;
    map<Node, int> total;
    set<Node> rec;
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n - 2) {
        int x = a[i];
        int y = a[i + 1];
        int z = a[i + 2];
        mp_1[{y, z}]++;
        mp_2[{x, z}]++;
        mp_3[{x, y}]++;
        total[{x, y, z}]++;
        rec.insert({x, y, z});
    }
    LL rs = 0;
    for (auto it = rec.begin(); it != rec.end(); it++) {
        auto [x, y, z] = *it;
        LL k = total[{x, y, z}];
        LL v;
        v = mp_1[{y, z}];
        // cerr << x << ' ' << y << ' ' << z << '\n';
        // cerr << total[{x, y, z}] << '\n';
        // cerr << mp_1[{y, z}] << '\n';
        rs += k * (v - k);
        v = mp_2[{x, z}];
        rs += k * (v - k);
        v = mp_3[{x, y}];
        rs += k * (v - k);
    }
    cout << rs / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
    return 0;
}
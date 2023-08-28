#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 4e6 + 1;
void work() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> cnt;
    int mx = 0, p = -1;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] >= mx) {
            mx = cnt[a[i]];
            p = a[i];
        }
    }
    if ((*cnt.begin()).second == mx) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cas = 1;
    cin >> cas;
    while (cas--) {
        work();
    }
}
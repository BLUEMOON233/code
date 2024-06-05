#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

template <class T>
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
template <class T>
inline void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
#define read() read<__int128>()

void solve() {
    int n, mod;
    // cin >> n >> mod;
    n = read<int>();
    mod = read<int>();

    vector<LL> a(n + 1);
    __int128 sum = 0;
    rep(i, 1, n) a[i] = read<LL>();
    rep(i, 1, n) a[i] %= mod;
    rep(i, 1, n) sum += a[i] * (n - 1);
    sort(a.begin() + 1, a.end());
    for (int l = 1, r = n; l <= n - 1; l++) {
        while (a[r] + a[l] >= mod && l < r) {
            r--;
        }
        sum -= 1LL * (n - max(r, l)) * mod;
    }
    write<__int128>(sum);
    // cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
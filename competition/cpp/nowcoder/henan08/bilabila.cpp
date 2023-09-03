#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const double pi = acos(-1);

inline void solve() {
    double c72 = cos(72.0 / 180.0 * pi);
    double s72 = sin(72.0 / 180.0 * pi);
    double x;
    cin >> x;
    cout << fixed << setprecision(2);
    cout << "A: " << c72 * x + x << ' ' << 0.0 << '\n';
    double y = c72 * x * 2;
    if (x != 0.0) cout << "B: " << c72 * (x + x + y) << ' ' << -1.0 * s72 * (x + y) << '\n';
    else cout << "B: " << c72 * (x + x + y) << ' ' << s72 * (x + y) << '\n';
    if (x != 0.0) cout << "C: " << -1.0 * c72 * (x + x + y) << ' ' << -1.0 * s72 * (x + y) << '\n';
    else cout << "C: " << c72 * (x + x + y) << ' ' << s72 * (x + y) << '\n';
    if (x != 0.0) cout << "D: " << -1.0 * (c72 * x + x) << ' ' << 0.0 << '\n';
    else cout << "D: " << c72 * x + x << ' ' << 0.0 << '\n';
    cout << "E: " << 0.0 << ' ' << s72 * x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
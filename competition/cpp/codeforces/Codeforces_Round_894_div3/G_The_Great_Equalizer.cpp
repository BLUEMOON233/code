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
template<class T>
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
template<class T>
inline void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
    return;
}
#define read() read<int>()
#define write(tmp) write<int>(tmp);
//#define read() read<LL>()
//#define write(tmp) write<LL>(tmp);
//#define read() read<__int128>()
//#define write(tmp) write<__int128>(tmp);

const int N = 1;

inline void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    multiset<LL> s, d;
    rep(i, 1, n) s.insert(a[i]);
    for (auto it = s.begin(); it != s.end(); it++) {
        if (it == s.begin()) continue;
        d.insert(*it - *prev(it));
    }
    // for (auto it = s.begin(); it != s.end(); it++) cout << *it << ' ';
    // cout << '\n';
    int q;
    cin >> q;
    while (q--) {
        LL p, x;
        cin >> p >> x;
        if (n == 1) {
            a[p] = x;
            cout << a[1] << ' ';
            continue;
        }
        s.erase(s.lower_bound(a[p]));
        auto it = s.lower_bound(a[p]);
        if (it != s.end()) d.erase(d.lower_bound(*it - a[p]));
        if (it != s.begin()) d.erase(d.lower_bound(a[p] - *prev(it)));
        if (it != s.end() && it != s.begin()) d.insert(*it - *prev(it));
        a[p] = x;
        it = s.lower_bound(a[p]);
        if (it != s.end()) d.insert(*it - a[p]);
        if (it != s.begin()) d.insert(a[p] - *prev(it));
        if (it != s.end() && it != s.begin()) d.erase(d.lower_bound(*it - *prev(it)));
        s.insert(a[p]);
        // cout << "\ntest:\n";
        // for (auto it = d.begin(); it != d.end(); it++) cout << *it << ' ';
        // cout << '\n';
        cout << *prev(s.end()) + *prev(d.end()) << ' ';
    }
    cout << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

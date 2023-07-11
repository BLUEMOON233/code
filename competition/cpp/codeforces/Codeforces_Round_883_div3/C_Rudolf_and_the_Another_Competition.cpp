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

struct res {
    int idx = 0;
    int point = 0;
    LL min = 0;
};


inline void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<res> rs(n + 1);
    rep(i, 1, n) {
        vector<int> t(m + 1);
        rep(j, 1, m) cin >> t[j];
        sort(t.begin() + 1, t.end());
        LL now = 0;
        rs[i].idx = i;
        rep(j, 1, m) {
            now += t[j];
            if (now > h) break;
            rs[i].point++;
            rs[i].min += now;
        }
    }
    sort(rs.begin() + 1, rs.end(), [](res& a, res& b) {
        if (a.point != b.point) return a.point > b.point;
        else if (a.min != b.min) return a.min < b.min;
        else return a.idx < b.idx;
        });
    // rep(i, 1, n) cout << rs[i].idx << ' ' << rs[i].point << ' ' << rs[i].min << '\n';
    rep(i, 1, n) if (rs[i].idx == 1) {
        cout << i << '\n';
        return;
    }
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

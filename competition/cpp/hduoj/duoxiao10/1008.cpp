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

LL quickPow(LL a, LL b) {
    LL rs = 1;
    while (b) {
        if (b & 1) rs = rs * a;
        b >>= 1, a = a * a;
    }
    return rs;
}

inline void solve() {
    int n;
    cin >> n;
    int len = quickPow(2, n) - 1;
    vector<int> b(len + 1);
    rep(i, 1, len) cin >> b[i];
    sort(b.begin(), b.end());
    vector<int> rs;
    while (len != 1) {
        int mid = len / 2 + 1;
        unordered_map<int, int> mp;
        rep(i, 1, mid - 1) mp[b[i] ^ b[mid]]++;
        rep(i, mid + 1, len) {
            mp[b[i]]--;
            if (mp[b[i]] < 0) {
                cout << -1 << '\n';
                return;
            }
        }
        rs.emplace_back(b[mid]);
        len = mid - 1;
    }
    rs.emplace_back(b[len]);
    reverse(rs.begin(), rs.end());
    for (auto x : rs) cout << x << ' ';
    cout << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

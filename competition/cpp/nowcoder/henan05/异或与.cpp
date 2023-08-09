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

inline void solve() {
    map<LL, int> mp;
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) mp[a[i]] = i;
    rep(i, 1, n) {
        LL now = a[i], num = 0;
        string str = "";
        rep(j, 0, 60) {
            int x = ((now >> (j + 1)) & 1), y = ((now >> j) & 1);
            if (x == 0 && y == 0) {
                str += '0';
            }
            else if (x == 0 && y == 1) {
                j++;
                str += "11";
            }
            else if (x == 1 && y == 1) {
                j++;
                str += "10";
            }
            else {
                str += '0';
            }
        }
        while (str.length() < 63) str += '0';
        per(j, 63, 0) if (str[j] == '1') {
            num <<= 1;
            num += 1;
        }
        else {
            num <<= 1;
        }
        // cout << i << ' ' << a[i] << ' ' << mp[num] << ' ' << num << '\n';
        if (mp[num] && mp[num] != i) {
            cout << i << ' ' << mp[num] << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

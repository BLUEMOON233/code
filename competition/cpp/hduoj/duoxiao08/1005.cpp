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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '@' + s;
    char now = '0';
    int l = 1, r = n;
    while (l <= r) {
        // cout << now << ' ' << l << ' ' << r << '\n';
        if (l == r) {
            if (s[l] != now) {
                cout << char(1 - now + '0' + '0') << '\n';
            }
            else {
                cout << -1 << '\n';
            }
            return;
        }
        if (s[l] == now && s[r] != now) {
            l++;
            now = 1 - now + '0' + '0';
            continue;
        }
        if (s[l] != now && s[r] == now) {
            r--;
            now = 1 - now + '0' + '0';
            continue;
        }
        break;
    }
    while (l < r) {
        int cnt = 0;
        if (s[l] == now) cnt++;
        if (s[l + 1] == now) cnt++;
        if (s[r] == now) cnt++;
        if (s[r - 1] == now) cnt++;
        if (cnt > 2) {
            cout << now << '\n';
            return;
        }
        int ll = l, rr = r;
        while (ll + 2 <= r) {
            if (s[ll] == now && s[ll + 1] != now) ll += 2;
            else if (s[ll] == now && s[ll + 1] == now) {
                cout << now << '\n';
                return;
            }
            else {
                break;
            }
        }
        while (rr - 2 >= l) {
            if (s[rr] == now && s[rr - 1] != now) rr -= 2;
            else if (s[rr] == now && s[rr - 1] == now) {
                cout << now << '\n';
                return;
            }
            else {
                break;
            }
        }
        if (ll > rr) {
            cout << -1 << '\n';
            return;
        }
        cout << char(1 - now + '0' + '0') << '\n';
        break;
    }
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

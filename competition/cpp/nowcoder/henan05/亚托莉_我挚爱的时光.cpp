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
    int m;
    cin >> m;
    map<string, bool> mp1, mp2;
    while (m--) {
        string opt, str;
        cin >> opt;
        if (opt == "1") {
            cin >> str;
            if (mp1[str]) cout << "yes\n";
            else cout << "no\n";
        }
        else if (opt == "2") {
            cin >> str;
            if (mp2[str]) cout << "yes\n";
            else cout << "no\n";
        }
        else if (opt == "pacman") {
            cin >> opt >> str;
            if (opt == "-R") {
                mp1[str] = false;
            }
            else if (opt == "-Rscn") {
                mp2[str] = mp1[str] = false;
            }
        }
        else if (opt == "sudo") {
            cin >> opt;
            if (opt == "pacman") {
                cin >> opt >> str;
                mp1[str] = true;
                mp2[str] = true;
            }
            else if (opt == "rm") {
                while (cin >> str) {}
                cout << "wuwuwu\n";
                return;
            }
        }
    }
}



int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

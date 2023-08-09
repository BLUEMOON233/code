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
    int len;
    string str;
    string str1, str2;
    cin >> len >> str;
    for (auto c : str) {
        if (c == '?') {
            str1 += '1';
            str2 += '0';
        }
        else {
            str1 += c;
            str2 += c;
        }
    }
    LL rs = 0, l = 1, r = 1;
    rep(i, 1, len - 1) {
        if (str1[i] == str1[i - 1]) l++;
        else l = 1;
        if (str2[i] == str2[i - 1]) r++;
        else r = 1;
        rs = max({ rs, l, r });
    }
    rs = max({ rs, l, r });
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    cin >> T;
    while (T--) solve();
}

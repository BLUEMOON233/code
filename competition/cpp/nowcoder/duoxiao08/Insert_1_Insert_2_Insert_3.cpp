#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
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

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector <PII> p;
    rep(i, 1, n) {
        int j = i;
        while (j <= n && a[j] == a[i]) j++;
        p.emplace_back(a[i], j - i);
        i = j - 1;
    }
    unordered_map<int, int> mp;
    // for (auto [x, y] : p) cout << x << ' ' << y << '\n';
    int len = p.size();
    LL pre = 0;
    LL rs = 0;
    rep(i, 0, len - 1) {
        // cout << "i: " << i << ' ' << pre << '\n';
        int j = i;
        if (p[i].first == 1) {
            if (p[i + 1].first != 2 || i + 1 > len - 1) {
                rs += (pre + 1 + pre + p[i + 1].second) * p[i + 1].second / 2;
                mp[1]++;
            }
            else {
                LL sz = min(p[i].second, p[i + 1].second);

                int l = p[i].second - sz;
                rs += (pre + 1 + pre + l) * l / 2;
                pre += l;

                rs -= sz;
                while (j + 1 <= len - 1 && p[j + 1].first == p[j].first + 1 && p[j + 1].second <= p[j].second) {
                    rs += p[++j].second;
                }
                rs += (pre + 1 + pre + sz) * sz;
                // cout << i << ' ' << j << '\n';
                i = j;
                pre += 1;
                mp[p[j].first]++;
            }
        }
        else {
            if (mp[p[i].first - 1] >= p[i].second) {
                rs += (mp[p[i].first - 1] - p[i].second + 1 + mp[p[i].first - 1]) * p[i].second / 2;
                mp[p[i].first - 1] -= p[i].second;
                mp[p[i].first] += p[i].second;
                pre -= p[i].second;
            }
            else {
                rs += (1 + mp[p[i].first - 1]) * mp[p[i].first - 1] / 2;
                pre = 0;
                mp.clear();
            }
        }
    }
    cout << rs << '\n';
}

int main() {
    fast();
    int T = 1;
    //	T = read();
    // cin >> T;
    while (T--) solve();
}

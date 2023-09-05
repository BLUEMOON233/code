#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k & 1) {
        priority_queue<char, vector<char>, greater<char> > pq0, pq1;
        rep(i, 0, n - 1)
            if (i & 1) pq0.push(s[i]);
            else pq1.push(s[i]);
        while (pq0.size() || pq1.size()) {
            if (pq1.size()) {
                cout << pq1.top();
                pq1.pop();
            }
            if (pq0.size()) {
                cout << pq0.top();
                pq0.pop();
            }
        }
        cout << '\n';
    }
    else {
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
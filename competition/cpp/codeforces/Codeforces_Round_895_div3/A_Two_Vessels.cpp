#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = j; i <= int(k); i++)

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int dis = abs(a - b);
    LL rs = dis / (c << 1);
    if(dis % (c << 1)) rs++;
    cout << rs << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)


const int N = 1e6 + 7;
int primes[N], cnt = 0; //primes[] include all primes in range
bool st[N]; //false -> prime
void getPrimes(int n) {
    rep(i, 2, n) {
        if (!st[i]) primes[++cnt] = i;
        for (int j = 1; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (!(i % primes[j])) break;
        }
    }
}
vector<LL> pre(1e6 + 1, 0);

inline void solve() {
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    getPrimes(1e6 + 1);
    st[0] = st[1] = true;
    rep(i, 1, 1e6) pre[i] = pre[i - 1] + (!st[i]);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
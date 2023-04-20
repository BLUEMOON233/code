#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 12000;
int n, m;
int v[N], w[N], s[N];
int f[N];

int main() {
    int cnt = 0;
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int tv, tw, ts, k = 1;
        scanf(" %d%d%d", &tv, &tw, &ts);
        while (k <= ts) {
            v[++cnt] = tv * k;
            w[cnt] = tw * k;
            ts -= k;
            k *= 2;
        }
        if (ts > 0) {
            v[++cnt] = tv * ts;
            w[cnt] = tw * ts;
        }
    }
    n = cnt;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    printf("%d\n", f[m]);
    return 0;
}

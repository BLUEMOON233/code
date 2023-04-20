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

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    scanf(" %d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf(" %d%d", &v[i], &w[i]);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    printf("%d\n", f[m]);
    return 0;
}

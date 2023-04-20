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

const int N = 505;
int f[N];

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        for (int j = i; j >= 2; j--) {
            scanf(" %d", &a);
            f[j] = max(f[j - 1] + a, f[j] + a);
        }
        scanf(" %d", &a);
        f[1] += a;
    }
    int ans;
    for (int i = 1; i <= n; i++)
        ans = max(f[i], ans);
    printf("%d\n", ans);
}
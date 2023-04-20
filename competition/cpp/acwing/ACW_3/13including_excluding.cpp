#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;

int n, m;
int p[20];

int main() {
    scanf(" %d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf(" %d", p + i);
    int res = 0;
    for (int i = 1; i < 1 << m; i++) {
        int t = 1, cnt = 0;
        for (int j = 0; j < m; j++)
            if (i >> j & 1) {
                cnt++;
                if ((LL)t * p[j] > n) {
                    t = -1;
                    break;
                }else
                    t *= p[j];
            }
        if (t != -1) {
            if (cnt % 2)
                res += n / t;
            else
                res -= n / t;
        }
    }
    printf("%d\n", res);
}
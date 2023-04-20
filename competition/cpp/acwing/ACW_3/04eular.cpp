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

//欧拉函数指和在1~n中和n互质的个数
// f(n) = N * (1 - 1/p1) * (1 - 1/p2) *...*(1 - 1/pk)
//以下为公式法求欧拉函数
int fuoula() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        int a;
        scanf(" %d", &a);
        int res = a;
        for (int i = 2; i <= n / i; i++) {
            if (a % i == 0) {
                res = res / i * (i - 1);
                while (a % i == 0)
                    a /= i;
            }
        }
        if (a > 1)
            res = res / a * (a - 1);
        printf("%d\n", res);
    }
}

//以下为线性筛法求欧拉函数
const int N = 1000005;
int primes[N], cnt = 0;
int phi[N];
bool st[N];

LL get_eulars(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            } else
                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    LL ans = 0;
    for (int i = 1; i <= n;i++)
        ans += phi[i];
    return ans;
}

int main() {
    int n;
    scanf(" %d", &n);
    printf("%lld\n", get_eulars(n));
}
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

const int mod = 1e9 + 7;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        k >>= 1;
    }
    return res;
}

int main() {
    int n;
    scanf(" %d", &n);
    int a = 2 * n, b = n;
    int res = 1;
    for (int i = a; i > a - b; i--)
        res = (LL)res * i % mod;
    for (int i = 1; i <= b; i++)
        res = (LL)res * qmi(i, mod - 2, mod) % mod;
    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;
    printf("%d\n", res);
    return 0;
}
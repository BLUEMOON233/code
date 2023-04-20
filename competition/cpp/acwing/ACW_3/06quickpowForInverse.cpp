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

int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int quick_pow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (LL)res * a % p;
        b >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        int a, p;
        scanf(" %d%d", &a, &p);
        if (gcd(a, p) != 1)
            puts("impossible");
        else
            printf("%d\n", quick_pow(a, p - 2, p));
    }
}
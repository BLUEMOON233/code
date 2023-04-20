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
    return b ? gcd(b, a % b) : a;
}

int EXgcd(int a, int b, int& x, int& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = EXgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        int a, b, m;
        scanf(" %d%d%d", &a, &b, &m);
        int x, y;
        int d = EXgcd(a, m, x, y);
        if (b % d)
            puts("impossible");
        else
            printf("%d\n", (LL)x * (b / d) % m);
    }
}
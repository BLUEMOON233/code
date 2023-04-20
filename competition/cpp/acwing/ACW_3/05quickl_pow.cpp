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

int quick_pow(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (LL)res * a % p;
        b >>= 1;
        a = (LL)(a * a) % p;
    }
    return res;
}

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        int a, b, p;
        scanf(" %d%d%d", &a, &b, &p);
        printf("%d\n", quick_pow(a, b, p));
    }
}
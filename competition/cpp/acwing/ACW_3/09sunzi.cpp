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

LL exgcd(LL a, LL b, LL& x, LL& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int n;
    scanf(" %d", &n);
    bool has_answer = true;
    LL a1, m1;
    scanf(" %lld%lld", &a1, &m1);
    for (int i = 0; i < n - 1; i++) {
        LL a2, m2;
        scanf(" %lld%lld", &a2, &m2);

        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d) {
            has_answer = false;
            break;
        } else {
            k1 *= (m2 - m1) / d;
            LL t = a2 / d;
            k1 = (k1 % t + t) % t;
            m1 = a1 * k1 + m1;
            a1 = abs(a1 / d * a2);
        }
    }
    if (has_answer)
        printf("%lld\n", (m1 % a1 + a1) % a1);
    else
        puts("-1");
}
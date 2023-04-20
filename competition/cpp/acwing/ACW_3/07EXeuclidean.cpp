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

//裴蜀定理：有一对正整数a, b,那么一定存在整数x, y,使得 ax + by = gcd (a, b)

// int gcd(int a,int b){
//     return b ? gcd(b, a % b) : a;
// }

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
        int a, b, x, y;
        scanf(" %d%d", &a, &b);
        EXgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
}
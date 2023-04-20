#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
typedef long long ll;

using namespace std;

double cubeRoot(double n) {
    const double eps = 1e-7;
    double l = -100000, r = 100000;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    double n;
    cin >> n;
    printf("%.6f", cubeRoot(n));

    return 0;
}
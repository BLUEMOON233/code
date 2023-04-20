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

vector<int> getDivisors(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; i++)
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    sort(res.begin(), res.end());

    for (auto k : res)
        printf("%d ", k);
    puts("");

    return res;
}

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        int x;
        scanf(" %d", &x);
        getDivisors(x);
    }
}
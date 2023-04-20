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

const int N = 1e5 + 10;
int prime[N], cnt = 0;
bool st[N];

void getPrime(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] <= n / i; j++) {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    int n;
    scanf(" %d", &n);
    getPrime(n);
    printf("%d\n", cnt);
}
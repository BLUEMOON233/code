#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int UI;
typedef long long LL;

const int N = 200003, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N)
            k = 0;
    }
    return k;
}

int main() {
    memset(h, 0x1, sizeof(int)*N);
    cout << h[3] << endl;
    cout << 0x01010101 << endl;
    int n;
    scanf(" %d", &n);
    while (n--) {
        int x;
        char op[2];
        scanf(" %s%d", &op, &x);
        int k = find(x);
        cout << "k:" << k << endl;
        if (*op == 'I')
            h[k] = x;
        else if (h[k] != null)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
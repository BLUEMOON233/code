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

void quickSort(int q[], int l, int r) {
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }
    quickSort(q, l, j), quickSort(q, j + 1, r);
}

int main() {
    int n;
    int q[100010];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    quickSort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    return 0;
}
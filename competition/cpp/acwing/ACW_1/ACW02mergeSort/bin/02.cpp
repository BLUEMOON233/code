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

ll ans = 0;
int tmp[100010];
int q[100010];

void mergeSort(int q[], int l, int r) {
    if (l >= r)
        return;
    ll mid = l + r >> 1;
    mergeSort(q, l, mid);
    mergeSort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            ans += (mid - i + 1);
        }

    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    mergeSort(q, 0, n - 1);
    printf("%lld\n", ans);
    return 0;
}
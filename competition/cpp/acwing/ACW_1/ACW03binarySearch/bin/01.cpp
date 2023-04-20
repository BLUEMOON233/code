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

const int N = 1e5 + 10;
int n, q, a[N];

int bsearch_left(int l, int r, int x) {
    while (l < r) {
        int mid = l + r >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    // if (a[l] != x)
    //     return -1;
    return l;
}

int bsearch_right(int l, int r, int x) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    if (a[l] != x)
        return -1;
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--) {
        int x;
        cin >> x;
        cout << bsearch_left(0, n - 1, x) << " " << bsearch_right(0, n - 1, x)
             << endl;
    }
    return 0;
}
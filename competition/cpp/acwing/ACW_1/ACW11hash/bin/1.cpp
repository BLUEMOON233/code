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

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int n1;
        cin >> n1;
        for (int j = 0; j < n1; j++) {
            int a;
            cin >> a;
            sum += a;
        }
        cout << sum << endl;
        if (i != n - 1)
            cout << endl;
    }
    return 0;
}

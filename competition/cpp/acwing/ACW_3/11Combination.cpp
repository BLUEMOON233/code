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

const int N = 2005, M = 1e9 + 7;
int c[N][N];

void init(){
    for (int i = 0; i <= N;i++)
        for (int j = 0; j <= i;j++)
            if(!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
}

int main(){
    init();
    int n;
    scanf(" %d",&n);
    while(n--){
        int a, b;
        scanf(" %d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
}
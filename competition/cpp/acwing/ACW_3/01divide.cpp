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

void divide(int n){
    for (int i = 2; i <= n / i;i++){
        if(n%i == 0){
            int s = 0;
            while(n%i == 0){
                n /= i;
                s++;
            }
            printf("%d %d\n", i, s);
        }
    }
    if(n>1)
        printf("%d %d\n", n, 1);
    puts("");
}

int main(){
    int t;
    scanf(" %d", &t);
    while(t--){
        int x;
        scanf(" %d", &x);
        divide(x);
    }
}
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

const int N = 100010;

int stk[N], tt;

void add(int x) {
    stk[++tt] = x;
}

void del() {
    tt--;
}

int getStackTop() {
    return stk[tt];
}

bool isEmpty() {
    if (tt > 0)
        return false;
    else
        return true;
}

//***********************************

int que[N], hh, tt = -1;

void add(int x) {
    que[++tt] = x;
}

void del() {
    hh++;
}

bool isEmpty() {
    if (hh <= tt)
        return false;
    else
        return true;
}

int getTop() {
    return que[hh];
}

int getTail() {
    return que[tt];
}
int main() {}
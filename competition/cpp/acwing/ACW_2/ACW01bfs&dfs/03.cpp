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
#include <unordered_map>
#include <vector>

using namespace std;
typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;

int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
unordered_map<string, int> d;
queue<string> q;
string ed = "12345678x";
string str;
unordered_map<string, string> path;

int bfs() {
    q.push(str);
    d[str] = 0;
    path[str] = "end";
    while (!q.empty()) {
        auto tmp = q.front();
        string ttmp = tmp;
        q.pop();
        if (tmp == ed)
            return d[tmp];
        int distance = d[tmp];
        int idx = tmp.find('x');
        int y = idx / 3;
        int x = idx % 3;
        for (int i = 0; i < 4; i++) {
            int sx = x + mov[i][1], sy = y + mov[i][0];
            swap(tmp[sy * 3 + sx], tmp[idx]);
            if (sx >= 0 && sx < 3 && sy >= 0 && sy < 3 && !d[tmp]) {
                d[tmp] = distance + 1;
                q.push(tmp);
            }
            swap(tmp[sy * 3 + sx], tmp[idx]);
        }
    }
    return -1;
}

int main() {
    char c;
    for (int i = 0; i < 9; i++) {
        scanf(" %c", &c);
        str += c;
    }
    printf("%d\n", bfs());
}

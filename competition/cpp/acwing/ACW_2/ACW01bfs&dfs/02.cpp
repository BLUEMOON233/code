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

const int N = 105;
int n, m;
int g[N][N], d[N][N];
int mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs() {
    queue<pair<int, int>> q;
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = tmp.second + mov[i][1];
            int y = tmp.first + mov[i][0];
            if (x >= 0 && x < m && y >= 0 && y < n && g[y][x] == 0 &&
                d[y][x] == -1) {
                d[y][x] = d[tmp.first][tmp.second] + 1;
                q.push({y, x});
            }
        }
    }
    return d[n - 1][m - 1];
}

int main() {
    scanf(" %d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %d", &g[i][j]);
    printf("%d\n", bfs());
}
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define rep(i, j, k) for(int i = int(j); i <= int(k); i++)
#define per(i, j, k) for(int i = int(j); i >= int(k); i--)

const int N = 5e5 + 7, mod = 1e9 + 7;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

inline void solve() {
    LL x, y;
    cin >> x >> y;
    LL n;
    cin >> n;
    string op;
    cin >> op;
    LL tx = 0, ty = 0;
    if(x == 0 && y == 0) {
        cout << "Yes\n";
        return;
    }
    for (auto c : op) {
        if (c == 'U') tx += dx[0], ty += dy[0];
        else if (c == 'D') tx += dx[1], ty += dy[1];
        else if (c == 'L') tx += dx[2], ty += dy[2];
        else tx += dx[3], ty += dy[3];
        // cout << tx << ' ' << ty << '\n';
    }
    // cout << tx << ' ' << ty << '\n';
    LL xx = 0, yy = 0;
    for (auto c : op) {
        if (c == 'U') xx += dx[0], yy += dy[0];
        else if (c == 'D') xx += dx[1], yy += dy[1];
        else if (c == 'L') xx += dx[2], yy += dy[2];
        else xx += dx[3], yy += dy[3];
        // cout << xx << ' ' << yy << '\n';
        if (tx == 0 && ty == 0) {
            if (x == xx && y == yy) {
                cout << "Yes\n";
                return;
            }
        }
        else if (tx == 0 && ty != 0) {
            if (x == xx && (y - yy) % ty == 0) {
                if ((y - yy) / ty >= n || (y - yy) / ty < 0) continue;
                cout << "Yes\n";
                return;
            }
        }
        else if (tx != 0 && ty == 0) {
            if ((x - xx) % tx == 0 && y == yy) {
                if ((x - xx) / tx >= n || (x - xx) / tx < 0) continue;
                cout << "Yes\n";
                return;
            }
        }
        else {
            if ((x - xx) % tx == 0 && (y - yy) % ty == 0) {
                if ((x - xx) / tx >= n || (x - xx) / tx < 0 || (y - yy) / ty >= n || (y - yy) / ty < 0) continue;
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
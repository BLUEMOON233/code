#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
#define per(i, j, k) for (int i = int(j); i >= int(k); i--)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2, -1);
    rep(i, 1, n) cin >> a[i];
    int lp = -1;

    bool none = true;
    rep(i, 1, n) if (a[i] != -1) {
        none = false;
        break;
    }
    if (none) {
        rep(i, 1, n) b[i] = 1 << (i % 2);
        rep(i, 1, n) cout << b[i] << " \n"[i == n];
        return;
    }

    auto getlen = [](int now) -> int {
        int len = 0;
        while (now) {
            now >>= 1;
            len++;
        }
        return len;
    };

    rep(i, 1, n) {
        if (a[i] == -1) continue;
        b[i] = a[i];
        if (lp == -1) {
            lp = i;
            continue;
        }

        //[lp, i]
        // cout << lp << ' ' << i << '\n';
        int cnt = i - lp - 1;

        if (cnt == 0) {
            if (a[lp] == (a[i] >> 1) || a[i] == (a[lp] >> 1)) {
                lp = i;
                continue;
            } else {
                cout << -1 << '\n';
                return;
            }
        }

        bool dis = true;
        int low = a[lp], high = a[i];
        if (low > high) {
            dis = false;
            swap(low, high);
        }

        int bit_l = getlen(low);
        int bit_h = getlen(high);
        // cout << bit_l << ' ' << bit_h << '\n';
        int cost = 0;

        per(j, bit_l - 1, 0) {
            int k = j + bit_h - bit_l;
            if (((low >> j) & 1) != ((high >> k) & 1)) {
                cost = j + 1;
                break;
            }
        }
        // cout << cnt << ' ' << cost << '\n';
        int re = cost;
        cost *= 2;
        cost += bit_h - bit_l;

        // cout << cost << '\n';

        if (cost <= cnt + 1 && ((cnt - cost + 1) % 2 == 0)) {
            if (dis) {
                int idx = lp + 1;
                rep(j, 1, re) {
                    b[idx] = b[idx - 1] >> 1;
                    idx++;
                }
                per(j, re + bit_h - bit_l - 1, 0) {
                    // cout << idx << ' ' << b[idx - 1] << ' ' << ((high >> j) & 1) << ' ';
                    b[idx] = (b[idx - 1] << 1) + ((high >> j) & 1);
                    // cout << b[idx] << '\n';
                    idx++;
                }
                rep(j, 1, (cnt - cost)) {
                    // int hold = b[idx - 1] & 1;
                    if (idx > i) break;
                    b[idx] = (b[idx - 1] << 1);
                    idx++;
                    if (idx > i) break;
                    b[idx] = (b[idx - 1] >> 1);
                    idx++;
                }
                b[i] = a[i];
            } else {
                int idx = i - 1;
                rep(j, 1, re) {
                    b[idx] = b[idx + 1] >> 1;
                    idx--;
                }
                per(j, re + bit_h - bit_l - 1, 0) {
                    b[idx] = (b[idx + 1] << 1) + ((high >> j) & 1);
                    idx--;
                }
                rep(j, 1, (cnt - cost)) {
                    // int hold = b[idx + 1] & 1;
                    if (idx < lp) break;
                    b[idx] = b[idx + 1] << 1;
                    idx--;
                    if (idx < lp) break;
                    b[idx] = b[idx + 1] >> 1;
                    idx--;
                }
                b[lp] = a[lp];
            }
        } else {
            cout << -1 << '\n';
            return;
        }

        lp = i;
    }

    rep(i, 1, n) {
        if (b[i] == -1) continue;
        per(j, i - 1, 1) {
            if (j % 2 != i % 2) b[j] = b[j + 1] << 1;
            else b[j] = b[j + 1] >> 1;
        }
        break;
    }

    per(i, n, 1) {
        if (b[i] == -1) continue;
        rep(j, i + 1, n) {
            if (j % 2 != i % 2) b[j] = b[j - 1] << 1;
            else b[j] = b[j - 1] >> 1;
        }
        break;
    }

    // rep(i, 1, n) cout << a[i] << "\t\n"[i == n];
    rep(i, 1, n) cout << b[i] << " \n"[i == n];
    // cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) solve();
}
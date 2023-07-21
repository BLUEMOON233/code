#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <vector>
#include <stack>
#include <iomanip>
#include <numeric>

#define x first
#define y second
#define endl '\n'
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<char, int> PCI;

const int N = 2e3 + 10;

signed main()
{
    fast();
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<map<int, int>> mp(n + 1), ref(n + 1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                            cin >> mp[i][j];
                            ref[i][mp[i][j]] = j;
                         }
        vector<bool> chosen(m + 1, false);
        vector<int> res;

        int cnt = k % n;
        if (cnt == 0) cnt = n;
        while (k--)
        {
            int mx = 0;
            for (int i = 1; i <= m; i++)
                if (!chosen[i])
                    mx = max(mx, mp[cnt][i]);

            auto idx = ref[cnt][mx];
            chosen[idx] = true;
            res.emplace_back(idx);
            cnt--;
            if (!cnt) cnt = n;
        }

        sort(res.begin(), res.end());
        for (auto &i: res)
            cout << i << " ";
        cout << endl;
        cout.flush();
    }
    cout.flush();
//    system("pause");
    return 0;
}
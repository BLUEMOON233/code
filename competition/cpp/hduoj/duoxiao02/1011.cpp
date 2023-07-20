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
#define int long long

using namespace std;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<char, int> PCI;

const int N = 1e6 + 10;

signed main()
{
//    fast();
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> per(n);
        iota(per.begin(), per.end(), 1);

        PII ans = {0, 0};
        for (int k = 0; k < n; k++)
        {

            int cnt = 0;
//            cout << "now k = " << k << endl;
            while (true)
            {
                int x = -1;
                for (int i = 0; i < k; i++)
                {
                    x = max(x, per[i]);
                }

                bool flag = false;
                for (int i = k; i < n - 1; i++)
                {
                    if (per[i] > x)
                    {
                        x = per[i];
                        flag = true;
                        break;
                    }
                }

//                cout << "permutation = ";
//                for (int i = 0; i < n; i++)
//                    cout << per[i] << " ";
//                cout << endl;

                if (!flag)
                    x = per[n - 1];

                if (x == n)
                    cnt++;
//                cout << "now x = " << x << endl;
                next_permutation(per.begin(), per.end());
                if (is_sorted(per.begin(), per.end()))
                {
//                    cout << cnt << endl;
                    break;
                }
            }
            if (cnt > ans.x)
                ans = {cnt, k};
            else if (cnt == ans.x)
                ans = {cnt, min(ans.y, k)};
        }
        cout << "k = " << ans.y << endl;
//        cout.flush();
    }
    cout.flush();
//    system("pause");
    return 0;
}

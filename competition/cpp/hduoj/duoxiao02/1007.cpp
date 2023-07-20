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
#include <bitset>

#define x first
#define y second
#define endl '\n'
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<char, int> PCI;
#define int long long

const int N = 1e6 + 10;
const int mod = 1000000007;

int head[N], node[N], ne[N], idx;
int d[N];
int n;
int C2[N], C4[N];
bitset<1010> bs[1010];

void add(int a, int b)
{
    node[idx] = b;
    ne[idx] = head[a];
    head[a] = idx++;
}

long long qmi(long long a, long long b, long long p)
{
    long long res = 1 % p;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int bfs(int u)
{
    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i != u)
        {
            int vis = (bs[i] & bs[u]).count();
            if (vis >= 4)
            {
                int x = d[u] - 4;
                if (bs[i][u])
                    x--;
//                cout << "res = " << res << endl;
                res += C4[vis] * C2[x] % mod;
            }
        }
    }
    return res;
}


// dp[i][0] def-> di i ge peng you bu jiao qie qian i ge man zu timu yao qiu
// dp[i][1] def-> di i ge peng you jiao qie qian i ge man zu ti mu yao qiu
//dp[i][1]= min(i-1,i-m+1)

signed main()
{
    fast();
    int t = 1;
    C2[2] = 1;
    C4[4] = 1;
    for (int i = 3; i <= 1e3; i++)
        C2[i] = C2[i - 1] * i % mod * qmi(i - 2, mod - 2, mod) % mod;
    for (int i = 5
                 ; i <= 1e3; i++)
        C4[i] = C4[i - 1] * i % mod * qmi(i - 4, mod - 2, mod) % mod;
    cin >> t;

    while (t--)
    {
        idx = 0;

        int m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            head[i] = -1, d[i] = 0, bs[i].reset();
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            if (a == b)
                continue;
            d[a]++, d[b]++;
            bs[a][b] = bs[b][a] = true;
            add(a, b), add(b, a);
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] >= 6)
            {
                res += bfs(i);
                res %= mod;
            }
        }
        cout << res << endl;
//        cout.flush();
    }
    cout.flush();
//    system("pause");
    return 0;
}
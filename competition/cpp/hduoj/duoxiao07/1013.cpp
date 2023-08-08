#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define mes(tmp, data) memset(tmp, data, sizeof tmp)
#define debug(x) cerr << "(" << __LINE__ << ")" << #x << " = " << x << endl;
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout<<tmp[i]<<" \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout<<tmp[i]<<" \n"[i == Size]
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"

const int N = 1e5 + 7;
LL a[N], temp[N];
LL n;
LL merge_sort(LL* q, LL l, LL r) {
	if (l >= r) return 0;
	LL mid = l + r >> 1;
	LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
	LL i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) temp[k++] = q[i++];
		else {
			res += mid - i + 1;
			temp[k++] = q[j++];
		}
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= r) temp[k++] = a[j++];
	for (k = 0, i = l; i <= r; i++, k++) q[i] = temp[k];
	return res;
}


inline void solve() {
	cin >> n;
	vector<LL> p(n);
	rep(i, 0, n - 1) cin >> p[i];
	rep(i, 0, n - 1) a[i] = p[i];
	LL rs1 = merge_sort(a, 0, n - 1);
	if (rs1 % 2) rs1 = 2;
	else rs1 = 0;
	cout << rs1 << ' ';
	per(i, 29, 2) if (n >= (1 << i)) rs1 += (1 << i);
	cout << (rs1 | 1) << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

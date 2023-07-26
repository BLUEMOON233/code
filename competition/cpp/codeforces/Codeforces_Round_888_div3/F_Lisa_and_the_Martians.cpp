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
template<class T>
inline T read() {
	T x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
template<class T>
inline void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
	return;
}
#define read() read<int>()
#define write(tmp) write<int>(tmp);
//#define read() read<LL>()
//#define write(tmp) write<LL>(tmp);
//#define read() read<__int128>()
//#define write(tmp) write<__int128>(tmp);

const int N = 1;
int n, k;

struct Node {
	bitset<30> val;
	int idx;
};

bool cmp(Node &x, Node &y) {
	per(i, k - 1, 0) if (x.val[i] < y.val[i]) return true;
	else if (x.val[i] > y.val[i]) return false;
	return x.idx < y.idx;
}

inline void solve() {
	cin >> n >> k;
	vector<Node> a(n + 1);
	rep(i, 1, n) {
		int t;
		cin >> t;
		a[i].val = t;
		a[i].idx = i;
	}
	sort(a.begin() + 1, a.end(), cmp);
	// rep(i, 1, n) cout << a[i].val.to_string() << '\n';
	LL rsi = -1, rsj = -1, max_val = -1, rsx = -1;
	rep(i, 1, n - 1) {
		LL t = 0, tt = 0;
		per(j, k - 1, 0) {
			t <<= 1, tt <<= 1;
			// cout << !(a[i].val[j] ^ a[i + 1].val[j]) << '\n';
			if (!a[i].val[j] ^ a[i + 1].val[j]) {
				t++;
				tt += !a[i].val[j];
			}
		}
		// cout << t << ' ' << tt << '\n';
		if (t > max_val) {
			max_val = t;
			rsx = tt;
			rsi = min(a[i].idx, a[i + 1].idx);
			rsj = max(a[i].idx, a[i + 1].idx);
		}
		// cout << endl;
	}
	cout << rsi << ' ' << rsj << ' ' << rsx << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

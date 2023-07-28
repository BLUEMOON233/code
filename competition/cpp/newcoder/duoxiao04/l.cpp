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

struct Node {
	LL rc;
	LL val;
	LL opt;
};

inline void solve() {
	LL n, m, q;
	cin >> n >> m >> q;
	vector<bool> row(n + 1);
	vector<bool> col(m + 1);
	LL cnt_r = 0, cnt_c = 0;
	vector<Node> op(q + 1);
	rep(i, 1, q) {
		string s1, s2;
		cin >> s1 >> op[i].val >> s2;
		if (s1 == "row") op[i].rc = 1;
		else op[i].rc = 2;
		if (s2 == "on") op[i].opt = 1;
		else op[i].opt = 2;
	}
	LL rs = 0;
	per(i, q, 1) {
		if (op[i].opt == 1) {
			if (op[i].rc == 1) {
				if (row[op[i].val]) continue;
				rs += m - cnt_c;
				cnt_r++;
				row[op[i].val] = true;
			} else {
				if (col[op[i].val]) continue;
				rs += n - cnt_r;
				cnt_c++;
				col[op[i].val] = true;
			}
		} else {
			if (op[i].rc == 1) {
				if (row[op[i].val]) continue;
				cnt_r++;
				row[op[i].val] = true;
			} else {
				if (col[op[i].val]) continue;
				cnt_c++;
				col[op[i].val] = true;
			}
		}
	}
	cout << rs << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

#include<bits/stdc++.h>
using namespace std;
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
// #define read() read<int>()
// #define write(tmp) write<int>(tmp);
//#define read() read<LL>()
//#define write(tmp) write<LL>(tmp);
#define read() read<__int128>()
#define write(tmp) write<__int128>(tmp);

const int N = 1;

inline void solve() {
	// cin >> n;
	__int128 n;
	n = read();
	if (n == 1) {
		printf("0\n");
		return;
	}
	__int128 c = (n + 5) / 10;
	__int128 rs1 = ((c - 1) * 5 + 5) * (c - 1) / 2;
	__int128 d = (n + 5) % 10;
	rs1 += ((d / 2) + 1) * c;
	// write(n);
	// putchar(' ');
	// write(rs1);
	// putchar(' ');
	c = n / 10;
	__int128 rs2 = ((c - 1) * 5 + 5) * (c - 1) / 2;
	d = n % 10;
	rs2 += ((d / 2) + 1) * c;
	// write(rs2);
	// puts("");
	// if (a == 0) rs2 += 1;
	write(rs1 + rs2);
	puts("");
}

int main() {
	// fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	solve();
	// rep(i, 1, 100) solve(i);
}


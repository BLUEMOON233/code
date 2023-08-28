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

inline void solve() {
<<<<<<< HEAD

=======
	string s;
	cin >> s;
	LL a = 0, b = 0, c = 0, d = 0;
	int p = 0;
	while (p < s.length() && !isdigit(s[p])) {
		a *= 26;
		a += s[p] - 'A' + 1;
		p++;
	}
	while (p < s.length() && isdigit(s[p])) {
		b *= 10;
		b += s[p] - '0';
		p++;
	}
	while (p < s.length() && !isdigit(s[p])) {
		c *= 26;
		c += s[p] - 'A' + 1;
		p++;
	}
	while (p < s.length() && isdigit(s[p])) {
		d *= 10;
		d += s[p] - '0';
		p++;
	}
	if (a == 18 && c == 3) {
		string rs = "";
		while (d) {
			rs += 'A' + (d - 1) % 26;
			d = (d - 1) / 26;
		}
		reverse(rs.begin(), rs.end());
		cout << rs << b << '\n';
	} else {
		cout << 'R' << b << 'C' << a << '\n';
	}
>>>>>>> aebcf2255e7444dfb5479f18d9530c412a0b0b95
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	cin >> T;
	while (T--) solve();
}

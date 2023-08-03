#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
#define endl '\n'
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
	if (x < 0) {
		x += P;
	}
	if (x >= P) {
		x -= P;
	}
	return x;
}
template<class T>
T power(T a, i64 b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) {
			res *= a;
		}
	}
	return res;
}
struct Z {
	int x;
	Z(int x = 0) : x(norm(x)) {}
	Z(i64 x) : x(norm(x % P)) {}
	int val() const {
		return x;
	}
	Z operator-() const {
		return Z(norm(P - x));
	}
	Z inv() const {
		assert(x != 0);
		return power(*this, P - 2);
	}
	Z &operator*=(const Z &rhs) {
		x = i64(x) * rhs.x % P;
		return *this;
	}
	Z &operator+=(const Z &rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	Z &operator-=(const Z &rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	Z &operator/=(const Z &rhs) {
		return *this *= rhs.inv();
	}
	friend Z operator*(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res *= rhs;
		return res;
	}
	friend Z operator+(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res += rhs;
		return res;
	}
	friend Z operator-(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res -= rhs;
		return res;
	}
	friend Z operator/(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res /= rhs;
		return res;
	}
	friend std::istream &operator>>(std::istream &is, Z &a) {
		i64 v;
		is >> v;
		a = Z(v);
		return is;
	}
	friend std::ostream &operator<<(std::ostream &os, const Z &a) {
		return os << a.val();
	}
};

inline void solve() {
	string str;
	cin >> str;
	int n = str.size();
	str = '@' + str;
	vector<vector<Z> > dp(n + 2, vector<Z>(n + 2, 0));
	dp[0][0] = 1;
	rep(i, 1, n) {
		if (str[i] == '?') dp[i][0] += dp[i - 1][1];
		if (str[i] == '?') dp[i][n] += dp[i - 1][n - 1];
		if (str[i] == ')') dp[i][0] += dp[i - 1][1];
		if (str[i] == '(') dp[i][n] += dp[i - 1][n - 1];
		rep(j, 1, n - 1) {
			if (str[i] == '(') dp[i][j] += dp[i - 1][j - 1];
			else if (str[i] == ')') dp[i][j] += dp[i - 1][j + 1];
			else dp[i][j] += dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
	}
	cout << dp[n][0] << '\n';
}

int main() {
	fast();
	int T = 1;
	//	T = read();
	// cin >> T;
	while (T--) solve();
}

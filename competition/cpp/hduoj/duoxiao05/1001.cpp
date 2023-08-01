#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
using ll = long long;
using db = double;
const db eps = 1e-6;
//double类型判断是否为0
inline int sgn(db x) {
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	return 1;
}
//double 类型平方
db spr(db x) {return x * x;}
//二维几何
struct Point {
	db x, y;
	Point() {}
	Point(db x, db y): x(x), y(y) {}
	// 3.常用，求向量
	Point operator - (const Point &b)const {
		return Point(x - b.x, y - b.y);
	}
	// 4. 叉积
	db operator ^ (const Point &b)const {
		return x * b.y - y * b.x;
	}
	// 5. 点积
	db operator * (const Point &b)const {
		return x * b.x + y * b.y;
	}
	// 8. 返回两点距离
	db distance(Point &p) {
		// return hypot(x - p.x, y - p.y);
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
};

struct Line {
	Point s, e;
	double len;
	Line() {}
	Line(Point s, Point e): s(s), e(e) {
		len = s.distance(e);
	}

	// 30. 点到直线的距离
	db dispointtoline(Point &p) {
		return fabs((p - s) ^ (e - s)) / len;
	}
	// 31. 点到线段的距离
	db dispointtoseg(Point &p) {
		if (sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
			return min(p.distance(s), p.distance(e));
		return dispointtoline(p);
	}
};

inline void solve() {
	int m, n;
	cin >> m >> n;
	vector<Point> p(m + 1);
	vector<Point> s(n + 1);
	vector<Line> ls(m);
	rep(i, 1, m) {
		// db x, y;
		int x, y;
		cin >> x >> y;
		p[i] = Point(x, y);
	}
	rep(i, 1, n) {
		db x, y;
		cin >> x >> y;
		s[i] = Point(x, y);
	}
	rep(i, 1, m - 1) {
		ls[i] = Line(p[i], p[i + 1]);
	}
	rep(i, 1, n) {
		Point now = s[i];
		double rs = 1e10;
		rep(j, 1, m - 1) rs = min(rs, ls[j].dispointtoseg(now));
		cout << fixed << setprecision(4) << rs << '\n';
		// printf("%.4lf\n", rs);
	}
}

int main() {
	fast();
	int T = 1;
	// T = read();
	// cin >> T;
	while (T--) solve();
}

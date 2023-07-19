# ACM模板库

*********

## 马猴烧酒の必备魔法

### 马猴烧酒の魔法起手式

````C++
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int UI;
typedef pair<int, int> PII;
#define rep(i,j,k) for(int i=int(j);i<=int(k);i++)
#define per(i,j,k) for(int i=int(j);i>=int(k);i--)
#define mes(tmp, data) memset(tmp, data, sizeof tmp)
#define debug0(tmp, Size) rep(i, 0, Size - 1) cout<<tmp[i]<<" \n"[i == Size - 1]
#define debug1(tmp, Size) rep(i, 1, Size) cout<<tmp[i]<<" \n"[i == Size]
#define fast() ios::sync_with_stdio(false); cin.tie(nullptr)
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
const int N = 1;

inline void solve() {
}

int main() {
	fast();
	int T = 1;
//	cin >> T;
	while (T--) solve();
}
````

### 马猴烧酒の魔法释放术

#### 快读快写

顺带支持__int128的输入输出

```C++
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
} //注意关闭同步后要使用C语言输出
template<class T>
inline void write(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
	return;
} // 记得改下面的数据类型
#define read() read<__int128>()
```

#### 高精度

```C++
vector<int> add(vector<int>& A, vector<int>& B) {
	if (A.size() < B.size()) return add(B, A);
	vector<int> C;
	int t = 0;
	rep(i, 0, A.size() - 1) {
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t) C.push_back(t);
	return C;
}
vector<int> sub(vector<int>& A, vector<int>& B) {
	vector<int> C;
	int t = 0;
	rep(i, 0, A.size() - 1) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
vector<int> mul(vector<int>& A, int b) {
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
int r;
vector<int> div(vector<int>& A, int b, int& r) {
	vector<int> C;
	r = 0;
	per(i, A.size() - 1, 0) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
```

####  i64乘法

**时间复杂度：** $O(logb)$

```C++
LL mul(LL a, LL b, LL p) {
	LL ans = 0;
	for (; b; b >>= 1) {
		if (b & 1) ans = (ans + a) % p;
		a = (a << 1) % p;
	}
	return ans;
}
```

#### i64乘法（long double）

```C++
ULL mul(ULL a, ULL b, ULL p) {
	a %= p, b %= p;
	ULL c = (long double)a * b / p;
	ULL x = a * b, y = c * p;
	LL ans = (LL)(x % p) - (LL)(y % p);
	if (ans < 0) ans += p;
	return ans;
}
```

#### 特殊数据类型

- **__int128**
  **存储范围：**[$2^{127},\ 2^{127}-1$] (-1.7014118e+38, 1.7014118e+38)，加unsigned可以存储到39位
  **读入读出：**使用快读快写
- **long double**
  **存储范围：**long double 能精确到18位左右。（12 字节）
  **读入读出：**scanf("%Lf", &a); printf("%.10Lf", a); 或者使用C++流输入输出
  **注意事项：**long double 的数学常用符号都需要在后面加个l， 例如fabsl(a)，sqrtl(a)，cosl(a)...

## 数论

******

### 基本处理

#### 最大公因数

```C++
__gcd(a, b);
```

```C++
inline int gcd(int a, int b) {
	while(b ^= a ^= b ^= a %= b);
	return a;
}
```

#### 最小公倍数

```C++
inline int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}
```

#### 分解质因数

```C++
void divide(int n) {
	rep(i, 2, n / i) if (!(n % i)) {
		int s = 0;
		while (!(n % i)) n /= i, s++;
		cout << i << ' ' << s << '\n';
	} //i -> prime | s -> count of this prime
	if (n > 1) cout << n << ' ' << 1 << '\n';
}
```

### 处理质数

#### 欧拉筛

```C++
int primes[N], cnt = 0; //primes[] include all primes in range
bool st[N]; //false -> prime
void getPrimes(int n) {
	rep(i, 2, n) {
		if (!st[i]) primes[++cnt] = i;
		for (int j = 1; primes[j] <= n / i; j++) {
			st[primes[j] * i] = true;
			if (!(i % primes[j])) break;
		}
	}
}
```

### 快速幂

```C++
LL quickPow(LL a, LL b, LL mod) {
	LL rs = 1;
	while (b) {
		if (b & 1) rs = rs * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return rs % mod;
}
LL quickPow(LL a, LL mod) {
	return quickPow(a, mod - 2, mod);
}
```

### 扩展欧几里得（Exgcd）

#### 裴蜀定理

若 $a$, $b$ 是整数,且 $gcd(a,b)=d$，那么对于任意的整数 $x,\ y,\ ax+by$ 都一定是 $d$ 的倍数，特别地，一定存在整数 $x$, $y$，使 $ax+by=d$ 成立。
它的一个重要推论是: $a$, $b$ 互质的充分必要条件是存在整数 $x$, $y$ 使 $ax+by=1$。
对于 $ax + by = gcd(a, b)$ 其通解为 $x = x_0 + (b/gcd)*k,\ y = y_0 – (a/gcd)*k\ \ (k∈Z)$
对于 $ax + by = c$ ，我们令 $gcd(a, b) = d,\ X = x/c*d,\ Y = x/c*d$，则原式化为 $aX + bY=d$，其有解条件为$c\ \%\ gcd(a,b)=0$

```C++
LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	LL g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
} //g means gcd(a, b), {x, y} was a special solution of the equation "ax + by = gcd(a, b)";
void exgcd(LL a, LL b, LL c, LL &x, LL &y) {
	LL X, Y;
	LL d = exgcd(a, b, X, Y);
	if (c % d) {
		cout << "No solution\n";
		return;
	}
	X *= c / d, b /= d;
	if (b < 0) b = -b;
	x = X % b;
	// 取零暴力：
	while (x < 0) x += b;
	// // 取零二分：
	// LL l = 0, r = 1e14 / b;
	// while (l < r) {
	// 	LL mid = (l + r) >> 1;
	// 	if (x + b * mid >= 0) r = mid;
	// 	else l = mid + 1;
	// }
	// x += l * b;
	y = (c - a * x) / (b * d);
}
```



## 数据维护

***********

### 前缀和

**操作：**$O(1)$的时间复杂度查询某个区间总和

**时间复杂度：**预处理$O(N)$，查询$O(1)$

```C++
pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j]; //二维前缀和
inline int get(int x1, int y1, int x2, int y2) {
    return s[x2, y2] - s[x1 - 1, y2] - s[x2, y1 - 1] + s[x1 - 1, y1 - 1];
} //返回{[x1, y1], [x2, y2]}范围内的区间和。
```

### 差分

**操作：**$O(1)$ 的时间复杂度对一个区间进行增删操作（但是查询为$O(N)$，适合多增删，少查询）

**时间复杂度：**预处理$O(N)$，查询$O(N)$，修改$O(1)$。

```C++
pre[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1]; //二维差分
inline void add(int x1, int y1, int x2, int y2, int val) {
    d[x1][y1] += val, d[x2 + 1][y2 + 1] += val, d[x2 + 1][y1] -= val, d[x1][y2 + 1] -= val;
} //在{[x1, y1], [x2, y2]}区间内+=val
```

### 容器

#### 二叉堆

```C++
LL heap[N], sz = 0;
void up(int p) {
	while (p > 1) if (heap[p] > heap[p >> 1]) {
			swap(heap[p], heap[p >> 1]);
			p >>= 1;
		} else break;
}
void down(int p) {
	int s = p << 1;
	while (s <= sz) {
		if (s < sz && heap[s] < heap[s + 1]) s++;
		if (heap[s] > heap[p]) {
			swap(heap[s], heap[p]);
			swap(s, p);
			s <<= 1;
		} else break;
	}
}
void Insert(LL val) {
	heap[++sz] = val;
	up(sz);
}
LL Top() {
	return heap[1];
}
void Pop(int pos = 1) {
	heap[pos] = heap[sz--];
	up(pos), down(pos);
}
```

### ST算法（区间最值）

**时间复杂度：** 预处理 $O(nlogn)$
					   查询 $O(1)$

```C++
template <class T>
struct STtable {
	int Size, t;
	vector<T> &a;
	vector<vector<T> > f;
	STtable(vector<T> &array): a(array), Size(array.size() - 1) {
		t = log2(Size) + 1;
		f = vector<vector<T> >(Size + 1, vector<T>(log2(Size) + 7, 0));
		rep(i, 1, Size) f[i][0] = a[i];
		rep(j, 1, t - 1) rep(i, 1, Size - (1 << j) + 1)
		f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	}
	T query(int l, int r) {
		int k = log2(r - l + 1);
		return max(f[l][k], f[r - (1 << k) + 1][k]);
	}
};
```

### 并查集

**操作：**查找 确定某个元素处于哪个子集。
		   合并 将两个子集合并成一个集合。

**时间复杂度：**预处理$O(N)$，查询和合并$O(1)$（路径压缩后查询和合并都近似为常数级别。）

```C++
struct DSU {
	vector<int> p, Size;
	DSU(int n) : p(n + 1), Size(n + 1, 1) { iota(p.begin(), p.end(), 0);}
	int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
	bool same(int x, int y) {return find(x) == find(y);}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		Size[x] += Size[y], p[y] = x;
		return true;
	}
	int size(int x) {return Size[find(x)];}
};
```

### 树状数组

**操作：**数组的单点修改，区间求和。

**时间复杂度：**查询和修改均为$O(logN)$

可以拓展为求逆序对数量，注意  {x, x} 相同的元素会被认为是逆序对（虽然不合法）

```C++
LL a[N], tr[N], n;
inline LL lowbit(int x) {
	return x & -x;
}
inline void add(LL x, LL y) {
	for (LL i = x; i <= n; i += lowbit(i)) tr[i] += y;
} //getSum can get sum of a[1, x];
LL getSum(LL x) {
	LL rs = 0;
	for (LL i = x; i; i -= lowbit(i)) rs += tr[i];
	return rs;
}
LL getInversion () {
	LL rs = 0;
	per(i, n, 1) rs += getSum(a[i]), add(a[i], 1);
	return rs;
}
```

### 分块

**操作：**区间修改、区间查询、处理不满足区间可加性这种情况（优雅的暴力）

**时间复杂度：**查询和修改均为$O(\sqrt{N})$

```C++
LL a[N], sum[N], add[N];
int L[N], R[N], pos[N], n, t; //t -> number of sections
void change(int l, int r, LL d) {
	int p = pos[l], q = pos[r];
	if (p == q) {
		rep(i, l, r) a[i] += d;
		sum[p] += d * (r - l + 1);
	} else {
		rep(i, p + 1, q - 1) add[i] += d;
		rep(i, l, R[p]) a[i] += d;
		sum[p] += d * (R[p] - l + 1);
		rep(i, L[q], r) a[i] += d;
		sum[q] += d * (r - L[q] + 1);
	}
} // initaction: init();
LL ask(int l, int r) {
	LL p = pos[l], q = pos[r], rs = 0;
	if (p == q) {
		rep(i, l, r) rs += a[i];
		rs += add[p] * (r - l + 1);
	} else {
		rep(i, p + 1, q - 1) rs += sum[i] + add[i] * (R[i] - L[i] + 1);
		rep(i, l, R[p]) rs += a[i];
		rs += add[p] * (R[p] - l + 1);
		rep(i, L[q], r) rs += a[i];
		rs += add[q] * (r - L[q] + 1);
	}
	return rs;
}
inline void init() {
	t = sqrt(n);
	rep(i, 1, t) L[i] = (i - 1) * t + 1, R[i] = i * t;
	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
	rep(i, 1, t) rep(j, L[i], R[i]) pos[j] = i, sum[i] += a[j];
}
```

### 线段树

**操作：**区间查询、区间修改

**时间复杂度：**查询和修改均为$O(logN)$

```C++
int w[N], n, m;
struct Node {
	int l, r;
	LL sum, add;
} tr[N << 2];
void pushup(int u) {
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void pushdown(int u) {
	Node &rt = tr[u], &lp = tr[u << 1], &rp = tr[u << 1 | 1];
	if (rt.add) {
		lp.add += rt.add, lp.sum += (LL)(lp.r - lp.l + 1) * rt.add;
		rp.add += rt.add, rp.sum += (LL)(rp.r - rp.l + 1) * rt.add;
		rt.add = 0;
	}
}
void build(int u, int l, int r) {
	if (l == r) tr[u] = {l, r, w[l], 0};
	else {
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int l, int r, LL v) {
	if (l <= tr[u].l && tr[u].r <= r) {
		tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * v;
		tr[u].add += v;
	} else {
		pushdown(u);
		int mid = tr[u].l + tr[u].r >> 1;
		if (l <= mid) modify(u << 1, l, r, v);
		if (r > mid) modify(u << 1 | 1, l, r, v);
		pushup(u);
	}
}
LL query(int u, int l, int r) {
	if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	LL rs = 0;
	if (l <= mid) rs = query(u << 1, l, r);
	if (r > mid) rs += query(u << 1 | 1, l, r);
	return rs;
}
```



## 图论

************

### 二分图

#### 染色法

判断是否为二分图

**时间复杂度：**$O(M + N)$

```C++
int st[N], h[N], e[N << 1], ne[N << 1], idx;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}//initaction: mes(h, -1);
bool dfs(int u, int c) {
	st[u] = c; // st[]:0 -> no color, 1/2 -> color
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j] && !dfs(j, 3 - c) || st[j] == c) return false;
	} // dfs(u, c) -> try paint c color on node u
	return true;
}// !st[u] && !dfs(i, 1) -> no answer
```

#### 匈牙利算法

寻找二分图的最大匹配
PS：二分图的匹配：
给定一个二分图 G，在 G 的一个子图 M 中，M 的边集 {E} 中的任意两条边都不依附于同一个顶点，则称 M 是一个匹配。

**时间复杂度：**$O(N_1^2 * N_2)$ ，$N_1$、$N_2$图中两侧点的数量

```C++
int h[N], e[M], ne[M], idx = 0, n1, n2, mtch[N], st[N];;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
} //initaction: mes(h, -1);
int find(int x) { //every find need mes(st, false);
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			st[j] = true;
			if (!mtch[j] || find(mtch[j])) {
				mtch[j] = x;
				return true;
			}
		}
	}
	return false;
}
```

### 最短路

#### Floyd算法

```C++
void floyd() {
	rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
```

#### Dijkstra算法（堆优化）

Dijkstra算法处理最短路适用于有重边，有自环，无负权的有向图，且只适用于求**单源最短路**。

**时间复杂度：**$O(|E|+|V|log|V|)$

```C++
int dist[N], h[N], e[N], ne[N], w[N], idx = 0;
bool st[N];
inline void add(int a, int b, int c) {
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dijkstra(int s, int n) {
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	mes(dist, 0x3f), dist[s] = 0, heap.push({0, s});
	while (!heap.empty()) {
		auto [d, v] = heap.top();
		heap.pop();
		if (st[v]) continue;
		st[v] = true;
		for (int i = h[v]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[v] + w[i]) dist[j] = dist[v] + w[i], heap.push({dist[j], j});
		}
	}
	return dist[n] == 0x3f3f3f3f;
}
```

#### SPFA算法

SPFA算法求最短路主要适用于有重边，有自环，有负边权的有向图，且只适用于求**单源最短路**
相当于一个优化版的bellman-ford算法，只要是非负边权的话还是用堆优化Dijkstra。

**时间复杂度：**最优$O(kE)$ (其中$k$为常数) ，最坏$O(VE)$

```C++
int dist[N], h[N], e[M], ne[M], w[M], idx = 0;
bool st[N];
inline void add(int a, int b, int c) {
	w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void spfa(int s, int n) {
	queue<int>q;
	mes(dist, 0x3f), dist[s] = 0, st[s] = true, q.push(s);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		st[t]  = false;
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if (!st[j]) q.push(j), st[j] = true;
			}
		}
	}
	if (dist[n] > 0x3f3f3f3f / 2) cout << "impossible\n";
	else cout << dist[n] << '\n';
}
```

### 最小生成树

#### prim算法

```C++
int g[N][N], dist[N]; //g[x][y] -> distance between x and y
bool st[N]; //initaction: mes(g, 0x3f);
int prim(int n) {
	mes(dist, 0x3f);
	int rs = 0;
	rep(i, 0, n - 1) {
		int t = -1;
		rep(j, 1, n) if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
		if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
		if (i) rs += dist[t];
		st[t] = true;
		rep(j, 1, n) dist[j] = min(dist[j], g[t][j]);
	}
	return rs;
}
```

#### kruskal算法

```C++
struct Edge {
	int a, b, w;
	bool operator<(const Edge & W) const {
		return w < W.w;
	}
} edges[2 * N];
int p[N];
int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}
int kruskal(int n, int m) {
	int rs = 0, cnt = 0;
	sort(edges + 1, edges + 1 + m);
	rep(i, 1, n) p[i] = i;
	rep(i, 1, m) {
		int a = find(edges[i].a), b = find(edges[i].b), w = edges[i].w;
		if (a != b) p[a] = b, rs += w, cnt++;
	}
	if (cnt < n - 1) return 0x3f3f3f3f;
	else return rs;
}
```

### 最近公共祖先（LCA）

#### 倍增算法

时间复杂度：预处理$O(nlogn)$查询$O(logn)$

```C++
int h[N], e[2 * N], ne[2 * N], idx = 0, depth[N], fa[N][16];
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}//initaction: mes(h, -1), 可将队列改为数组形式减少时间复杂度的常数。
void initBFS(int rt) {
	queue<int> q;
	mes(depth, 0x3f), depth[0] = 0, depth[rt] = 1, q.push(rt);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = h[x]; i != -1; i = ne[i]) {
			int j = e[i];
			if (depth[j] > depth[x] + 1) {
				depth[j] = depth[x] + 1, q.push(j), fa[j][0] = x;
				rep(k, 1, 15) fa[j][k] = fa[fa[j][k - 1]][k - 1];
			}
		}
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	per(k, 15, 0) if (depth[fa[a][k]] >= depth[b]) a = fa[a][k];
	if (a == b) return a;
	per(k, 15, 0) if (fa[a][k] != fa[b][k]) a = fa[a][k], b = fa[b][k];
	return fa[a][0];
}
```

### 强连通分量

#### tarjan 算法

Tarjan算法求有向图强连通分量并缩点

```C++
const int N = 1e5 + 7, M = 1e6 + 7;
int e[M], ne[M], h[N], dfn[N], low[N], idx = 0;
int ce[M], cne[M], ch[N], cidx = 0;
int ins[N], c[N];
int n, m, num = 0, scc_cnt = 0;
stack<int> stk;
vector<int> scc[N];
inline void add(int a, int b) {
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}
inline void add_c(int a, int b) {
	ce[++cidx] = b, cne[cidx] = ch[a], ch[a] = cidx;
}
void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	stk.push(x);
	ins[x] = 1;
	for (int i = h[x]; i; i = ne[i]) {
		int j = e[i];
		if (!dfn[j]) {
			tarjan(j);
			low[x] = min(low[x], low[j]);
		} else if (ins[j]) low[x] = min(low[x], dfn[j]);
	}
	if (dfn[x] == low[x]) {
		scc_cnt++;
		int y;
		do {
			y = stk.top(), ins[y] = 0;
			stk.pop();
			c[y] = scc_cnt, scc[scc_cnt].push_back(y);
		} while (x != y);
	}
}
void tarjan() {
	while (!stk.empty()) stk.pop();
	int u, v;
	rep(i, 1, m) {
		cin >> u >> v;
		add(u, v);
	}
	rep(i, 1, n) if (!dfn[i]) tarjan(i);
	//缩点：
	rep(x, 1, n) for (int i = h[x]; i; i = ne[i]) {
		int y = e[i];
		if (c[x] == c[y]) continue;
		add_c(c[x], c[y]);
	}
}
```



## 字符串

*********

### 字符串匹配

#### KMP算法

```C++
int ne[N];
inline void initKMP(string &p) {
	ne[0] = -1;
	int len = p.length(), i = 0, j = -1;
	while (i < len) if (j == -1 || p[i] == p[j]) ne[++i] = ++j;
	else j = ne[j];
} //p是匹配串，s是文本串
inline void KMP(string &s, string &p) {
	int i = 0, j = 0, n = s.length(), m = p.length();
	initKMP(p);
	while (i < n) {
		if (j == -1 || s[i] == p[j]) i++, j++;
		else j = ne[j];
		if (j == m) {
			//此处添加操作，i - j为匹配起始下标
			j = ne[j];
		}
	}
}
```

#### AC自动机

1.AC自动机是一种**有限状态自动机**（说了等于没说），它常被用于多模式串的字符串匹配。

2.AC自动机是**以Trie的结构为基础**，结合**KMP的思想**建立的。（AC = KMP+ Trie) 但不完全是。

多个模板串匹配文本串输出有多少模板串存在：

```c++
int fail[N], vis[N][30], ba[N], tot = 0;
inline void Insert(string s) {
	int len = s.length(), now = 0;
	rep(i, 0, len - 1) {
		if (!vis[now][s[i] - 'a']) vis[now][s[i] - 'a'] = ++tot;
		now = vis[now][s[i] - 'a'];
	}
	ba[now]++;
}
void Build() {
	queue<int> q;
	rep(i, 0, 25) if (vis[0][i]) fail[vis[0][i]] = 0, q.push(vis[0][i]);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		rep(i, 0, 25) if (vis[u][i]) fail[vis[u][i]] = vis[fail[u]][i], q.push(vis[u][i]);
		else vis[u][i] = vis[fail[u]][i];
	}
}
int find(string s) {
	int len = s.length(), now = 0, rs = 0;
	rep(i, 0, len - 1) {
		now = vis[now][s[i] - 'a'];
		for (int t = now; t && ba[t] != -1; t = fail[t]) rs += ba[t], ba[t] = -1;
	}
	return rs;
}
```

多个模板串在文本串中出现的个数，存储于ans[].num，对应pos为输入pos：

```C++
struct Result {
	int num;
	int pos;
} ans[N];
bool operator< (Result &a, Result &b) {
	if (a.num != b.num) return a.num > b.num;
	else return a.pos < b.pos;
}
string str[N];
int fail[N], vis[N][30], ba[N], tot = 0;
inline void Clean(int x) {
	rep(i, 0, 25) vis[x][i] = 0;
	ba[x] = fail[x] = 0;
}
inline void Insert(string s, int x) {
	int len = s.length(), now = 0;
	rep(i, 0, len - 1) {
		if (!vis[now][s[i] - 'a']) vis[now][s[i] - 'a'] = ++tot, Clean(tot);
		now = vis[now][s[i] - 'a'];
	}
	ba[now] = x;
}
void Build() {
	queue<int> q;
	rep(i, 0, 25) if (vis[0][i]) fail[vis[0][i]] = 0, q.push(vis[0][i]);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		rep(i, 0, 25) if (vis[u][i]) fail[vis[u][i]] = vis[fail[u]][i], q.push(vis[u][i]);
		else vis[u][i] = vis[fail[u]][i];
	}
}
int Find(string s) {
	int len = s.length(), now = 0, rs = 0;
	rep(i, 0, len - 1) {
		now = vis[now][s[i] - 'a'];
		for (int t = now; t; t = fail[t]) ans[ba[t]].num++;
	}
	return rs;
}
```

### 回文串判断

#### Manacher判断回文串

**时间复杂度：**$O(N)$

```C++
int p[2 * N];//将处理后的字符串每个位点看作对称中心，p[]存储对称中心回文串长度+1
char s[2 * N];//存储方式：例如"aba"->"#a#b#a#","abab"->"#a#b#a#b#"
void manacher(string data) {
	int len = data.size();
	rep(i, 1, len) s[i << 1] = data[i - 1], s[(i << 1) | 1] = '#';
	len = (len << 1) | 1, s[0] = '@', s[1] = '#';
	for (int i = 1, r = 0, mid = 0; i <= len; i++) {
		if (i <= r) p[i] = min(p[(mid << 1) - i], r - i + 1);
		while (s[i - p[i]] == s[i + p[i]]) p[i]++;
		if (p[i] + i > r) r = p[i] + i - 1, mid = i;
	}
}
```

### 循环字符串的最小表示法

**最小表示法：** 对于一个字符串S，求S的循环的同构字符串中字典序最小的一个。

```C++
string minCycStr(string &str) {
	int i = 0, j = 1, k = 0;
	int len = str.size();
	while (i < len && j < len && k < len) {
		int t = str[(i + k) % len] - str[(j + k) % len];
		if (t == 0) k++;
		else {
			if (t > 0) i += k + 1;
			else j += k + 1;
			if (i == j) j++;
			k = 0;
		}
	}
	int minPos = i < j ? i : j;
	return str.substr(minPos, len - minPos) + str.substr(0, minPos);
}
```


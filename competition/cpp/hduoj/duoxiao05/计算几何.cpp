#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const db eps= 1e-8;
const db inf=1e20;
const db pi=acos(-1.0);
const int N=1e6+100;
const int maxp=1010;
//double类型判断是否为0
int sgn(db x){
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    return 1;
}
//double 类型平方
db spr(db x){return x*x;}
//二维几何
struct Point{
    db x, y;
    Point(){}
    Point(db x, db y):x(x), y(y){}
    void input(){
        scanf("%lf%lf",&x, &y);//如果为longdouble则需要改为Lf
    }
    // 1.比较两点是否相同
    bool operator == (Point b)const {
        return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
    }
    // 2.按照(x,y)的优先级比较，因题目不同要修改
    bool operator < (Point b)const{
        return sgn(x-b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    // 3.常用，求向量
    Point operator - (const Point &b)const{
        return Point(x - b.x, y - b.y);
    }
    // 4. 叉积
    db operator ^ (const Point &b)const{
        return x * b.y - y * b.x;
    }
    // 5. 点积
    db operator * (const Point &b)const{
        return x * b.x + y * b.y;
    }
    // 6. 返回长度
    db len(){
        return hypot(x, y);
    } 
    // 7. 返回长度平方
    db len2(){
        return x * x + y * y;
    }
    // 8. 返回两点距离 
    db distance(Point p){
        return hypot(x - p.x, y - p.y);
    }
    // 9. 向量加
    Point operator + (const Point &b)const{
        return Point(x + b.x, y + b.y);
    }
    // 10. 标量乘
    Point operator * (const db &k) const {
        return Point(x * k,  y * k);
    }
    // 11. 标量除
    Point operator /(const db &k)const {
        return Point(x / k, y / k);
    }
    // 12.
    // 计算 pa 和 pb 的夹角
    // 就是求这个点看 a，b所成的夹角
    // LightOJ 1203
    db rad(Point a, Point b){
        Point p = *this;
        return fabs(atan2( fabs((a-p)^(b-p)), (a-p) * (b-p) ));
    }
    // 13. 化为长度为 r 的向量
    Point trunc(db r){
        db l = len();
        if(!sgn(l)) return *this;
        r /= l;
        return Point(x*r, y*r);
    }
    // 14. 逆时针旋转90度
    Point rotleft(){
        return Point(-y, x);
    }
    // 15. 顺时针转90度
    Point rotright(){
        return Point(y, -x);
    }
    // 16. 绕点 p 逆时针旋转 angle
    Point rotate(Point p, db angle){
        Point v = (*this) - p;
        db c = cos(angle), s = sin(angle);
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};

struct Line{
    Point s, e;
    Line(){}
    Line(Point s, Point e):s(s),e(e){}
    void input(){
        s.input();
        e.input();
    }
    // 17. 判断直线是否相等
    bool operator == (Line v){
        return (s == v.s) && (e == v.e);
    }
    // 20. 调整直线两点顺序
    void adjust(){
        if(e < s) swap(s, e);
    }
    // 21. 求直线长度
    db length(){
        return s.distance(e);
    }
    // 18. 根据一个点和倾斜角angle确定直线， 0 <= angle < pi
    Line (Point p, db angle){
        s = p;
        if(sgn(angle - pi / 2) == 0){
            e = (s + Point(0, 1));
        }else{
            e = (s + Point(1, tan(angle)));
        }
    }
    // 19. ax + by + c = 0
    Line (db a, db b, db c){
        if(sgn(a) == 0){ //  y = -c / b
            s = Point(0, -c/b);
            e = Point(1, -c/b);
        } else if (sgn(b) == 0){ // x = -c / a
            s = Point(-c/a, 0);
            e = Point(-c/a, 1);
        }else{//(0, -c/b), (1, (-c-a)/b)
            s = Point(0, -c/b);
            e = Point(1, (-c-a)/b);
        }
    }
    // 22. 返回直线倾斜角 0 <= angle < pi
    db angle(){
        db k = atan2(e.y - s.y, e.x - s.x);
        if(sgn(k) < 0) k += pi;
        if(sgn(k - pi) == 0) k -= pi;
        return k;
    }
    /*
            23. 
            点和直线的关系
            1 在左侧
            2 在右侧
            3 在直线上
    */
    int relation(Point p){
        int c = sgn((p-s) ^ (e-s));
        if(c < 0) return 1;
        else if(c > 0) return 2;
        else return 3;
    }
    // 24. 点在线段上的判断，包括端点 第二个判断改为小于表示不包括端点
    bool pointonseg(Point p){
        return sgn((p-s)^(e-s)) == 0 && sgn((p-s) * (p-e)) <= 0;
    }
    // 25. 两向量平行（对应直线平行或重合）
    bool parallel(Line v){
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    /*
            26. 
            两线段相交判断
            2 规范相交
            1 非规范相交
            0 不相交
    */
    int segcrosseg(Line v){
        int d1 = sgn((e - s) ^ (v.s - s));  //v.s 在 线段的哪一侧
        int d2 = sgn((e - s) ^ (v.e - s));  //v.e 在 线段的哪一侧
        int d3 = sgn((v.e - v.s) ^ (s - v.s));  
        int d4 = sgn((v.e - v.s) ^ (e - v.s));
        if((d1^d2) == -2 && (d3^d4) == -2) return 2; // 跨立实验满足 一个是-1一个是1
    
        // 1. v.s在线段上 || v.e 在线段上 || s 在另外一条线段上 || e在另外一条线段上
        return (d1 == 0 &&  sgn((v.s - s) * (v.s - e)) <= 0) ||
            (d2 == 0 && sgn((v.e - s) * (v.e - e)) <= 0) ||
            (d3 == 0 && sgn((s - v.s) * (s - v.e)) <= 0) || 
            (d4 == 0 && sgn((e - v.s) * (e - v.e)) <= 0);
    }
    /*
            27. 
            直线与线段相交判断
            *this line -v seg 
            2 规范相交
            1 非规范相交
            0 不相交
    */
    int linecorssseg(Line v){ // v是线段
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if((d1 ^ d2) == -2) return 2;
        return (d1 == 0 || d2 == 0);
    }
    /*
            28. 
            两直线关系
            0 平行
            1 重合
            2 相交
    */
    int linecrossline(Line v){
        // 如果平行，则看点是否在直线上
        if((*this).parallel(v)) return v.relation(s) == 3;
        return 2;
    }
    /*
            29. 
            求两直线的交点
            要保证两直线不平行或重合
        */
    Point crosspoint(Line v){
        db a1 = (v.e - v.s) ^ (s - v.s);
        db a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    // 30. 点到直线的距离
    db dispointtoline(Point p){
        return fabs((p-s) ^ (e-s)) / length();
    }
    // 31. 点到线段的距离
    db dispointtoseg(Point p){
        if(sgn((p-s)*(e-s)) < 0 || sgn((p-e) * (s-e)) < 0)
            return min(p.distance(s), p.distance(e));
        return dispointtoline(p);
    } 
    /*
            32. 
            返回线段到线段的距离
            前提是两线段不相交，相交距离就是 0 了
    */
    db dissegtoseg(Line v){
        return min(min(dispointtoseg(v.s), dispointtoseg(v.e)), min(v.dispointtoseg(s), v.dispointtoseg(e)));
    }
    /*
            33. 返回 p 在直线上的投影
    */
    Point lineprog(Point p){
        return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
    }
    //  34. 返回点 p 关于直线的对称点
    Point symmetrypoint(Point p){
        Point q = lineprog(p);
        return Point(2*q.x - p.x, 2 * q.y - p.y);
    }
};

struct circle{
    Point p;
    db r;
    circle(){}
    circle(Point p, db r):p(p), r(r){}
    void input(){
        p.input();
        scanf("%lf", &r);
    }
    // 通过圆心角确定圆上的一个点
    Point point(double a){
        return Point(p.x + cos(a) * r, p.y + sin(a) * r);
    }
    bool operator == (circle v){
        return (p == v.p) && sgn(r - v.r) == 0;
    }
    bool operator < (circle v)const{
        return ((p<v.p) || (p == v.p) && sgn(r - v.r) < 0);
    }
    // 面积
    db area(){
        return pi * r * r;
    }
    // 周长
    db circumference(){
        return 2 * pi * r;
    }
    /*
            三角形的外接圆
            需要Point 的 + / rotate() 以及 Line 的crosspoint()
            利用两条边的中垂线得到圆心
            UVA 12304
    */
    circle(Point a, Point b, Point c){
        Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft()));
        Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft()));
        p = u.crosspoint(v);
        r = p.distance(a);
    }
    /*
            三角形的内切圆
            bool t 没有作用，只是为了和上面外接圆函数区别
            UVA 12304
    */
    circle(Point a, Point b, Point c, bool t){
        Line u, v;
        // u 为角 a 的平分线
        db m  = atan2(b.y-a.y, b.x-a.x), n = atan2(c.y - a.y, c.x - a.x);
        u.s = a;
        u.e = u.s + Point(cos((n+m)/2), sin((n+m)/2));
        // v 为角 b 的平分线
        m = atan2(a.y-b.y, a.x-b.x), n = atan2(c.y-b.y, c.x-b.x);
        v.s = b;
        v.e = v.s + Point(cos((n+m)/2), sin((n+m)/2));
        p = u.crosspoint(v);
        r = Line(a,b).dispointtoseg(p);
    }
    /*
            点和圆的关系
            0 圆外
            1 圆上
            2 圆内
    */
    int relation(Point b){
        db dst = b.distance(p);
        if(sgn(dst - r) < 0) return 2;
        else if(sgn(dst - r) == 0) return 1;
        return 0;
    }
    /*
            线段和圆的关系
            比较的是圆心到线段的距离和半径的关系
            2 交
            1 切
            0 不交
    */
    int relationseg(Line v){
        db dst = v.dispointtoseg(p);
        if(sgn(dst - r) < 0) return 2;
        else if(sgn(dst - r) == 0) return 1;
        return 0;
    }
    int relationline(Line v){
        db dst = v.dispointtoline(p);
        if(sgn(dst - r) < 0) return 2;
        else if(sgn(dst - r) == 0) return 1;
        return 0;
    }
    /*
            两圆的关系
            5 相离
            4 外切
            3 相交
            2 内切
            1 内含
    */
    int relationcircle(circle v){
        db d = p.distance(v.p);
        if(sgn(d - r - v.r) > 0) return 5;
        if(sgn(d - r - v.r) == 0) return 4;
        db l = fabs(r - v.r);
        if(sgn(d - r - v.r) < 0 && sgn(d - l) > 0) return 3;
        if(sgn(d - l) == 0) return 2;
        if(sgn(d - l) < 0) return 1;
    }
    /*
            求两个圆的交点，返回0表示没有交点，返回1是一个交点，2是两个交点
    */
    int pointcrosscircle(circle v, Point &p1, Point &p2){
        int rel = relationcircle(v);
        if(rel == 1 || rel == 5) return 0;
        db d = p.distance(v.p);
        db l = (d * d + r * r - v.r * v.r) / (2 * d);
        db h = sqrt(r * r - l * l);
        Point tmp = p + (v.p - p).trunc(l);
        p1 = tmp + ((v.p - p).rotleft().trunc(h));
        p2 = tmp + ((v.p - p).rotright().trunc(h));
        if(rel == 2 || rel == 4)return 1;
        return 2;
    }
    // 求直线与圆的交点，返回交点个数
    int pointcrossline(Line v, Point &p1, Point &p2){
        if(!(*this).relationline(v)) return 0;
        Point a = v.lineprog(p);
        db d = v.dispointtoline(p);
        d = sqrt(r * r - d * d);
        if(sgn(d) == 0){
            p1 = a;
            p2 = a;
            return 1;
        }
        p1 = a + (v.e - v.s).trunc(d);
        p2 = a - (v.e - v.s).trunc(d);
        return 2;
    }
    // 得到 通过a，b两点，半径为r1的两个圆
    int getcircle(Point a, Point b, db r1, circle &c1, circle &c2){
        circle x(a, r1), y(b, r1);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if(!t) return 0;
        c1.r = c2.r = r;
        return t;
    }
    // 得到与直线 u 相切，过点 q， 半径为 r1 的圆
    int getcircle(Line u, Point q, db r1, circle &c1, circle &c2){
        db dis = u.dispointtoline(q);
        if(sgn(dis - r1 * 2) > 0) return 0;
        if(sgn(dis) == 0){
            c1.p = q + ((u.e - u.s).rotleft().trunc(r1));
            c2.p = q + ((u.e - u.s).rotright().trunc(r1));
            c1.r = c2.r = r1;
            return 2;
        }
        Line u1 = Line((u.s + (u.e - u.s).rotleft().trunc(r1)), (u.e + (u.e - u.s).rotleft().trunc(r1)));
        Line u2 = Line((u.s + (u.e - u.s).rotright().trunc(r1)), (u.e + (u.e - u.s).rotright().trunc(r1)));
        circle cc = circle(q, r1);
        Point p1, p2;
        if(!cc.pointcrossline(u1, p1, p2)) cc.pointcrossline(u2, p1, p2);
        c1 = circle(p1, r1);
        if(p1 == p2){
            c2 = c1;
            return 1;
        }
        c2 = circle(p2, r1);
        return 2;
    }
    // 同时与直线u，v相切，半径为r1的圆 , u,v不平行
    int getcircle(Line u, Line v, db r1, circle &c1, circle &c2, circle &c3, circle &c4){
        if(u.parallel(v)) return 0;
        Line u1 = Line(u.s + (u.e - u.s).rotleft().trunc(r1), u.e + (u.e - u.s).rotleft().trunc(r1));
        Line u2 = Line(u.s + (u.e - u.s).rotright().trunc(r1), u.e + (u.e - u.s).rotright().trunc(r1));
        Line v1 = Line(v.s + (v.e - v.s).rotleft().trunc(r1), v.e + (v.e - v.s).rotright().trunc(r1));
        Line v2 = Line(v.s + (v.e - v.s).rotright().trunc(r1), v.e + (v.e - v.s).rotright().trunc(r1));
    
        c1.r = c2.r = c3.r = c4.r = r1;
        c1.p = u1.crosspoint(v1);
        c2.p = u1.crosspoint(v2);
        c3.p = u2.crosspoint(v1);
        c4.p = u2.crosspoint(v2);
        return 4;
    }
    // 同时与不相交圆 cx, cy 相切，半径为r1的圆
    int getcircle(circle cx, circle cy, db r1, circle &c1, circle &c2){
        circle x(cx.p, r1+cx.r), y(cy.p, r1+cy.r);
        int t = x.pointcrosscircle(y, c1.p, c2.p);
        if(!t) return 0;
        c1.r = c2.r = r1;
        return t;
    }
    // 过一点作圆的切线 (先判断点和圆的关系)
    int tangentline(Point q, Line &u, Line &v){
        int x = relation(q);
        if(x == 2) return 0; //圆内
        if(x == 1){ //圆上
            u = Line(q, q+(q-p).rotleft());
            v = u;
            return 1;
        }
        db d = p.distance(q);
        db l = r * r / d;
        db h = sqrt(r * r - l * l);
        u = Line(q, p + ((q - p).trunc(l) + (q-p).rotleft().trunc(h)));
        v = Line(q, p + (q - p).trunc(l) + (q - p).rotright().trunc(h));
        return 2;
    }
    // 求两圆相交的面积
    db areacircle(circle v){
        int rel = relationcircle(v);
        if(rel >= 4) return 0.0;
        if(rel <= 2) return min(area(), v.area()); //内部
        db d = p.distance(v.p);
        db hf = (r + v.r + d) / 2.0;
        db ss = 2 * sqrt(hf*(hf - r) * (hf - v.r) * (hf - d));
        db a1 = acos((r * r + d * d - v.r * v.r) / (2.0 * r * d));
        a1 = a1 * r * r;
        db a2 = acos((v.r * v.r + d * d - r * r) / (2.0 * v.r * d));
        a2 = a2 * v.r * v.r;
        return a1 + a2 - ss;
    }
    // 求圆和三角形 pab 的相交面积
    // POJ3675 HDU3982 HDU2892
    db areatriangle(Point a, Point b){
        if(sgn((p-a)^(p-b)) == 0)return 0.0;
        Point q[5];
        int len = 0;
        q[len++] = a;
        Line l(a, b);
        Point p1, p2;
        if(pointcrossline(l, q[1], q[2]) == 2){
            if(sgn((a-q[1]) * (b-q[1])) < 0) q[len++] = q[1];
            if(sgn((a-q[2]) * (b-q[2])) < 0) q[len++] = q[2];
        }
        q[len++] = b;
        if(len == 4 && sgn((q[0] - q[1]) * (q[2] - q[1])) > 0) swap(q[1], q[2]);
        db res = 0;
        for(int i=0;i<len-1;i++){
            if(relation(q[i]) == 0 || relation(q[i+1]) == 0){
                db arg = p.rad(q[i], q[i+1]);
                res += r * r * arg / 2.0;
            }else{
                res += fabs((q[i] - p) ^ (q[i+1] - p)) / 2.0;
            }
        }
        return res;
    }

};

// a[i] 存放第 i 条公切线与 圆A 的交点
// int getTangents(circle A, circle B, Point*a, Point *b){//求两个圆的公切线
//     int cnt = 0;
//     // 以A为半径更大的那个圆进行计算
//     if(A.r < B.r) return getTangents(B, A, b, a);
//     db d2 = (A.p-B.p).len2();  // 圆心距平方
//     db rdiff = A.r - B.r;		// 半径差
//     db rsum = A.r + B.r;		//半径和
//     if(d2 < rdiff * rdiff) return 0; 	// 情况1，内含,没有公切线
//     Vector AB = B.p - A.p;				// 向量AB，其模对应圆心距
//     db base = atan2(AB.y, AB.x);		// 求出向量AB对应的极角
//     if(d2 == 0 && A.r == B.r) return -1;// 情况3，两个圆重合，无限多切线
//     if(d2 == rdiff * rdiff){ 			// 情况2，内切，有一条公切线
//         a[cnt] = A.point(base);			
//         b[cnt] = B.point(base);cnt++;
//         return 1;
//     }
//     // 求外公切线
//     db ang = acos((A.r - B.r) / sqrt(d2)); //求阿尔法
//     // 两条外公切线
//     a[cnt] = A.point(base+ang); b[cnt] = B.point(base+ang); cnt++;
//     a[cnt] = A.point(base-ang); b[cnt] = B.point(base-ang); cnt++;
//     if(d2 == rsum * rsum){  // 情况5，外切，if里面求出内公切线
//         a[cnt] = A.point(base); b[cnt] = B.point(pi+base); cnt++;
//     }
//     else if(d2 > rsum * rsum){	//情况6，相离，再求出内公切线
//         db ang = acos((A.r + B.r) / sqrt(d2));
//         a[cnt] = A.point(base + ang); b[cnt] = B.point(pi+base+ang);cnt++;
//         a[cnt] = A.point(base - ang); b[cnt] = B.point(pi+base-ang);cnt++;
//     }
//     // 此时，d2 < rsum * rsum 代表情况 4 只有两条外公切线
//     return cnt;
// }

//求圆的并
struct circles{
    circle c[N];
    double ans[N];
    double pre[N];
    int n;
    circles(){}
    void add(circle cc){
        c[n++] = cc;
    }
    // x 包含在 y 中
    bool inner(circle x, circle y){
        if(x.relationcircle(y) != 1) return 0;
        return sgn(x.r - y.r) <= 0 ? 1 : 0;
    }
    double areaarc(double th, double r){
        return 0.5 * r * r * (th - sin(th));
    }
    // 圆的面积并，去掉内含的圆
    void init_or(){
        int i, j, k = 0;
        bool mark[N] = {0};
        for(i = 0; i < n; i++){
            for(j = 0; j < n;j ++){
                if(i != j && !mark[j]){
                    if((c[i] == c[j]) || inner(c[i], c[j])) break;
                }
            }
            if(j < n) mark[i] = 1;
        }
        for(i = 0; i < n; i++){
            if(!mark[i]){
                c[k++] = c[i];
            }
        }
        n = k;
    }
    // 圆的面积交，去掉内含的圆
    void init_and(){
        int i, j, k = 0;
        bool mark[N] = {0};
        for(i = 0; i < n; i++){
            for(j = 0; j < n;j ++){
                if(i != j && !mark[j]){
                    if((c[i] == c[j]) || inner(c[j], c[i])) break;
                }
            }
            if(j < n) mark[i] = 1;
        }
        for(i = 0; i < n; i++){
            if(!mark[i]){
                c[k++] = c[i];
            }
        }
        n = k;
    }
    void getarea(){
        memset(ans, 0, sizeof ans);
        vector<pair<double,int> > v;
        for(int i=0;i<n;i++){
            v.clear();
            v.push_back(make_pair(-pi, 1));
            v.push_back(make_pair(pi, -1));   
            for(int j=0;j<n;j++){
                if(i != j){
                    Point q = (c[j].p - c[i].p);
                    db ab = q.len(), ac = c[i].r, bc = c[j].r;
                    if(sgn(ab + ac - bc) <= 0){
                        v.push_back(make_pair(-pi, 1));
                        v.push_back(make_pair(pi, -1));
                        continue;
                    }
                    if(sgn(ab + bc - ac) <= 0) continue;
                    if(sgn(ab - ac - bc) > 0) continue;
                    double th = atan2(q.y, q.x), fai = acos((ac*ac + ab * ab - bc * bc) / (2.0*ac*ab));
                    double a0 = th - fai;
                    if(sgn(a0 + pi) < 0) a0 += 2 * pi;
                    db a1 = th + fai;
                    if(sgn(a1 - pi) > 0) a1 -= 2 * pi;
                    if(sgn(a0 - a1) > 0){
                        v.push_back(make_pair(a0, 1));
                        v.push_back(make_pair(pi, -1));
                        v.push_back(make_pair(-pi, 1));
                        v.push_back(make_pair(a1, -1));
                    }
                    else {
                        v.push_back(make_pair(a0, 1));
                        v.push_back(make_pair(a1, -1));
                    }
                }
            }
            sort(v.begin(),v.end());
            int cur = 0;
            for(int j=0;j<v.size();j++){
                if(cur && sgn(v[j].first - pre[cur])){
                    ans[cur] += areaarc(v[j].first - pre[cur], c[i].r);
                    ans[cur] += 0.5 * (c[i].point(pre[cur])^c[i].point(v[j].first));
                }
                cur += v[j].second;
                pre[cur] = v[j].first;
            }
        }
    }
}cs;

//多边形
struct polygon{
    int n;
    Point p[maxp];
    Line l[maxp];
    void input(int n){
        this->n=n;
        for(int i=0;i<n;i++) p[i].input();
    }
    // 得到所有边
    void getline(){
        for(int i=0;i<n;i++){
            l[i] = Line(p[i],p[(i+1)%n]);
        }
    }
    // 以 p0 为标准极角排序
    struct cmp{
        Point p;
        cmp(const Point &p0){p = p0;}
        bool operator()(const Point &aa, const Point &bb){
            Point a = aa, b = bb;
            int d = sgn((a-p)^(b-p));
            if(d == 0){
                return sgn(a.distance(p) - b.distance(p)) < 0;
            }
            return d > 0;
        }
    };
    /*
            进行极角排序
            首先找打最左下角的点
            需要重载好Point的 < 操作符
    */
    void norm(){
        Point mi = p[0];
        for(int i=1;i<n;i++) mi = min(mi, p[i]);
        sort(p, p+n, cmp(mi));
    }
    // 得到周长
    db getcircumference(){
        db sum = 0;
        for(int i=0;i<n;i++){
            sum += p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
    // 得到面积
    db getarea(){
        db sum = 0;
        // 以原点为划分点
        for(int i=0;i<n;i++){
            sum += (p[i]^p[(i+1)%n]);
        }
        return fabs(sum)/2;
    }
    // 得到方向，1 表示逆时针，0表示顺时针
    bool getdir(){
        db sum = 0;
        for(int i=0;i<n;i++){
            sum += (p[i] ^ p[(i+1)%n]);
        }
        if(sgn(sum) > 0) return 1;
        return 0;
    }
    // 得到重心
    Point getbarycentre(){
        Point ret(0,0);
        db area = 0;
        for(int i=1;i<n-1;i++){
            db tmp = (p[i]-p[0])^(p[i+1]-p[0]);
            if(sgn(tmp) == 0) continue;
            area += tmp;
            ret.x += (p[0].x + p[i].x + p[i+1].x) / 3 * tmp;
            ret.y += (p[0].y + p[i].y + p[i+1].y) / 3 * tmp;
        }
        if(sgn(area)) ret = ret / area;
        return ret;
    }
    /*
        得到凸包 凸包点编号0 ~ n-1
    */
    void getconvex(polygon &convex){
        sort(p, p+n);
        convex.n = n;
        for(int i=0;i<min(n, 2);i++){
            convex.p[i] = p[i];
        }
        if(convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n --;
        if(n <= 2) return;
        int &top = convex.n;
        top = 1;
        for(int i=2;i<n;i++){
            while(top && sgn((convex.p[top] - p[i]) ^ (convex.p[top-1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        int temp = top;
        convex.p[++top] = p[n-2];
        for(int i=n-3;i>=0;i--){
            while(top != temp && sgn((convex.p[top] - p[i]) ^ (convex.p[top-1] - p[i])) <= 0)
                top--;
            convex.p[++top] = p[i];
        }
        if(convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n --;
        convex.norm();
    }
    void Graham(polygon &convex){
        norm();
        int &top = convex.n;
        top = 0;
        if(n == 1){
            top = 1;
            convex.p[0] = p[0];
            return ;
        }
        if(n == 2){
            top = 2;
            convex.p[0] = p[0];
            convex.p[1] = p[1];
            if(convex.p[0] == convex.p[1]) top--;
            return;
        }
        convex.p[0] = p[0];
        convex.p[1] = p[1];
        top = 2;
        for(int i=2;i<n;i++){
            while(top > 1 && sgn((convex.p[top-1] - convex.p[top-2]) ^ (p[i]-convex.p[top-2])) <= 0) 
                top--;
            convex.p[top++] = p[i];
        }
        if(convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--;
    }
    // 判断是不是凸的
    bool isconvex(){
        bool s[3];
        memset(s, false, sizeof s);
        for(int i=0;i<n;i++){
            int j = (i + 1) % n;
            int k = (j + 1) % n;
            s[sgn((p[j] - p[i]) ^ (p[k] - p[i])) + 1] = true;
            if(s[0] && s[2]) return false;
        }
        return true;
    }
    /*
            判断点和任意多边形的关系
            3 点上
            2 边上
            1 内部
            0 外部
    */
    int relationpoint(Point q){
        for(int i=0;i<n;i++){
            if(p[i] == q) return 3; 
        }
        getline();
        for(int i=0;i<n;i++){
            if(l[i].pointonseg(q)) return 2;
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            int j = (i + 1) % n;
            int k = sgn((q-p[j])^(p[i]-p[j]));
            int u = sgn(p[i].y - q.y);
            int v = sgn(p[j].y - q.y);
            if(k > 0 && u < 0 && v >= 0) cnt ++;
            if(k < 0 && v < 0 && u >= 0) cnt --;
        }
        return cnt != 0;
    }
    //直线 u 切割凸多边形左侧
    //注意直线方向
    //HDU3982
    
    void convexcut(Line u, polygon &po){
        int &top = po.n;
        top = 0;
        for(int i=0;i<n;i++){
            int d1 = sgn((u.e-u.s)^(p[i]-u.s));
            int d2 = sgn((u.e-u.s)^(p[(i+1)%n]-u.s));
            if(d1 >= 0) po.p[top++] = p[i];
            if(d1 * d2 < 0) po.p[top++] = u.crosspoint(Line(p[i], p[(i+1)%n]));
        }
    }
    // 多边形和圆交的面积
    db areacircle(circle c){
        db ans = 0;
        for(int i=0;i<n;i++){
            int j = (i + 1) % n;
            if(sgn((p[j]-c.p)^(p[i]-c.p)) >= 0)
                ans += c.areatriangle(p[i], p[j]);
            else ans -= c.areatriangle(p[i], p[j]);
        }
        return fabs(ans);
    }
    /*
            多边形与圆的关系
            2. 圆完全在多边形内
            1. 圆在多边形里面，碰到了多边形边界
            0. 其他
    */
    db relationcircle(circle c){
        getline();
        int x = 2;
        if(relationpoint(c.p) != 1) return 0; // 圆心不在内部
        for(int i=0;i<n;i++){
            if(c.relationseg(l[i]) == 2) return 0;
            if(c.relationseg(l[i]) == 1) x = 1; // 相切
        }
        return x;
    }
    db minRectangleCover(){
        if(n < 3) return 0.0;
        p[n] = p[0];
        db ans = -1;
        int up = 1, r = 1, l;
        for(int i=0;i<n;i++){
            Point vec = p[i+1] - p[i];
            while(sgn( (vec^(p[up+1]-p[i])) - (vec^(p[up]-p[i])) ) >= 0)
                up = (up + 1) % n;
            while(sgn( (vec*(p[r+1]-p[i])) - (vec * (p[r]-p[i])) ) >= 0)
                r = (r + 1) % n;
            if(i == 0) l = r;
            while(sgn( (vec*(p[l+1]-p[i])) - (vec * (p[l]-p[i])) ) <= 0)
                l = (l + 1) % n;
    
            db d = (p[i] - p[i+1]).len2();
            db tmp = (vec^(p[up]-p[i])) * ( (vec*(p[r]-p[i])) - (vec *(p[l]-p[i]))) / d;
            if(ans < 0 || ans > tmp) ans = tmp;
        }
        return ans;
    }
    // 最远的一对点的距离
    db diameter(){
        if(n == 2) return p[0].distance(p[1]);
        int i = 0, j = 0;
        for(int k=0;k<n;k++){
            if(p[i] < p[k]) i = k;
            if(!(p[j] < p[k])) j = k;
        }
        int si = i, sj = j;
        db res = 0;
        while(i != sj || j != si){
            res = max(res, p[i].distance(p[j]));
            int ni = (i+1)%n;
            int nj = (j+1)%n;
            if(sgn((p[ni]-p[i])^(p[nj]-p[j])) <= 0){
                i = ni;
            } else j = nj;
        }
        return res;
    }
};

int main(){
    //code
    return 0;
}


#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <stack>
#include <vector>
#define rep(i, j, k) for (int i = int(j); i <= int(k); i++)
const int N = 1e3 + 7;

struct krskEdge {
    int a, b, w;
    bool operator<(const krskEdge& W) const { return w < W.w; }
};

struct Edge {
    int idx;
    int weight;
    Edge* next;
};

template <class T>
struct Node {
    T node;
    Edge* first;
};

template <class T>
class Graph {
   public:
    Graph();
    ~Graph();
    void dfs(T s);
    void bfs(T s);
    std::vector<std::vector<int>> G2G();
    std::vector<krskEdge> initKruskal();
    std::vector<std::pair<int, int>> getSonNode(int x);
    int getNodeId(T s) { return this->mp[s]; }
    int getNodeNum() { return this->nodeNum; }
    int getEdgeNum() { return this->edgeNum; }
    T getIdNode(int x) { return this->adjList[x].node; }

   private:
    Node<T> adjList[N];
    std::map<T, int> mp;
    int nodeNum, edgeNum;
};

template <class T>
Graph<T>::Graph() {
    T u, v;
    int w;
    std::cin >> nodeNum >> edgeNum;
    rep(i, 0, this->nodeNum - 1) {
        std::cin >> adjList[i].node;
        mp[adjList[i].node] = i;
        this->adjList[i].first = nullptr;
    }
    rep(i, 0, this->edgeNum - 1) {
        std::cin >> u >> v >> w;
        Edge* now = new Edge;
        now->idx = mp[v];
        now->weight = w;
        now->next = adjList[mp[u]].first;
        adjList[mp[u]].first = now;
        now = new Edge;
        now->idx = mp[u];
        now->weight = w;
        now->next = adjList[mp[v]].first;
        adjList[mp[v]].first = now;
    }
    edgeNum *= 2;
}

template <class T>
Graph<T>::~Graph() {
    rep(i, 0, this->nodeNum) {
        Edge* p = adjList[i].first;
        while (p) {
            Edge* q = p;
            p = p->next;
            delete q;
        }
    }
}

template <class T>
void Graph<T>::dfs(T ss) {
    std::vector<bool> st(N, false);
    int s = mp[ss];
    std::stack<int> stk;
    std::cout << adjList[s].node << ' ';
    st[s] = true;
    stk.push(s);
    while (!stk.empty()) {
        s = stk.top();
        Edge* p = adjList[s].first;
        while (p && st[p->idx]) p = p->next;
        if (p) {
            s = p->idx;
            std::cout << adjList[s].node << ' ';
            st[s] = true;
            stk.push(s);
        } else stk.pop();
    }
}

template <class T>
void Graph<T>::bfs(T ss) {
    int s = mp[ss];
    std::vector<bool> st(N, false);
    std::queue<int> q;
    std::cout << this->adjList[s].node << ' ';
    st[s] = true;
    q.push(s);
    while (!q.empty()) {
        s = q.front();
        Edge* p = this->adjList[s].first;
        q.pop();
        while (p) {
            if (!st[p->idx]) {
                st[p->idx] = true;
                std::cout << this->adjList[p->idx].node << ' ';
                q.push(p->idx);
            }
            p = p->next;
        }
    }
}

template <class T>
std::vector<std::vector<int>> Graph<T>::G2G() {
    std::vector<std::vector<int>> G(this->nodeNum, std::vector<int>(this->nodeNum, -1));
    rep(i, 0, this->nodeNum - 1) {
        Edge* p = adjList[i].first;
        while (p) {
            int v = p->idx;
            G[i][v] = p->weight;
            p = p->next;
        }
    }
    return G;
}

template <class T>
int prim(Graph<T>& g) {
    std::vector<std::vector<int>> G = g.G2G();
    std::vector<int> dist(g.getNodeNum(), 0x3f3f3f3f);
    std::vector<bool> st(g.getNodeNum(), false);
    int rs = 0;
    rep(i, 0, g.getNodeNum() - 1) {
        int t = -1;
        rep(j, 0, g.getNodeNum() - 1) if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if (i) rs += dist[t];
        st[t] = true;
        rep(j, 0, g.getNodeNum() - 1) dist[j] = std::min(dist[j], G[t][j]);
    }
    std::cout << "Sum of Edge Weights of Minimum Spanning Tree: \n" << rs << '\n';
    return rs;
}

template <class T>
std::vector<krskEdge> Graph<T>::initKruskal() {
    std::vector<krskEdge> krskEdges(this->edgeNum);
    int cnt = 0;
    rep(i, 0, this->nodeNum - 1) {
        Edge* p = this->adjList[i].first;
        while (p) {
            krskEdges[cnt].a = i;
            krskEdges[cnt].b = p->idx;
            krskEdges[cnt++].w = p->weight;
            p = p->next;
        }
    }
    return krskEdges;
}

template <class T>
std::vector<std::pair<int, int>> Graph<T>::getSonNode(int x) {
    std::vector<std::pair<int, int>> vec;
    Edge* p = this->adjList[x].first;
    while (p) {
        vec.push_back({p->idx, p->weight});
        p = p->next;
    }
    return vec;
}

int find(int x, std::vector<int>& p) { return p[x] == x ? x : p[x] = find(p[x], p); }
template <class T>
int kruskal(Graph<T>& g) {
    std::vector<krskEdge> krskEdges = g.initKruskal();
    std::vector<int> p(g.getNodeNum());
    int rs = 0, cnt = 0;
    std::sort(krskEdges.begin(), krskEdges.end());
    rep(i, 0, g.getNodeNum() - 1) p[i] = i;
    rep(i, 0, g.getEdgeNum() - 1) {
        int a = find(krskEdges[i].a, p), b = find(krskEdges[i].b, p), w = krskEdges[i].w;
        if (a != b) { p[a] = b, rs += w, cnt++; }
    }
    std::cout << "Sum of Edge Weights of Minimum Spanning Tree: \n" << rs << '\n';
    if (cnt < g.getNodeNum() - 1) return 0x3f3f3f3f;
    else return rs;
}

template <class T>
void dijkstra(Graph<T>& g, T s) {
    std::vector<bool> st(g.getNodeNum(), false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;
    std::vector<int> dist(g.getNodeNum(), 0x3f3f3f3f);
    std::vector<int> rs[g.getNodeNum()];
    dist[g.getNodeId(s)] = 0, heap.push({0, g.getNodeId(s)});
    while (!heap.empty()) {
        auto [d, v] = heap.top();
        heap.pop();
        if (st[v]) continue;
        st[v] = true;
        std::vector<std::pair<int, int>> vec = g.getSonNode(v);
        for (auto& son : vec) {
            int j = son.first, w = son.second;
            if (dist[j] > dist[v] + w) dist[j] = dist[v] + w, heap.push({dist[j], j});
        }
    }
    std::cout << "Shortest path: \n";
    rep(i, 0, g.getNodeNum() - 1) std::cout << s << "->" << g.getIdNode(i) << ": " << dist[i] << '\n';
}

int main() {
    Graph<std::string> g;
    prim<std::string>(g);
    kruskal<std::string>(g);
    dijkstra<std::string>(g, "Pe");

    puts("");
    puts("");
    puts("");
    puts("");
    system("pause");
}

/*
6 15
Pe N Pa L T M
Pe N 109
Pe Pa 82
Pe L 81
Pe T 21
Pe M 124
N Pa 58
N L 55
N T 108
N M 32
Pa L 3
Pa T 97
Pa M 92
L T 95
L M 89
T M 113
*/

/*
9 11
0 1 99
1 3 99
3 7 99
7 8 99
1 4 99
4 7 00
4 5 99
0 2 99
2 5 99
5 6 99
6 8 99
*/
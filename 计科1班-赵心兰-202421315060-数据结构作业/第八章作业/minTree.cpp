#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MaxVertexNum 100
#define INF 99999999
//图的邻接矩阵结构
struct Graph
{
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexnum;
};
//并查集（用于kruskal）
struct UnionFind
{
    int parent[MaxVertexNum];
    void init(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    bool unionSet(int x,int y)
    {
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY)
        {
           parent[rootX]=rootY;
           return true;
        }
        return false;
    }
};
// 边结构体（用于 Kruskal）
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
};

// 比较函数：按权重排序
bool cmp(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal 算法
void Kruskal(Graph G) {
    vector<Edge> edges;
    int count = 0;

    // 构建所有边（忽略自环和权重为0的边）
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = i + 1; j < G.vexnum; j++) {
            if (G.Edge[i][j] > 0) {
                edges.push_back(Edge(i, j, G.Edge[i][j]));
            }
        }
    }

    // 按权重排序
    sort(edges.begin(), edges.end(), cmp);

    UnionFind uf;
    uf.init(G.vexnum);

    cout << "Kruskal 最小生成树结果: ";
    for (auto e : edges) {
        if (uf.unionSet(e.u, e.v)) {
            cout << "(" << e.u << "," << e.v << ") ";
            count++;
            if (count == G.vexnum - 1) break;
        }
    }
    cout << endl;
}

// Prim 算法
void Prim(Graph G) {
    int lowcost[MaxVertexNum]; // 记录每个顶点到当前生成树的最小边权
    int closest[MaxVertexNum]; // 记录该顶点连接到生成树的最近顶点
    bool visited[MaxVertexNum]; // 是否已加入生成树

    // 初始化
    for (int i = 0; i < G.vexnum; i++) {
        lowcost[i] = INF;
        closest[i] = 0;
        visited[i] = false;
    }

    // 从顶点 0 开始
    lowcost[0] = 0;

    cout << "Prim 最小生成树结果: ";
    for (int i = 0; i < G.vexnum - 1; i++) {
        // 找到未访问的、lowcost 最小的顶点
        int u = -1;
        for (int j = 0; j < G.vexnum; j++) {
            if (!visited[j] && (u == -1 || lowcost[j] < lowcost[u])) {
                u = j;
            }
        }

        visited[u] = true;

        // 输出边 (closest[u], u)
        if (u != 0) {
            cout << "(" << closest[u] << "," << u << ") ";
        }

        // 更新其他顶点的 lowcost 和 closest
        for (int v = 0; v < G.vexnum; v++) {
            if (!visited[v] && G.Edge[u][v] > 0 && G.Edge[u][v] < lowcost[v]) {
                lowcost[v] = G.Edge[u][v];
                closest[v] = u;
            }
        }
    }
    cout << endl;
}

// 主函数
int main() {
    int n;
    while (cin >> n && n != -1) {
        Graph G;
        G.vexnum = n;

        // 输入邻接矩阵
        cout << "请输入邻接矩阵（每行" << n << "个整数）：" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> G.Edge[i][j];
            }
        }

        // 调用 Kruskal 算法
        Kruskal(G);

        // 调用 Prim 算法
        Prim(G);
    }

    return 0;
}

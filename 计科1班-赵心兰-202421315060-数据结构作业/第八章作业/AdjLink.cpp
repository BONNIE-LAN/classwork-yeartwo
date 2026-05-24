#include<iostream>
#include<queue>
using namespace std;
#define MaxVertexNum 100
//邻接表的边结点
struct ArcNode
{
    int adjvex; //邻接点的序号
    ArcNode *nextarc; //指向下一个邻接点的指针
};
//邻接表的顶点结点
struct VNode
{
    ArcNode* firstarc;//指向第一个邻接点的指针
};
//图的邻接表结构
struct Graph
{
    VNode vertices[MaxVertexNum];//顶点数组
    int vexnum;//顶点数
};
//访问标记数组
bool visited[MaxVertexNum];
//创建邻接表
void CreateGraph(Graph& G)
{
    cout<<"Please enter every vertex's adjvertex(end with -1): "<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        int adj;
        cin>>adj;
        ArcNode* p=nullptr;
        while(adj!=-1)
        {
            p=new ArcNode;
            p->adjvex=adj;
            p->nextarc=G.vertices[i].firstarc;
            G.vertices[i].firstarc=p;
            cin>>adj;
        }
    }
}
//广度优先遍历
void BFS(Graph G,int start)
{
    queue<int> Q;
    Q.push(start);
    visited[start]=true;
    cout<<start<<" ";
    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();
        //遍历v的所有邻接点
        ArcNode* p=G.vertices[v].firstarc;
        while(p!=nullptr)
        {
            int w=p->adjvex;
            if(!visited[w])
            {
                cout<<w<<" ";
                visited[w]=true;
                Q.push(w);
            }
            p=p->nextarc;
        }
    }
}
//深度优先遍历
void DFS(Graph G,int v)
{
    visited[v]=true;
    cout<<v<<" ";
    //遍历v的所有邻接点
    ArcNode* p=G.vertices[v].firstarc;
    while(p!=nullptr)
    {
        int w=p->adjvex;
        if(!visited[w])
        {
            DFS(G,w);
        }
        p=p->nextarc;
    }
}
int main() 
{
    int n;
    while (cin >> n && n != -1) {
        Graph G;
        G.vexnum = n;

        // 初始化所有顶点的 firstarc 为 nullptr
        for (int i = 0; i < n; i++) {
            G.vertices[i].firstarc = nullptr;
        }

        // 构建邻接表
        CreateGraph(G);

        // 输入出发点
        int start;
        cout <<"Please enter the vertex you went to begin: ";
        cin >> start;

        // 初始化访问数组
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        // 输出 BFS 结果
        cout << "The BFS traverse results: ";
        BFS(G, start);
        cout << endl;

        // 重置访问数组
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        // 输出 DFS 结果
        cout << "The DFS traverse results: ";
        DFS(G, start);
        cout << endl;
    }
    return 0;
}
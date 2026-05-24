#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define MaxVertexNum 100
bool visited[MaxVertexNum];//访问标记数组
// 字符到索引的映射（用于查找某个字符对应的下标）
map<char, int> charToIndex;
struct Graph
{
    char vex[MaxVertexNum];//顶点表
    int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵
    int vexnum,arcnum;//当前顶点数和边数
};
void BFS(Graph G,int start)
{
    queue<int> Q;
    Q.push(start);
    visited[start]=true;
    cout<<G.vex[start]<<" ";
    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();
        //遍历所有未访问的邻接顶点
        for(int w=0;w<G.vexnum;w++)
        {
            if(G.Edge[v][w]==1&&!visited[w])
            {
                cout<<G.vex[w]<<" ";
                visited[w]=true;
                Q.push(w);
            }
        }
    }
}
void DFS(Graph G,int v)
{
    cout<<G.vex[v]<<" ";
    visited[v]=true;
    for(int w=0;w<G.vexnum;w++)
    {
        if(G.Edge[v][w]==1&&!visited[w])
        {
            DFS(G,w);
        }
    }
}
int main()
{
    int n;
    cout<<"Please enter the number of vertex in the Graph"<<endl;
    while(cin>>n&&n!=-1)
    {
        Graph G;
        G.vexnum=n;
        cout<<"Please enter the vertex in the Graph"<<endl;
        for(int i=0;i<G.vexnum;i++)
        {
            cin>>G.vex[i];
            charToIndex[G.vex[i]] = i; 
        }
        // 输入邻接矩阵
        cout << "Please enter the AdjArray(every column has " << n << " integers)" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> G.Edge[i][j];
            }
        }

        // 输入出发点（字符）
        char startChar;
        cout << "Please enter the vertex you want to begin: ";
        cin >> startChar;

        // 查找该字符对应的索引
        int start = charToIndex[startChar];

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
        charToIndex.clear();    
    }
    return 0;
}


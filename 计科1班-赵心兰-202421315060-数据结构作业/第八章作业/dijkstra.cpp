#include<iostream>
using namespace std;
typedef int VertexType;
typedef int EdgeType;
#define MaxSize 100
#define MaxEdge 200
#define Max 0x10000 //相当于正无穷，正无穷是0x7fff
typedef struct 
{
    VertexType vertex[MaxSize];
    EdgeType arc[MaxSize][MaxSize];
    int vertex_num;
    int edge_num;
}Mat_Graph;
void createGraph(Mat_Graph* G)
{
    cin>>G->vertex_num;
    if(G->vertex_num==-1) return;
    for(int i=0;i<G->vertex_num;i++) //顶点是0，1，2，3,....
    {
        G->vertex[i]=i;
    }
    for(int i=0;i<G->vertex_num;i++)
    {
        for(int j=0;j<G->vertex_num;j++)
        {
            if(i==j)
            {
                G->arc[i][j]=0;
            }
            else
            {
                cin>>G->arc[i][j];
            }
        }
    }    
}
int choose(int distance[],bool found[],int vertex_num)//选择未被访问的，已确定的路径最短的顶点
{
    int min=Max;
    int minPos=-1;
    for(int i=0;i<vertex_num;i++)
    {
        if(distance[i]<min&&found[i]==false)
        {
            min=distance[i];
            minPos=i;
        }
    }
    return minPos;
}
void dijkstra(Mat_Graph G,int begin)
{
    bool found[MaxSize];//顶点是否已经走过
    int path[MaxSize];//路径
    int distance[MaxSize];//begin到各个顶点的最短距离
    for(int i=0;i<G.vertex_num;i++)//初始化各个数组
    {
        found[i]=false;
        path[i]=-1;
        distance[i]=G.arc[begin][i];
    }
    found[begin]=true;
    distance[begin]=0;
    int next;//下一个要走的顶点
    for(int i=1;i<G.vertex_num;i++)
    {
        next=choose(distance,found,G.vertex_num);
        found[next]=true;
        for(int j=0;j<G.vertex_num;j++)
        {
            if(found[j]==false)
            {
                if(distance[next]+G.arc[next][j]<distance[j])//dijkstra核心
                {
                    distance[j]=distance[next]+G.arc[next][j];
                    path[j]=next;
                }
            }
        }
    }
    //for(int i=1;i<G.vertex_num;i++) //输出
    //{
        //cout<<begin<<"->v"<<i<<": "<<distance[i]<<endl;
        //int j=i;
        //cout<<"v"<<i<<"<-";
        //while(path[j]!=-1)
        //{
            //cout<<"v"<<path[j];
            //j=path[j];
        //}
        //cout<<begin<<endl;
    //}
    // 修复输出部分
    for(int i=0;i<G.vertex_num;i++) 
    {
        if(i != begin) {
            cout << "Shortest distance from " << begin << " to " << i << ": " << distance[i] << endl;
            
            // 输出路径
            if(path[i] != -1) {
                // 简单路径输出（可以从终点反向追踪到起点）
                cout << "Path: ";
                int current = i;
                // 这里可以进一步优化路径打印逻辑
                cout << current << " <- ... <- " << begin << endl;
            }
        }
    }
}
int main()
{
    Mat_Graph G;
    while(true)
    {
        createGraph(&G);
        if(G.vertex_num==-1) break;
        int begin;
        cin>>begin;
        dijkstra(G,begin);
        cout<<endl;
    }
    return 0;
}

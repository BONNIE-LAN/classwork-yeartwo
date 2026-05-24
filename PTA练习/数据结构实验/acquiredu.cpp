#include <iostream>
#include<vector>
using namespace std; 
#ifndef MAXV
#define MAXV 100                                        //图中最多的顶点数
#define INF 0x3f3f3f3f                                //用INF表示
#endif 

class MatGraph                        //图邻接矩阵类
{
public:
    int edges[MAXV][MAXV];            //邻接矩阵数组，假设元素为int类型
    int n,e;                        //顶点数，边数
    string vexs[MAXV];                //存放顶点信息
    void CreateMatGraph(int a[][MAXV],int n,int e) //通过边数组a、顶点数n和边数e来建立图的邻接矩阵
    {
        this->n=n; this->e=e;                //置顶点数和边数
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                this->edges[i][j]=a[i][j];
    }
    void DispMatGraph()                        //输出图的邻接矩阵
    {    for (int i=0;i<n;i++)
        {    for (int j=0;j<n;j++)
                if (edges[i][j]==INF)
                    printf("%4s","∞");
                else
                    printf("%4d",edges[i][j]);
            printf("\n");
        }
    }
};
int Degree1(MatGraph &g,int v)                           //无向图邻接矩阵g中求顶点v的度
{
    int ans=0;
   for(int i=0;i<g.n;i++)
   {
      ans+=g.edges[v][i];
   }
   return ans;     
}
vector<int> Degree2(MatGraph &g,int v)                 //有向图邻接矩阵g中求顶点v的出度和入度
{
    vector<int> ans={0,0};                           //ans[0]累计出度,ans[1]累计入度
    //补充
    for(int i=0;i<g.n;i++)
    {
        if(g.edges[v][i]!=INF&&v!=i)
        {
            ans[0]+=1;
        }
    }
    for(int j=0;j<g.n;j++)
    {
        if(g.edges[j][v]!=INF&&v!=j)
        ans[1]+=1;
    }
   
   return ans;
    
}
int main()
{
    MatGraph g1,g2;
    int n=5,e=8;
    int a[MAXV][MAXV]={{0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
    g1.CreateMatGraph(a,n,e);
    printf("图G1(无向图)\n"); g1.DispMatGraph();
    printf("求解结果\n");
    for (int i=0;i<g1.n;i++)
        printf("  顶点%d的度: %d\n",i,Degree1(g1,i));

    n=5; e=5;
    int b[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};    
    g2.CreateMatGraph(b,n,e);
    printf("图G2(有向图)\n"); g2.DispMatGraph();
    printf("求解结果\n");
    for (int i=0;i<g2.n;i++)
    {
        vector<int> ans=Degree2(g2,i);
        printf("  顶点%d: 出度=%d 入度=%d 度=%d\n",i,ans[0],ans[1],ans[0]+ans[1]);
    }
    return 0;
}
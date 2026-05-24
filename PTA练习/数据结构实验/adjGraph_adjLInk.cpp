#include <iostream>
using namespace std; 
#ifndef MAXV
#define MAXV 100                                        //图中最多的顶点数
#define INF 0x3f3f3f3f                                //用INF表示
#endif 

struct ArcNode                                        //边结点类型 
{    int adjvex;                                        //邻接点 
    int weight;                                        //权值 
    ArcNode *nextarc;                                //指向下一条边的边结点 
};
struct HNode                                        //头结点类型 
{
    string info;                                    //顶点信息
    ArcNode *firstarc;                                //指向第一条边的边结点
};
class AdjGraph                                        //图邻接表类
{
public:
    HNode adjlist[MAXV];                            //头结点数组
    int n,e;                                        //顶点数，边数
    AdjGraph()                                        //构造函数
    {
        for (int i=0;i<MAXV;i++)                    //头结点的firstarc置为空 
            adjlist[i].firstarc=NULL;
    }
    ~AdjGraph()                                        //析构函数,释放图的邻接表空间
    {
        ArcNode *p,*q;
        for(int i=0;i<n;i++)
        {
            p=adjlist[i].firstarc;
            while(p!=NULL)
            {
                q=p->nextarc;
                delete p;
                p=q;
            }
        }
    }
    void CreateAdjGraph(int a[][MAXV],int n,int e)    //通过边数组a、顶点数n和边数e来建立图的邻接表
    {
        this->n=n;
        this->e=e;
        ArcNode *p,*tail;
        for(int i=0;i<n;i++)
        {
            tail=NULL;
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=INF&&i!=j)
                {
                    p=new ArcNode;
                    p->adjvex=j;
                    p->weight=a[i][j];
                    p->nextarc=NULL;//尾插法
                    if(tail==NULL)
                    {
                        adjlist[i].firstarc=p;
                        tail=p;
                    }
                    else
                    {
                        tail->nextarc=p;
                        tail=p;
                    }
                }
            }
        }
    }

    
    void DispAdjGraph()                                //输出图的邻接表
    {
        ArcNode *p;
        for (int i=0;i<n;i++)                        //遍历每个头结点 
        {
            printf("   [%d]",i);
            p=adjlist[i].firstarc;                    //p指向第一个邻接点
            if (p!=NULL)  printf("->");
            while (p!=NULL)                            //遍历第i个单链表 
            {
                printf(" (%d,%d)",p->adjvex,p->weight);
                p=p->nextarc;                        //p移向下一个邻接点
            }
            printf("\n");
        }
    }
};
int main()
{
    AdjGraph G;
    int n=5,e=5;
    int A[MAXV][MAXV]={{0,8,INF,5,INF},{INF,0,3,INF,INF},{INF,INF,0,INF,6},{INF,INF,9,0,INF},{INF,INF,INF,INF,0}};    
    G.CreateAdjGraph(A,n,e);
    cout << "Graph:\n"; G.DispAdjGraph();
    cout << "Destory\n";
    return 0;
}

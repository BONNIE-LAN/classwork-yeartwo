#include<iostream>
#include<stack>
using namespace std;
#define MaxSize 100
typedef int VertexType;
//边结点结构体
typedef struct EdgeNode
{
    int edge_vex;
    EdgeNode* next;
}EdgeNode;
//顶点结构体
typedef struct VertexNode
{
    VertexType data;
    int in;//入度
    EdgeNode* head;
}VertexNode;
//邻接表结构体
typedef struct Adj_Graph
{
    VertexNode Adj_List[MaxSize];
    int vertex_num;
}Adj_Graph;
//创建邻接表
void createGraph(Adj_Graph* AG)
{
    int n;
    cin>>n;
    if(n==-1) return;//输入-1结束程序
    AG->vertex_num=n;
    //初始化所有顶点
    for(int i=0;i<n;i++)
    {
        AG->Adj_List[i].data=i;
        AG->Adj_List[i].in=0;
        AG->Adj_List[i].head=nullptr;
    }
    //读取每个顶点的邻接点
    for(int i=0;i<n;i++)
    {
        int adj;
        while(cin>>adj&&adj!=-1)
        {
            //创建新边结点
            EdgeNode* p=new EdgeNode;
            p->edge_vex=adj;
            p->next=AG->Adj_List[i].head;
            AG->Adj_List[i].head=p;
            //增加邻接点的入的
            AG->Adj_List[i].in++;
        }
    }
}
//拓扑排序函数
bool TopologicalSort(Adj_Graph* AG)
{
    stack<int> S;
    int count=0;
    int n=AG->vertex_num;
    //找到所有入度为0的顶点并入栈
    for(int i=0;i<n;i++)
    {
        if(AG->Adj_List[i].in==0)
        {
            S.push(i);
        }
    }
    cout<<"The result of topo: ";
    while(!S.empty())
    {
        int v=S.top();
        S.pop();
        cout<<v<<" ";
        count++;
        //遍历v的所有出边
        for(EdgeNode* p=AG->Adj_List->head;p!=nullptr;p=p->next)
        {
            int adj=p->edge_vex;
            AG->Adj_List[adj].in--;
            if(AG->Adj_List[adj].in==0)
            {
                S.push(adj);
            }
        }
    }
    cout<<endl;
    //如果输出的顶点数小于总顶点数，则说明存在回路
    return(count==0);
}
int main()
{
    Adj_Graph AG;
    while(true)
    {
        createGraph(&AG);
        if(AG.vertex_num==-1) break;
        if(TopologicalSort(&AG))
        {
            cout<<"This Graph has no circle"<<endl;
        }
        else
        {
            cout<<"This Graph has circle"<<endl;
        }
        cout<<endl;
    }
    return 0;
}

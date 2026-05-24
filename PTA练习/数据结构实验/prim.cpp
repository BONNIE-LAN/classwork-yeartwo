#include <iostream>
#define MVNum 10
#define MaxInt 32767 
using namespace std;

struct edge{
    char adjvex;
    int lowcost;
}closedge[MVNum];

typedef struct{ 
    char vexs[MVNum];   
    int arcs[MVNum][MVNum]; 
    int vexnum,arcnum;
}AMGraph;
int LocateVex(AMGraph G , char v);//实现细节隐藏
int Min(AMGraph G);//实现细节隐藏
int CreateUDN(AMGraph &G);//实现细节隐藏

void Prim(AMGraph G, char u);

int main(){
    AMGraph G;
    CreateUDN(G);
    char u;
    cin >> u;
    Prim(G , u);
    return 0;
}
void Prim(AMGraph G, char u)
{
    int k = LocateVex(G, u);

    // 初始化 closedge
    for(int j = 0; j < G.vexnum; j++)
    {
        closedge[j].adjvex = u;
        closedge[j].lowcost = G.arcs[k][j];
    }
    closedge[k].lowcost = 0;  // 起点加入生成树

    // 生成最小生成树
    for(int i = 1; i < G.vexnum; i++)
    {
        k = Min(G);  // 选最小边
        cout << closedge[k].adjvex << "->" << G.vexs[k] << endl;
        closedge[k].lowcost = 0;

        // 更新其它顶点的 lowcost
        for(int j = 0; j < G.vexnum; j++)
        {
            if(G.arcs[k][j] < closedge[j].lowcost)
            {
                closedge[j].lowcost = G.arcs[k][j];
                closedge[j].adjvex = G.vexs[k];
            }
        }
    }
}
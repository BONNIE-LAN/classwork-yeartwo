#include <stdio.h>
#define MVNum 10 
#define MaxInt 32767 

typedef struct{ 
    char vexs[MVNum];
    int arcs[MVNum][MVNum];
    int vexnum,arcnum; 
}AMGraph;

struct Evode{
    char Head;
    char Tail;
    int lowcost;
}Edge[(MVNum * (MVNum - 1)) / 2];

int Vexset[MVNum];
void CreateUDN(AMGraph &G);//实现细节隐藏
void Kruskal(AMGraph G);
int main(){
    AMGraph G;
    CreateUDN(G);
    Kruskal(G);
    return 0;
}
void Kruskal(AMGraph G)
{
    int i, j;
    int k = 0;   // 已选边数

    // 1. 初始化并查集
    for(i = 0; i < G.vexnum; i++)
        Vexset[i] = i;

    // 2. 对 Edge 按权值从小到大排序（冒泡排序，考试常用）
    int edgeNum = G.arcnum;
    struct Evode temp;
    for(i = 0; i < edgeNum - 1; i++)
    {
        for(j = 0; j < edgeNum - i - 1; j++)
        {
            if(Edge[j].lowcost > Edge[j + 1].lowcost)
            {
                temp = Edge[j];
                Edge[j] = Edge[j + 1];
                Edge[j + 1] = temp;
            }
        }
    }

    // 3. 依次选最小边
    for(i = 0; i < edgeNum && k < G.vexnum - 1; i++)
    {
        int v1, v2;

        // 找顶点下标
        for(j = 0; j < G.vexnum; j++)
            if(G.vexs[j] == Edge[i].Head)
                v1 = j;

        for(j = 0; j < G.vexnum; j++)
            if(G.vexs[j] == Edge[i].Tail)
                v2 = j;

        int vs1 = Vexset[v1];
        int vs2 = Vexset[v2];

        // 不在同一集合，则选该边
        if(vs1 != vs2)
        {
            printf("%c->%c\n", Edge[i].Head, Edge[i].Tail);
            k++;

            // 合并集合
            for(j = 0; j < G.vexnum; j++)
                if(Vexset[j] == vs2)
                    Vexset[j] = vs1;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#define MVNum 10
                        
int visited[MVNum];
typedef struct{ 
    char vexs[MVNum];                    
    int arcs[MVNum][MVNum]; 
    int vexnum,arcnum;             
}Graph;
 
void CreateUDN(Graph &G);//实现细节隐藏
void DFS(Graph G, int v);
void DFSTraverse(Graph G){ 
    int v;
    for(v = 0; v < G.vexnum; ++v)  visited[v] = 0;    
    for(v = 0; v < G.vexnum; ++v)
        if(!visited[v])  DFS(G, v); 
}
int main(){
    Graph G;
    CreateUDN(G);
    DFSTraverse(G);
    return 0;
}
void DFS(Graph G,int v)
{
    printf("%c ",G.vexs[v]);
    visited[v]=true;
    for(int w=0;w<G.vexnum;w++)
    {
        if(G.arcs[v][w]==1&&!visited[w])
        {
            DFS(G,w);
        }
    }
}
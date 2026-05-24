#include <stdio.h>
#include <stdlib.h>
#define MVNum 10
int visited[MVNum]; 
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int info; 
}ArcNode; 

typedef struct VNode{ 
    char data;
    ArcNode *firstarc;
}VNode, AdjList[MVNum];

typedef struct{ 
    AdjList vertices; 
    int vexnum, arcnum;
}ALGraph;

int CreateUDG(ALGraph &G);//实现细节隐藏
void DFS(ALGraph G, int v);

void DFSTraverse(ALGraph G){ 
 int v;
 for(v = 0; v < G.vexnum; ++v)  
   visited[v] = 0;    
 for(v = 0; v < G.vexnum; ++v)
   if(!visited[v])  
     DFS(G, v);
} 

int main(){
 ALGraph G;
 CreateUDG(G);
 DFSTraverse(G);
 return 0;
}
void DFS(ALGraph G, int v)
{
    printf("%c ",G.vertices[v].data);
    visited[v]=1;
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

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
void BFS(Graph G, int v);
void BFSTraverse(Graph G){ 
    int v;
    for(v = 0; v < G.vexnum; ++v)  visited[v] = 0;    
    for(v = 0; v < G.vexnum; ++v)
        if(!visited[v])  BFS(G, v); 
}
int main(){
    Graph G;
    CreateUDN(G);
    BFSTraverse(G);
    return 0;
}
void BFS(Graph G,int v)
{
    int queue[MVNum];  // 用数组模拟队列
    int front = 0, rear = 0;  // 队列的头和尾指针
    
    // 访问第一个顶点
    printf("%c ", G.vexs[v]);
    visited[v] = 1;
    
    // 将起始顶点入队
    queue[rear++] = v;
    
    while(front != rear)  // 队列不为空时循环
    {
        // 出队一个顶点
        int u = queue[front++];
        
        // 查找u的所有邻接顶点
        for(int w = 0; w < G.vexnum; w++)
        {
            if(G.arcs[u][w] == 1 && !visited[w])
            {
                printf("%c ", G.vexs[w]);
                visited[w] = 1;
                queue[rear++] = w;  // 入队
            }
        }
    }
}
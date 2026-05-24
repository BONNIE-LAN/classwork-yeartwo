#include <stdio.h>
#include <stdlib.h>
#define MVNum 10
#define MAXQSIZE 100

bool visited[MVNum]; 
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
void BFS(ALGraph G, int v);

void BFSTraverse(ALGraph G){ 
 int v;
 for(v = 0; v < G.vexnum; ++v)  
   visited[v] = 0;    
 for(v = 0; v < G.vexnum; ++v)
   if(!visited[v])  
     BFS(G, v);
} 

int main(){
 ALGraph G;
 CreateUDG(G);
 BFSTraverse(G);
 return 0;
}
void BFS(ALGraph G, int v)
{
    // 使用数组模拟循环队列
      int Queue[MAXQSIZE];
      int front = 0, rear = 0;
      
      // 访问第一个顶点
      printf("%c ", G.vertices[v].data);
      visited[v] = true;
      
      // 将起始顶点入队
      Queue[rear] = v;
      rear = (rear + 1) % MAXQSIZE;
      
      while(front != rear)  // 队列不为空
      {
          // 出队一个顶点
          int u = Queue[front];
          front = (front + 1) % MAXQSIZE;
          
          // 遍历u的所有邻接点
          ArcNode *p = G.vertices[u].firstarc;
          while(p != NULL)
          {
              int w = p->adjvex;
              if(!visited[w])
              {
                  printf("%c ", G.vertices[w].data);
                  visited[w] = true;
                  
                  // 入队
                  Queue[rear] = w;
                  rear = (rear + 1) % MAXQSIZE;
              }
              p = p->nextarc;
          }
      }
}

#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
const int MaxSize=100;                        //最多总结点个数

struct HTNode                                 //哈夫曼树结点类
{    
    char data;                                //结点值
    double weight;                            //权值
    int parent;                               //双亲结点
    int lchild;                               //左孩子结点
    int rchild;                               //右孩子结点
    bool flag;                                //标识是双亲的左(True)或者右(False)孩子
    HTNode()                                 //构造函数
    {     
        parent=-1;
        lchild=-1;
        rchild=-1;
        flag=true;
    }    
    HTNode(char d,double w)                 //重载构造函数
    {    
        data=d;
        weight=w;
        parent=-1;
        lchild=-1;
        rchild=-1;
        flag=true;
    }
};

HTNode ht[MaxSize];                         //ht存放哈夫曼树
string hcd[MaxSize];                        //hcd存放哈夫曼编码

struct HeapNode                                //优先队列元素类型 
{
    double w;                                //权值
    int i;                                   //对应哈夫曼树中结点编号
    HeapNode(double w1,int i1):w(w1),i(i1) {}    //构造函数 
    bool operator<(const HeapNode &s) const    
    {                                        //按w越小越优先出队
        return w>s.w;                        
    }    
};

//--------------------------------
//   建立哈夫曼树
//--------------------------------
void CreateHT(char D[], double W[], int n0)                                
{
    priority_queue<HeapNode> qu; //小根堆

    // 1. 初始化叶子节点并加入队列
    for (int i=0;i<n0;i++)
    {
        ht[i] = HTNode(D[i],W[i]);
        qu.push(HeapNode(W[i],i));
    }

    int m = 2*n0 - 1; // 总节点个数

    // 2. 依次合并两个最小权值结点
    for (int k=n0;k<m;k++)
    {
        HeapNode x = qu.top(); qu.pop();
        HeapNode y = qu.top(); qu.pop();

        // 新结点
        ht[k].weight = x.w + y.w;
        ht[k].lchild = x.i;
        ht[k].rchild = y.i;
        ht[k].data = ' '; // 非叶节点
        ht[x.i].parent = k;
        ht[y.i].parent = k;
        ht[x.i].flag = true;  // 左孩子
        ht[y.i].flag = false; // 右孩子

        // 新节点入队
        qu.push(HeapNode(ht[k].weight, k));
    }
}

//--------------------------------
//   建立哈夫曼编码
//--------------------------------
void CreateHCode(int n0)
{
    string code;
    int p;
    for (int i=0;i<n0;i++)
    {
        code = "";
        int c = i;
        while (ht[c].parent != -1)
        {
            p = ht[c].parent;
            if (ht[c].flag)
                code = "0" + code;
            else
                code = "1" + code;
            c = p;
        }
        hcd[i] = code;
    }
}

//--------------------------------
//   输出哈夫曼树
//--------------------------------
void DispHT(int n0)
{
    printf("  i      ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",i);
    printf("\n");
    printf("  D[i]   ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3c",ht[i].data);
    printf("\n");
    printf("  W[i]   ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3g",ht[i].weight);
    printf("\n");
    printf("  parent ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",ht[i].parent);
    printf("\n");
    printf("  lchild ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",ht[i].lchild);
    printf("\n");
    printf("  rchild ");
    for (int i=0;i<2*n0-1;i++)
        printf("%3d",ht[i].rchild);
    printf("\n");
}

//--------------------------------
//   输出哈夫曼编码
//--------------------------------
void DispHCode(int n0)
{
    for (int i=0;i<n0;i++)
        cout << "  " << ht[i].data << ":" << hcd[i] << endl;
}

int main()
{
    int n0;                                    //编码的字符个数
    cin>>n0;
    double* W = new double[n0];                //权值列表
    char* D = new char[n0];                    //字符列表
    char sep;
    for(int i=0;i<n0-1;i++)
        cin>>D[i]>>sep;
    cin>>D[n0-1];
    for(int i=0;i<n0-1;i++)
        cin>>W[i]>>sep;
    cin>>W[n0-1];

    printf("(1)建立哈夫曼树\n");
    CreateHT(D,W,n0);
    printf("(2)输出哈夫曼树\n");
    DispHT(n0);
    printf("(3)建立哈夫曼编码\n");
    CreateHCode(n0);
    printf("(4)输出哈夫曼编码\n");
    DispHCode(n0);
    return 0;
}

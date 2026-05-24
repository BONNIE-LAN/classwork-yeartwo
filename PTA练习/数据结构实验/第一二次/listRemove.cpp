#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ERROR 0
#define OK 1
typedef int Status;
typedef int ElemType;
//定义顺序表结构 
typedef struct
{
    ElemType *elem;
    int length;    
    int listsize;
}SqList ;

Status InitList(SqList &L);//定义初始化函数
Status CreateList(SqList &L,int a[],int n);//构造与数组元素内容相同的顺序表L 
void DispList(SqList L) ;//显示顺序表内容
Status DeleteList(SqList &L,int i,ElemType &e) ;//删除顺序线性表L中第i个元素,并将所删除的元素保存在e中

int main()
{
    int i;
    ElemType e;
    scanf("%d",&i);    
    int a[]={16,6,2,9,11,8,1};
    SqList L;
    InitList(L);
    CreateList(L,a,sizeof(a)/sizeof(a[0]));
    printf("删除前："); 
    DispList(L);
    DeleteList(L,i,e); 
    printf("删除后："); 
    DispList(L);
    return 0;    
}
//定义初始化函数
Status InitList(SqList &L)
{
    L.elem=(ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
    if(!L.elem)
        return ERROR;
    L.length=0;
    L.listsize= MAXSIZE;
    return OK;
}
//构造与数组元素内容相同的顺序表LA 
Status  CreateList(SqList &L,int a[],int n)
{
    L.length=n;    
    for(int i=0;i<n;i++)
        L.elem[i]=a[i];    
    return OK;
}
//显示顺序表内容
void DispList(SqList L)
{
    if(L.length!=0)
    {
        for(int i=0;i<L.length;i++)
            printf("%d ",L.elem[i]);
        printf("\n");
    }
}
Status DeleteList(SqList &L,int i,ElemType &e)
{
    if(i<0||i>L.length)
    {
        printf("不合理的位置,无法删除元素");
        return ERROR;
    }
    e=L.elem[i-1];
    for(int j=i;j<L.length;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
    return OK;
}
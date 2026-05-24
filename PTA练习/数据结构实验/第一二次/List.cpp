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
Status IsEmpty(SqList L);//判断顺序表是否为空 
Status ListLength(SqList L) ;//求顺序表长度 
void ClearList(SqList &L) ;//清空顺序表 
void DestoryList(SqList &L) ;//销毁顺序表 

int main()
{
    int a[]={16,6,2,9,11,8,1};
    SqList L;
    InitList(L);//初始化顺序表
    CreateList(L,a,sizeof(a)/sizeof(a[0]));//构造与数组中元素相同的顺序表
    if(IsEmpty(L)==1)
        printf("empty\n");
    else
    {
        printf("not empty\n");
        printf("List Length:%d\n",ListLength(L));
    }
    ClearList(L);
    printf("Afert clearing the length of list:%d\n",ListLength(L));
    DestoryList(L);
    if(!L.elem)
        printf("The List has been destroy\n");        
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
Status IsEmpty(SqList L)
{
    if(L.length==0)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }
}
Status ListLength(SqList L)
{
    return L.length;
}
void ClearList(SqList &L)
{
    while (L.length > 0) {
        for (int i = 1; i < L.length; i++) 
        {
            L.elem[i-1] = L.elem[i];
        }
        L.length--;
    }
}
void DestoryList(SqList &L)
{
    if(L.elem!=nullptr)
    {
        delete[]L.elem;
        L.elem=nullptr;
    }
    L.length=0;
}
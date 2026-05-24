#include <iostream>
using namespace std;
const int MaxSize = 100;
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int len;
}SqList;
void Input(SqList &L); //有序表输入，裁判实现，细节不表
int BS(SqList L, ElemType x);
int LB(SqList L, ElemType x); //最左
int UB(SqList L, ElemType x); //最右
int main() 
{
    SqList L;
    int n;
    cin>>n;
    Input(L);
    ElemType e;
    cin>>e;
    cout<<BS(L,e)<<" "<<LB(L,e)<<" "<<UB(L,e)<<endl;
}
int BS(SqList L, ElemType x)
{
    int left=0,right=L.len-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(L.data[mid]==x) return mid;
        if(L.data[mid]<x) left=mid+1;
        else right=mid-1;
    }
    return -1;
}
int LB(SqList L, ElemType x)
{
    int left=0,right=L.len;
    while(left<right)
    {
        int mid=left+(right-left)/2;
        if(L.data[mid]<x) left=mid+1;
        else right=mid;
    }
    return left;
}
int UB(SqList L,ElemType x)
{
    int left=0,right=L.len-1,ans=-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(L.data[mid]<=x)
        {
            ans=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return ans;
}

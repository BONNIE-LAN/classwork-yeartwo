#include<iostream>
#include<stack>
using namespace std;
int partition(int arr[],int low,int high);
//快排：递归版本
void quickSortRecursive(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivotIndex=partition(arr,low,high);
        quickSortRecursive(arr,low,pivotIndex-1);
        quickSortRecursive(arr,pivotIndex+1,high);
    }
}
//快排：非递归版(用栈模拟递归)
void quickSortIterative(int arr[],int low,int high)
{
    stack<pair<int,int>> stk;
    stk.push({low,high});
    while(!stk.empty())
    {
        pair<int, int> top = stk.top();
        int l = top.first;
        int r = top.second;
        stk.pop();
        if(l<r)
        {
            int pivotIndex=partition(arr,l,r);
            if(pivotIndex-1-1>r-(pivotIndex+1))
            {
                stk.push({l,pivotIndex-1});
                stk.push({pivotIndex+1,r});
            }
            else
            {
                stk.push({pivotIndex+1,r});
                stk.push({l,pivotIndex-1});
            }
        }
    }
}
//分区函数
int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
//打印数组
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<(i<size-1?" ":"");
    }
    cout<<endl;
}
int main()
{
    while(true)
    {
        int n=0;
        int arr[1000];
        while(true)
        {
            int x;
            cin>>x;
            if(x==-1) return 0;
            if(x==0) break;
            arr[n++]=x;
        }
        if(n==0)
        {
            cout<<"Empty list"<<endl;
            continue;
        }
        cout<<"Before sorting: ";
        printArray(arr,n);
        int arr2[1000];
        for(int i=0;i<n;i++) arr2[i]=arr[i];
        quickSortRecursive(arr,0,n-1);
        cout<<"Aftering recursive sorting: ";
        printArray(arr,n);
        quickSortIterative(arr2,0,n-1);
        cout<<"After non-recursive sorting: ";
        printArray(arr2,n);
    }
    return 0;
}

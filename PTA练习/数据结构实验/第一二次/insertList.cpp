#include <iostream>
using namespace std;

#define MAXSIZE 10
typedef int ElemType;
typedef struct
{
    ElemType* elem;
    int length;
}SqList;

bool CreateList(SqList& L)
{
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem)
    {
        return false;
    }
    cin >> L.length;
    for (int i = 0; i < L.length; i++)
    {
        cin >> L.elem[i];
    }
    return true;
}

bool ListInsert(SqList& L, int i, ElemType e)
{
    if(L.length>=10)
    {
        printf("OVERFLOW!");
        return false;
    }
    else if(i-1<0||i-1>L.length)
    {
        printf("Insert position error!");
        return false;
    }
    else
    {
        for(int j=L.length;j>=i-1;j--)
       {
            L.elem[j]=L.elem[j-1];
       }
       L.elem[i-1]=e;
       L.length++;
       return true;
    }
}

void print(SqList L)
{
    for (int i = 0; i < L.length; i++)
    {
        if (i == 0)
        {
            cout << '(' << L.elem[i];
        }
        else
        {
            cout << ',' << L.elem[i];
        }
    }
    cout << ')' << endl;
}

int main()
{
    SqList L; int i; ElemType e;
    CreateList(L);
    cout << "Before:";
    print(L);
    cin >> i >> e;
    if (ListInsert(L, i, e))
    {
        cout << "After:";
        print(L);
    }
    return 0;
}

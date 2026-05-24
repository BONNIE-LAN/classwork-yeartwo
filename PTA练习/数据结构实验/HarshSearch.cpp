#include<iostream>
using namespace std;

#define m 13
#define NULLKEY 0 //单元为空的标记

struct HashTable{
   int  key;
};

void CreateHash(HashTable HT[], int n)
{
    int value;
    for(int i = 0; i < n; i++)
    {
        cin >> value;
        int pos = value % m;

        while(HT[pos].key != NULLKEY)   // 线性探测
        {
            pos = (pos + 1) % m;
        }

        HT[pos].key = value;
    }
}

int SearchHash(HashTable HT[], int key)
{
    int pos = key % m;
    int start = pos;

    while(HT[pos].key != NULLKEY)      // 有数据才继续找
    {
        if(HT[pos].key == key)
            return pos;

        pos = (pos + 1) % m;

        if(pos == start)               // 回到起点，找不到
            return -1;
    }

    return -1;                         // 遇到空位 -> 查找失败
}

int main()
{    int value,key;
    int result;
    int i,j,n;
    HashTable HT[m];
    for(i=0;i<m;i++)
     HT[i].key=0;
    cin >> n;
    if(n>m) return 0;
    CreateHash(HT,n);
    cin >> key;
    result=SearchHash(HT,key);
    if(result!=-1)
        cout << "search success,The key is located in "<< result+1;
    else
        cout << "search failed";
    return 0;
}


/* 请在这里填写答案 */
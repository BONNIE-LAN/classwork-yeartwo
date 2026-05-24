#include<iostream>
#include<algorithm>
using namespace std;
const int defaultSize=100;
template<typename T>
class SeqList
{
    private:
    T *data;
    int maxSize;
    int last;
    public:
    SeqList(int sz=defaultSize); //构造函数
    SeqList(SeqList<T>& L); //复制构造函数
    ~SeqList() //析构函数
    {
        delete[] data;
    }
    void Reverse(); //反转函数
};
template <typename T>
SeqList<T>::SeqList(int sz)
{
    if(sz>0)
    {
        maxSize=sz;
        last=-1;
        data=new T[maxSize];
        if(data==nullptr)
        {
            cerr<<"wrong!"<<endl;
            exit(1);
        }
    }
    for(int i=0;i<maxSize;i++)
    {
        cin>>data[i];
    }
    last=maxSize-1;
}
template <typename T>
SeqList<T>::SeqList(SeqList<T>& L)
{
    maxSize=L.Size();
    last=L.length()-1;
    T value;
    data=new T[maxSize];
    if(data==nullptr)
    {
        cerr<<"wrong!"<<endl;
        exit(1);
    }
    for(int i=1;i<=last+1;i++)
    {
        value=data[i-1];
    } 
}
template <typename T>
void SeqList<T>::Reverse()
{
    int i=0,j=last;
    while(i<j)
    {
        swap(data[i],data[j]);
        i++;
        j--;
    }
    cout<<"After reversing: ";
    for(int i=0;i<=last;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    SeqList<int> sl(10);
    sl.Reverse();
    return 0;
}
#include<iostream>
using namespace std;
const int maxSize=100;
template<typename T>
class Array
{
    private:
    T a[maxSize];
    int length;
    public:
    Array()
    {
        length=0;
    }
    bool input()
    {
        cout<<"Please enter the number of array: "<<endl;
        cin>>length;
        if(length==-1)
        {
            return false;
        }
        cout<<"Please enter the element in the array: "<<endl;
        for(int i=0;i<length;i++)
        {
            cin>>a[i];
        }
        return true;
    }
    void removeMin()
    {
        T min=a[0];
        int minIndex=0;
        for(int i=0;i<length;i++)
        {
            if(a[i]<min)
            {
                min=a[i];
                minIndex=i;
            }
        }
        for(int i=minIndex;i<length;i++)
        {
            a[i]=a[i+1];
        }
        length--;
    }
    void display(const string& msg)
    {
       cout<<msg;
       for(int i=0;i<length;i++)
       {
            cout<<a[i]<<" ";
       }
       cout<<endl;
    }
};
int main()
{
    Array<int> arr;
    if(!arr.input())
    {
        cout<<"program exit!"<<endl;
    }
    else
    {
        arr.display("Before removing: ");
        arr.removeMin();
        arr.display("After removing: ");
    }
    return 0;
}
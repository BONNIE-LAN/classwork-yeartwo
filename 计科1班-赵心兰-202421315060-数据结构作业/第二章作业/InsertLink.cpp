#include<iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};
template <typename T>
class List
{
    Node<T> *first;
    int length;
    public:
    List()
    {
        first=nullptr;
        length=0;
    }
    ~List()
    {
        Node<T> *temp;
        while(first!=nullptr)
        {
            temp=first;
            first=first->next;
            delete temp;
        }
    }
    void CreateList(T endTag)
    {
        cout<<"Please enter the length of list:(if -1 exit) "<<endl;
        cin>>length;
        if(length==-1)
        {
            cout<<"program exit!"<<endl;
            return;
        }
        Node<T> *temp,*rear=nullptr;
        T val;
        cout<<"Enter value: ";
        for(int i=0;i<length;i++)
        {
            cin>>val;
            if(val==endTag) break;
            temp=new Node<T>;
            temp->data=val;
            temp->next=nullptr;
            if(first==nullptr)
            {
                first=temp;
                rear=temp;
            }
            else
            {
                rear->next=temp;
                rear=temp;
            }

        }
    }
    void display(const string& msg)
    {
        cout<<msg<<endl;
        Node<T> *temp;
        temp=first;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void Insert(T x)
    {
        Node<T> *temp;
        temp=new Node<T>;
        temp->data=x;
        if(first==nullptr||first->data>=x)
        {
            temp->next=first;
            first=temp;
            return;
        }
        Node<T>* locate=first;
        while(locate->next!=nullptr&&locate->next->data<x)
        {
            locate=locate->next;
        }
        temp->next=locate->next;
        locate->next=temp;
    }
    int getLength() const
    {
        return length;
    }
};
int main()
{
    List<int> L;
    L.CreateList(-1);
    if(L.getLength()==-1)
    {
        return 0;
    }
    int x;
    cout<<"Please enter the element you want to insert: "<<endl;
    cin>>x;
    L.display("Before inserting: ");
    L.Insert(x);
    L.display("After inserting: ");
    return 0;
}
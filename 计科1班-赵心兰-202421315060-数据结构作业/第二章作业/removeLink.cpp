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
        if(first==nullptr) return;
        // 找到最后一个节点，断开循环
        Node<T> *last = first;
        while(last->next != first) 
        {
            last = last->next;
        }
        last->next = nullptr; // 断开循环
        
        // 正常删除所有节点
        Node<T> *temp = first;
        while(temp != nullptr)
        {
            Node<T> *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
    void CreateList(T endTag)
    {
        cout<<"Please enter the length of list:(enter -1 exit)"<<endl;
        cin>>length;
        if(length==-1)
        {
            cout<<"Program exit!"<<endl;
            return;
        }
        Node<T> *temp,*rear=nullptr;
        T val;
        cout<<"Enter vallue: "<<endl;
        for(int i=0;i<length;i++)
        {
            cin>>val;
            if(val==endTag) break;
            temp=new Node<T>;
            temp->data=val;
            if(first==nullptr)
            {
                first=temp;
                temp->next=first;
                rear=first;
            }
            else
            {
                temp->next=first; //新节点指向头节点
                rear->next=temp; //尾节点指向新节点
                rear=temp; //更新尾节点
            }
        }
    }
    void display(const string& msg)
    {
        cout<<msg<<endl;
        if(first==nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node<T> *temp=first;
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        } while (temp!=first);
        cout<<endl;
    }
    void removeMin()
    {
        if(first==nullptr) return;
        //找到最小值节点及其前一个节点
        Node<T> *minPrev=nullptr;
        Node<T> *minNode=first;
        T minVal=first->data;
        Node<T> *prev=nullptr;
        Node<T> *current=first;
        do
        {
            if(current->data<minVal)
            {
                minVal=current->data;
                minNode=current;
                minPrev=prev;
            }
            prev=current;
            current=current->next;
        } while (current!=first);
        //删除最小值节点
        if(minNode==first)
        {
            if(first->next==first)
            {
                //只有一个节点
                delete first;
                first=nullptr;
            }
            else
            {
                //多个节点，需要找到尾节点
                Node<T> *tail=first;
                while(tail->next!=first)
                {
                    tail=tail->next;
                }
                tail->next=first->next;
                Node<T> *oldFirst = first;
                first = first->next;
                delete oldFirst;
            }
        }
        else
        {
            //删除非头节点
            minPrev->next=minNode->next;
            delete minNode;
        }
        length--;
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
    L.display("Before removing: ");
    L.removeMin();
    L.display("After removing: ");
    return 0;
}
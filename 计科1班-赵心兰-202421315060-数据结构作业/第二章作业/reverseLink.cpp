#include<iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};
template <typename T>
class ReverseList
{
    Node<T> *first;
    public:
    ReverseList()
    {
        first=nullptr;
    }
    ~ReverseList()
    {
        Node<T> *temp=first;
        if(first==nullptr)
        {
           cout<<"List is empty!"<<endl;
           return;
        }
        else
        {
            while(temp!=nullptr)
            {
                Node<T> *toDelete=temp;
                temp=temp->next;
                delete toDelete;
            }
        }
    }
    bool CreateList(T endTag)
    {
        Node<T>* newNode;
        Node<T> *rear=nullptr;
        T val;
        cout<<"Enter value:(enter -1 exit)"<<endl;
         while(true)
        {
            cin >> val;
            if(val == endTag) 
            {
                // 如果是第一次就输入-1，则退出程序
                if(first == nullptr)
                {
                    cout << "No data entered. Program will exit." << endl;
                    return false;  // 返回false表示程序应退出
                }
                else
                {
                    break;  // 结束数据输入，继续执行程序
                }
            }
            newNode=new Node<T>;
            newNode->data=val;
            newNode->next=nullptr;
           if(first == nullptr)
            {
                first = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
        return true;
    }
    void Reverse(struct Node<T> *f)
    {
        //退出条件
        if(f->next==nullptr)
        {
            first=f;
            return;
        }
        Reverse(f->next);
        struct Node<T> *q=f->next;
        q->next=f;
        f->next=nullptr;
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
    struct Node<T>* getFirst() const
    {
        return first;
    }
};
int main()
{
    ReverseList<int> L;
     // 调用CreateList，如果返回false则退出程序
    if(!L.CreateList(-1))
    {
        return 0;  // 用户一开始就输入-1，退出程序
    }
    L.display("Original list: ");
    
    // 反转链表
    if(L.getFirst() != nullptr)
    {
        L.Reverse(L.getFirst());
    }
    
    L.display("Reversed list: ");
    return 0;
}
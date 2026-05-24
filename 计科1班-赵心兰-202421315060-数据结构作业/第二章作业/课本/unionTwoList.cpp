#include<iostream>
using namespace std;
template<typename T>
struct Node1
{
    T data;
    Node1<T> *next;
    Node1(const &item,Node1<T> *ptr=nullptr)
    {data=item; next=ptr;}
};
template <typename T>
struct Node2
{
    T data;
    Node2<T> *next;
    Node2(const &item,Node2<T> *ptr=nullptr)
    {data=item; next=ptr;}
};
template <typename T>
class L1
{
    protected:
    Node1<T> *first;
    public:
    L1(){first=new Node1<T>;} //构造函数
    L1(const T&x){first=new Node1<T>(x);}//构造函数
    ~L1()//析构函数
    {
        Node1<T> *temp;
        while(first->next!=nullptr)
        {
            temp=first->next;
            first->next=temp->next;
            delete temp;
        }

    }
    void input())//按顺序插入，创建列表
    void Insrt(int i,T& value)//插入
    void remove(int i)//删除
    void output()//输出
};
template <typename T>
class L2
{
    protected:
    Node2<T> *first;
    public:
    L2(){first=new Node2<T>;} //构造函数
    L2(const T&x){first=new Node2<T>(x);}//构造函数
    ~L2()//析构函数
    {
        Node2<T> *temp;
        while(first->next!=nullptr)
        {
            temp=first->next;
            first->next=temp->next;
            delete temp;
        }

    }
    void input()//按顺序插入，创建列表
    void Insrt(int i,T& value)//插入
    void remove(int i)//删除
    void output()//输出
};
template <typename T>
void L1<T>::input()
{
     T val;
    while (true) {
        cout << "请输入要插入的值（输入-1结束）: ";
        cin >> val;
        
        if (val == -1) break;  // 结束条件
        
        Node1<T> *newNode = new Node1<T>(val);
        if (!newNode) {
            cerr << "内存分配失败!" << endl;
            continue;
        }
        
        // 找到合适的插入位置
        Node1<T> *prev = first;
        Node1<T> *current = first->next;
        
        while (current != nullptr && current->data < val) {
            prev = current;
            current = current->next;
        }
        
        // 检查重复值
        if (current != nullptr && current->data == val) {
            cout << "不能插入相同的数据: " << val << endl;
            delete newNode;
            continue;
        }
        
        // 插入节点
        newNode->next = current;
        prev->next = newNode;
    }
}



#include <iostream>
using namespace std;
template <typename T>
struct LinkNode                                //链栈结点类型 
{
     T data;                                //数据域
     LinkNode *next;                        //指针域
     LinkNode():next(NULL) {}                 //构造函数 
     LinkNode(T d):data(d),next(NULL) {}     //重载构造函数 
};

template <typename T>
class LinkStack                                //链栈泛型类
{
public:
    LinkNode<T> *head;                        //链栈头结点
    LinkStack()                                //构造函数
    {    
        head=new LinkNode<T>();
    }
    ~LinkStack()                            //析构函数
    {    
        LinkNode<T> *pre=head,*p=pre->next;
        while (p!=NULL)
        {
            delete pre;
            pre=p; p=p->next;                //pre、p同步后移
        }
        delete pre;
    }
      bool empty() {
        // 修正：检查头结点的next是否为空
        return head->next == nullptr;
    }
    
    bool push(T e) {
        // 修正：使用构造函数创建新节点
        LinkNode<T> *temp = new LinkNode<T>(e);
        temp->next = head->next;
        head->next = temp;
        return true;
    }
    
    bool pop(T &e) {
        // 修正：不需要创建新节点，直接使用现有节点
        if (head->next == nullptr) {  // 修正：检查栈是否为空
            return false;
        }
        LinkNode<T> *temp = head->next;
        e = temp->data;  // 修正：将节点数据赋给e
        head->next = temp->next;
        delete temp;  // 修正：使用delete而不是delete[]
        return true;
    }
    
    bool gettop(T &e) {
        if (head->next == nullptr) {  // 修正：检查栈是否为空
            return false;
        }
        e = head->next->data;  // 修正：将栈顶数据赋给e
        return true;
    }
};
int main()
{    LinkStack<char> st;                        //定义一个字符链栈st
    char e;
    cout << "建立空栈st\n";
    cout << "栈st" << (st.empty()?"空":"不空") << endl;
    cout << "字符a进栈\n"; st.push('a');
    cout << "字符b进栈\n"; st.push('b');
    cout << "字符c进栈\n"; st.push('c');
    cout << "字符d进栈\n"; st.push('d');
    cout << "字符e进栈\n"; st.push('e');
    cout << "栈st" << (st.empty()?"空":"不空") << endl;
    st.gettop(e);
    cout << "栈顶元素:" << e << endl;
    cout << "所有元素出栈次序:";
    while (!st.empty())        //栈不空循环
    {    st.pop(e);                    //出栈元素e并输出
        cout << e << " ";
    }
    cout << endl;
    cout << "销毁栈st" << endl;
    return 0;
}
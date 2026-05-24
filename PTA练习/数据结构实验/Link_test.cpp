#include <iostream>
using namespace std;
template <typename T>
struct LinkNode                                //单链表结点类型 
{
    T data;                                    //存放数据元素
    LinkNode<T> *next;                        //指向下一个结点的域
    LinkNode():next(NULL) {}                //构造函数 
    LinkNode(T d):data(d),next(NULL) {}        //重载构造函数 
};

template <typename T>
class LinkList                                //单链表类
{
public:
    LinkNode<T> *head;                        //单链表头结点
    LinkList()                                 //构造函数,创建一个空单链表
    {
        head=new LinkNode<T>();
    }
    ~LinkList()                             //析构函数,销毁单链表
    {
        LinkNode<T> *pre,*p;
        pre=head;p=pre->next;
        while (p!=NULL)                        //用p遍历结点并释放其前驱结点 
        {
            delete pre;                        //释放pre结点 
            pre=p; p=p->next;                //pre,p同步后移一个结点 
        }
        delete pre;                        //p为空时pre指向尾结点,此时释放尾结点                        
    }
    void CreateListF(T a[],int n)            //头插法建立单链表
        //创建节点语句：LinkNode<T> * s=new LinkNode<T>(a[i]);    
    {
        for(int i=0;i<n;i++)
        {
            LinkNode<T> *s=new LinkNode<T>(a[i]);
            s->next=head->next;
            head->next=s;
        }
    }
    void CreateListR(T a[],int n)            //尾插法建立单链表
    {
        LinkNode<T> *tail=head;
        for(int i=0;i<n;i++)
        {
            LinkNode<T> *s=new LinkNode<T>(a[i]);
            tail->next=s;
            tail=s;
        }
    }

    void Add(T e)                    //在单链表末尾添加一个值为e的结点 
    {
        LinkNode<T> *add=new LinkNode<T>(e);
        LinkNode<T> *current=head;
        while(current->next!=nullptr)
        {
            current=current->next;
        }
        current->next=add;
        delete current;
    }

    int Getlength()                           //求单链表中数据结点个数，返回节点数目
    {
        LinkNode<T> *temp=head;
        int count=0;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
            count++;
        }
        count+=1;
        return count;
    }

    bool GetElem(int i,T &e)                //求单链表中序号为i的结点值
         //参数i错误返回false，成功找到返回true，没有找到序号i的结点返回false 
    {
        if(i<0||i>n) return false;
        LinkNode<T> *temp=head;
        for(int j=0;j<i;j++)
        {
            if(temp!=nullptr)
            {
                temp=temp->next;
            }
            else
            {
                return false;
                break;
            }
        }
        e=temp->data;
        return true;
    } 

    bool SetElem(int i,T e)                  //设置序号为i的结点值
    { //参数i错误返回false，成功设置返回true
        if(i<0||i>n)
        {
            return false;
        }
        LinkNode<T> *temp=head->next;
        for(int j=0;j<i;j++)
        {
            temp=temp->next;
        }
        temp->data=e;
        return true;
    }

    int GetNo(T e)                            //查找第一个为e的元素的序号
    {//未找到时返回-1，找到后返回其序号
        LinkNode<T> *temp=head->next;
        for(int i=0;i<n;i++)
        {
            if(temp->data==e)
            {
                return i;
            }
        }
        return -1;
    }

    bool Insert(int i,T e)                    //在单链表中序号i位置插入值为e的结点
    {
        //参数i错误返回false，成功插入返回true
        LinkNode<T>* current=new LinkNode<T>(e);
        

    }

    bool Delete(int i)                        //在单链表中删除序号i位置的结点
    { //参数i错误返回false，删除成功返回true 
             

      }

    void DispList()                            //输出单链表所有结点值
    {
        LinkNode<T> *p;
        p=head->next;                        //p指向开始结点
        while (p!=NULL)                        //p不为NULL,输出p结点的data域
        {
            cout << p->data << " ";
            p=p->next;                        //p移向下一个结点
        }
        cout << endl;
    }
private:
    //*******************************************
    //序号i的正确范围：-1<=i<n，超出范围返回NULL
    //i=-1时返回头结点head
    //i≥0并且i<n时返回序号i的结点
    //*******************************************
    LinkNode<T> *geti(int i)                  //返回序号为i的结点
    { //i<-1返回NULL，找到该节点返回该节点指针


    }

};
int main()
{
    LinkList<int> L;
    int i,e;
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    cout << "创建整数单链表L" << endl;
    L.CreateListR(a,n);
    cout << "单链表L:"; L.DispList();    
    cout << "插入元素11在序号0" << endl;
    L.Insert(0,11);                            //插入元素11
    cout << "单链表L:"; L.DispList();
    cout << "插入元素8在末尾" << endl;
    L.Add(8);                                //添加整数8 
    cout << "单链表L:"; L.DispList();
    cout << "长度:" << L.Getlength() << endl;
    i=3; L.GetElem(i,e);
    cout << "序号为" << i << "的元素:" << e << endl;
    e=1;
    cout << "第一个" << e << "的元素序号=" << L.GetNo(e) << "\n";
    i=2; cout << "删除序号为" << i << "的元素\n";
    L.Delete(i);
    cout << "单链表L:";L.DispList();
    cout << "长度:" << L.Getlength() << endl;
    int b[]={0,1,1,0,1};
    for (int i=0;i<5;i++)
    {    cout << "删除序号为" << b[i] << "的元素\n";
        L.Delete(b[i]);
        cout << "单链表L:";L.DispList();
    cout << "长度:" << L.Getlength() << endl;
    }
    cout << "销毁单链表L" << endl;
    return 0;
}

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
    {
        for(int i=0; i<n; i++)
        {
            LinkNode<T> *s = new LinkNode<T>(a[i]);
            s->next = head->next;
            head->next = s;
        }
    }
    
    void CreateListR(T a[],int n)            //尾插法建立单链表
    {
        LinkNode<T> *tail = head;  // tail指向尾节点
        for(int i=0; i<n; i++)
        {
            LinkNode<T> *s = new LinkNode<T>(a[i]);
            tail->next = s;
            tail = s;
        }
    }

    void Add(T e)                    //在单链表末尾添加一个值为e的结点 
    {
        LinkNode<T> *p = head;
        while(p->next != NULL)  // 找到尾节点
        {
            p = p->next;
        }
        LinkNode<T> *s = new LinkNode<T>(e);
        p->next = s;
    }

    int Getlength()                           //求单链表中数据结点个数，返回节点数目
    {
        int count = 0;
        LinkNode<T> *p = head->next;
        while(p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }

    bool GetElem(int i,T &e)                //求单链表中序号为i的结点值
    {
        LinkNode<T> *p = geti(i);
        if(p == NULL)
            return false;
        e = p->data;
        return true;
    } 

    bool SetElem(int i,T e)                  //设置序号为i的结点值
    {
        LinkNode<T> *p = geti(i);
        if(p == NULL)
            return false;
        p->data = e;
        return true;
    } 

    int GetNo(T e)                            //查找第一个为e的元素的序号
    {
        LinkNode<T> *p = head->next;
        int i = 0;
        while(p != NULL)
        {
            if(p->data == e)
                return i;
            p = p->next;
            i++;
        }
        return -1;
    }

    bool Insert(int i,T e)                    //在单链表中序号i位置插入值为e的结点
    {
        LinkNode<T> *pre = geti(i-1);  // 找到第i-1个节点
        if(pre == NULL)
            return false;
        LinkNode<T> *s = new LinkNode<T>(e);
        s->next = pre->next;
        pre->next = s;
        return true;
    }

    bool Delete(int i)                        //在单链表中删除序号i位置的结点
    {
        LinkNode<T> *pre = geti(i-1);  // 找到第i-1个节点
        if(pre == NULL || pre->next == NULL)
            return false;
        LinkNode<T> *p = pre->next;  // p指向要删除的节点
        pre->next = p->next;
        delete p;
        return true;
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
    LinkNode<T> *geti(int i)                  //返回序号为i的结点
    {
        if(i < -1)
            return NULL;
        if(i == -1)
            return head;
        
        LinkNode<T> *p = head->next;
        int count = 0;
        while(p != NULL && count < i)
        {
            p = p->next;
            count++;
        }
        return p;
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
    {    cout << "删除序号为" << i << "的元素\n";
        L.Delete(b[i]);
        cout << "单链表L:";L.DispList();
    cout << "长度:" << L.Getlength() << endl;
    }
    cout << "销毁单链表L" << endl;
    return 0;
}
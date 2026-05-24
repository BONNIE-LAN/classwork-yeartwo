#include<iostream>
#include<vector>
using namespace std;

template <typename T1,typename T2>
struct BSTNode                                            //BST结点类模板 
{    T1 key;                                                //存放关键字,假设关键字为T1类型
    T2 data;                                             //存放数据项,假设数据项为T2类型
    BSTNode *lchild;                                       //存放左孩子指针
    BSTNode *rchild;                                       //存放右孩子指针
    BSTNode(T1 k,T2 d)                                    //构造方法
    {    key=k;
        data=d;
        lchild=rchild=NULL;
    }
};
template <typename T1,typename T2>
class BSTClass                                              //BST类
{
public:
    BSTNode<T1,T2> *r;                                  //BST根结点
    BSTNode<T1,T2> *f;                                    //用于存放待删除结点的双亲结点
    BSTClass()                                             //构造方法
    {    r=NULL;                                          //BST根结点
        f=NULL;                                            //用于存放待删除结点的双亲结点
    }
    ~BSTClass()                                            //析构函数
    {
        DestroyBTree(r);                                //调用DestroyBTree()函数
        r=NULL;
    }
    void DestroyBTree(BSTNode<T1,T2> *b)                //释放所有的结点空间
    {
        if (b!=NULL)
        {
            DestroyBTree(b->lchild);                    //递归释放左子树
            DestroyBTree(b->rchild);                    //递归释放右子树
            delete b;                                    //释放根结点
        }
    }
    //BST的基本运算算法
    void InsertBST(T1 k,T2 d)                            //插入一个(k,d)结点
    {
        r=_InsertBST(r,k,d);
    }

    BSTNode<T1,T2> *_InsertBST(BSTNode<T1,T2> *p,T1 k,T2 d)   //在以p为根的BST中插入关键字为k的结点
    {    //return p
        if(p==NULL)
        {
            return new BSTNode<T1,T2>(k,d);
        }
        if(k<p->key)
        {
            p->lchild=_InsertBST(p->lchild,k,d);
        }
        else if(k>p->key)
        {
            p->rchild=_InsertBST(p->rchild,k,d);
        }
        return p;
    }

    void CreateBST(vector<T1> &a,vector<T2> &b)            
    //由a和b向量创建一棵BST，a为关键字集合，b为其他data集合
    {  
        for(size_t i=0;i<a.size()&&i<b.size();i++)
        {
            InsertBST(a[i],b[i]);
        }  
    }
    BSTNode<T1,T2> *SearchBST(T1 k)                        //在BST中查找关键字为k的结点
    {
        return _SearchBST(r,k);                            //r为BST的根结点
    }

    BSTNode<T1,T2> *_SearchBST(BSTNode<T1,T2> *p,T1 k)     //被SearchBST方法调用
    {    //空树返回null
        //找到后返回p
        if(p==NULL)
        {
            return NULL;
        }
        if(k==p->key)
        {
            return p;
        }
        if(k<p->key)
        {
            return _SearchBST(p->lchild,k);
        }
        return _SearchBST(p->rchild,k);
    }

    bool DeleteBST(T1 k)                                //删除关键字为k的结点
    {    f=NULL;
        return _DeleteBST(r,k,-1);                        //r为BST的根结点
    }

    bool _DeleteBST(BSTNode<T1,T2> *p,T1 k,int flag)      //被DeleteBST方法调用
    //flag==-1为根，flag==0，p为f的左孩子，flag==1，p为f的右孩子
    {    if (p==NULL)
            return false;                                //空树返回False
        if (p->key==k)
            return DeleteNode(p,f,flag);                //找到后删除p结点
        if (k<p->key)
        {    f=p;
            return _DeleteBST(p->lchild,k,0);            //在左子树中递归查找
        }
        else
        {    f=p;
            return _DeleteBST(p->rchild,k,1);            //在右子树中递归查找
        }
    }

    bool DeleteNode(BSTNode<T1,T2> *p,BSTNode<T1,T2> *f,int flag) //删除结点p（其双亲为f）
   //flag==-1为根，flag==0，p为f的左孩子，flag==1，p为f的右孩子
    {  
        BSTNode<T1,T2> *child=NULL;
        if(p->lchild==NULL && p->rchild==NULL)
        {
            child=NULL;
        }
        else if(p->lchild==NULL)
        {
            child=p->rchild;
        } 
        else if(p->rchild==NULL)
        {
            child=p->lchild;
        } 
        else
        {
            BSTNode<T1,T2> *s=p;
            BSTNode<T1,T2> *q=p->lchild;
            int qflag=0;
            while(q->rchild!=NULL)
            {
                s=q;
                q=q->rchild;
                qflag=1;
            }
            p->key=q->key;
            p->data=q->data;
            return DeleteNode(q,s,qflag);
        }
        if(flag==-1)
        {
            r=child;
        }
        else if(flag==0)
        {
            f->lchild=child;
        }
        else
        {
            f->rchild=child;
        }
        delete p;
        return true;
    }

    void DispBST()                                        //输出BST的括号表示串(不含data)
    {
        _DispBST(r);
    }
    void  _DispBST(BSTNode<T1,T2> *p)                   //被DispBST方法调用
    {    if (p!=NULL)
        {    cout << p->key;                                //输出根结点值
            if (p->lchild!=NULL || p->rchild!=NULL)
            {    cout << "(";                               //有孩子结点时才输出"("
                _DispBST(p->lchild);                    //递归处理左子树
                if (p->rchild!=NULL)
                    cout << ",";                           //有右孩子结点时才输出","
                _DispBST(p->rchild);                    //递归处理右子树
                cout << ")";                               //有孩子结点时才输出")"
            }
        }
    }
 
};

int main()
{
    vector<int> a={25,18,46,2,53,39,32,4,74,67,60,11};
    vector<int> b={1,1,1,1,1,1,1,1,1,1,1,1};
    cout << "\n  (1)关键字序列\n    ";
    for (int i=0;i<a.size();i++)
        cout << a[i] << " ";
    cout << endl; 
    BSTClass<int,int> bst;
    cout << "  (2)创建BSTbst\n"; 
    bst.CreateBST(a,b);
    cout << "  (3)输出BST\n";
    cout << "    BST: ";bst.DispBST(); cout << endl;
    cout << "  (4)删除操作\n";
    vector<int> c={2,4,60,25,32,11};
    for (int i=0;i<c.size();i++)
    {
        bst.DeleteBST(c[i]);
        printf("    删除%2d后: ",c[i]); bst.DispBST(); cout << endl;
    }
    cout << "  (5)插入操作\n";
    vector<int> d={32,11,1};
    for (int i=0;i<d.size();i++)
    {
        bst.InsertBST(d[i],b[i]);
        printf("    插入%2d后: ",d[i]); bst.DispBST(); cout << endl;
    }
        
    return 0;
}

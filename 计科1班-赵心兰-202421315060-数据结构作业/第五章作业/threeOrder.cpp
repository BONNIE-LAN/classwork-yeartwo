#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
template<typename T>
struct BTNode
{
    T data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode(){lchild=rchild=nullptr;}
    BTNode(T d):data(d),lchild(nullptr),rchild(nullptr){}
};
template <typename T>
class BTree
{
    public:
    BTNode<T>* root;
    BTree()
    {
        root=nullptr;
    }
    //从后序和中序序列构建二叉树
    BTNode<T>* buildTree(vector<T>& postorder,vector<T>& inorder,int postStart,int postEnd,int inStart,int inEnd);
    //前序遍历输出
    void Preorderdisplay(BTNode<T>* r);
};
template <typename T>
BTNode<T>* BTree<T>::buildTree(vector<T>& postorder,vector<T>& inorder,int postStart,int postEnd,int inStart,int inEnd)
{
    if(postStart>postEnd||inStart>inEnd) return nullptr;
    //后序序列的最后一个元素是根节点
    T rootVal=postorder[postEnd];
    BTNode<T>* root=new BTNode<T>(rootVal);
    //在中序序列中找到根节点的位置
    int rootIndex=inStart;
    for(int i=inStart;i<=inEnd;i++)
    {
        if(inorder[i]==rootVal)
        {
            rootIndex=i;
            break;
        }
    }
    //计算左子树和右子树的节点数量
    int leftSize=rootIndex-inStart;
    int rightSize=inEnd-rootIndex;
    //递归构建左子树和右子树
    root->lchild=buildTree(postorder,inorder,postStart,postStart+leftSize-1,inStart,rootIndex-1);
    root->rchild=buildTree(postorder,inorder,postStart+leftSize,postEnd-1,rootIndex+1,inEnd);
    return root;
}
template <typename T>
void BTree<T>::Preorderdisplay(BTNode<T>* r)
{
    if(r==nullptr) return;
    cout<<r->data;
    if(r->lchild!=nullptr||r->rchild!=nullptr) cout<<" ";
    Preorderdisplay(r->lchild);
    if(r->lchild!=nullptr&&r->rchild!=nullptr) cout<<" ";
    Preorderdisplay(r->rchild);
}
int main()
{
    int treeNumber;
    while(true)
    {
        cout<<"Please enter the number of tree"<<endl;
        cin>>treeNumber;
        if(treeNumber==-1) break;
        for(int t=0;t<treeNumber;t++)
        {
            int n;
            cout<<"Please enter the size of the postorder sequence"<<endl;
            cin>>n;
            vector<int> postorder(n);
            cout<<"Please enter the postorder sequence"<<endl;
            for(int i=0;i<n;i++)
            {
                cin>>postorder[i];
            }
            vector<int> inorder(n);
            cout << "Please enter the inorder sequence" << endl;
            for(int i = 0; i < n; i++)
            {
                cin >> inorder[i];
            }
            
            BTree<int> tree;
            tree.root = tree.buildTree(postorder, inorder, 0, n-1, 0, n-1);
            tree.Preorderdisplay(tree.root);
            cout << endl;
        }
    }
    return 0;
}
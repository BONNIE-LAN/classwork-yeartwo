#include<iostream>
using namespace std;
//二叉树节点
struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val):data(val),left(nullptr),right(nullptr){};
};
//插入节点
BSTNode* Insert(BSTNode* root,int val)
{
    if(root==nullptr)
    {
        BSTNode* node=new BSTNode(val);
        return node;
    }
    if(val<root->data)
    {
        root->left=Insert(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=Insert(root->right,val);
    }
    return root;
}
//查找结点
bool Search(BSTNode* root,int val)
{
    if(root==nullptr)
    {
        return false;
    }
    if(root->data==val)
    {
        return true;
    }
    if(val<root->data)
    {
        return Search(root->left,val);
    }
    else
    {
        return Search(root->right,val);
    }
}
//查找最小结点(用于删除操作)
BSTNode* FindMin(BSTNode* root)
{
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root;
}
//删除结点
BSTNode* Delete(BSTNode* root,int val)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    if(val<root->data)
    {
        root->left=Delete(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=Delete(root->right,val);
    }
    else
    {
        //case1:只有右子树或无子树
        if(root->left==nullptr)
        {
            BSTNode* temp=root->right;
            delete root;
            return temp;
        }
        //case2:只有左子树
        else if(root->right==nullptr)
        {
            BSTNode* temp=root->left;
            delete root;
            return temp;
        }
        //case3:左右子树都存在
        BSTNode* temp=FindMin(root->right);
        root->data=temp->data;
        root->right=Delete(root->right,temp->data);
    }
    return root;
}
//释放内存
void DestroyTree(BSTNode* root)
{
    if(root==nullptr) return;
    DestroyTree(root->left);
    DestroyTree(root->right);
    delete root;
}
int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==-1)
        {
            break;
        }
        BSTNode* root=nullptr;
        //建立二叉查找树
        for(int i=0;i<n;i++)
        {
            int val;
            cin>>val;
            root=Insert(root,val);
        }
        //输入待插入的元素
        int key;
        cout<<"Please enter the element you want to insert: ";
        cin>>key;
        root=Insert(root,key);
        //查找元素
        int find;
        cout<<"Please enter the element you want to find: ";
        cin>>find;
        if(Search(root,find))
        {
            cout<<"Successful find"<<endl;
        }
        else
        {
            cout<<"Failed to find"<<endl;
        }
        //删除元素
        int del;
        cout<<"Please enter the element you want to delete: ";
        cin>>del;
        root=Delete(root,del);
        //再次查找
        if(Search(root,del))
        {
            cout<<"Successful find"<<endl;
        }
        else
        {
            cout<<"The element was deleted and failed to find"<<endl;
        }
        DestroyTree(root);
    }
    return 0;
}
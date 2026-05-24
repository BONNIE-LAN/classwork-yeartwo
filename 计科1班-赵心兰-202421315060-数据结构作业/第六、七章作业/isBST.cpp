#include<iostream>
using namespace std;
//二叉树结点
struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){data=val;left=right=nullptr;}
};
//创建树
TreeNode* createTree()
{
    int x;
    cin>>x;
    if(x==0) //0表示空子树
    {
        return nullptr;
    }
    TreeNode* node=new TreeNode(x);
    node->left=createTree();
    node->right=createTree();
    return node;
}
//利用中序遍历判断是否是二叉查找树
bool isBST(TreeNode* root,int& prev)
{
    if(root==nullptr)
    {
        return true;
    }
    //判断左子树
    if(!isBST(root->left,prev))
    {
        return false;
    }
    //判断当前结点
    if(root->data<=prev)
    {
        return false;
    }
    prev=root->data;
    //判断右子树
    return isBST(root->right,prev);
}
//释放二叉树内存
void DestroyTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return;
    }
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
        for(int i=0;i<n;i++)
        {
            TreeNode* root=createTree();
            int prev=-1e9;//设置一个足够小的初值
            if(isBST(root,prev))
            {
                cout<<"is Binary search Tree"<<endl;
            }
            else
            {
                cout<<"is not Binary search Tree"<<endl;
            }
            DestroyTree(root);
        }
    }
    return 0;
}
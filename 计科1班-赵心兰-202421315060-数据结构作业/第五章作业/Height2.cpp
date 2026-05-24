#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct BTNode
{
    int data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode() {lchild=rchild=nullptr;}
    BTNode(int d):data(d),lchild(nullptr),rchild(nullptr){}
};
class BTree
{
    public:
    BTNode* root;
    int GetHeight(BTNode* node);
    BTNode* buildTree(vector<int> preorder,int& index);
    void LevelOrder(BTNode* root);
};
int BTree::GetHeight(BTNode* node)
{
    if(node==nullptr) return -1;
    return max(GetHeight(node->lchild),GetHeight(node->rchild))+1;
}
BTNode* BTree::buildTree(vector<int> preorder,int& index)
{
    if(index>=preorder.size()||preorder[index]==0)
    {
        index++;
        return nullptr;
    }
    BTNode* root=new BTNode(preorder[index]);
    index++;
    root->lchild=buildTree(preorder,index);
    root->rchild=buildTree(preorder,index);
    return root;
}
void BTree::LevelOrder(BTNode* root)
{
    if(root==nullptr) return;
    queue<BTNode*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        BTNode* current=Q.front();
        if(abs(GetHeight(current->lchild)-GetHeight(current->rchild))==2)
        {
            cout<<current->data<<" ";
        }
        if(current->lchild!=nullptr) Q.push(current->lchild);
        if(current->rchild!=nullptr) Q.push(current->rchild);
        Q.pop();
    }
}
int main()
{
    int treeNumber;
    while(true)
    {
        cout<<"Please enter the number of tree"<<endl;
        cin>>treeNumber;
        if(treeNumber==-1) break;
        for(int i=0;i<treeNumber;i++)
        {
            int n;
            cout<<"Please enter the size of the preorder"<<endl;
            cin>>n;
            vector<int> preorder(n);
            cout<<"Please enter the postorder sequence"<<endl;
            for(int i=0;i<n;i++)
            {
                cin>>preorder[i];
            }
            BTree tree;
            int index=0;
            tree.root=tree.buildTree(preorder,index);
            tree.LevelOrder(tree.root);
            cout<<endl;
        }
    }
    return 0;
}

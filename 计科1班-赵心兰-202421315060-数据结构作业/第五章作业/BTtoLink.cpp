#include<iostream>
#include<vector>
using namespace std;
struct BTNode //二叉树的节点
{
    int data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode() {lchild=rchild=nullptr;}
    BTNode(int d):data(d),lchild(nullptr),rchild(nullptr){}
};
struct LinkNode //单链表节点
{
    int data;
    LinkNode* next;
    LinkNode() {next=nullptr;}
    LinkNode(int d):data(d),next(nullptr){}
};
class BTree
{
    public:
    BTNode* root;//根节点
    LinkNode* head;//单链表头节点
    LinkNode* tail;//单链表尾节点
    BTree()//构造函数
    {
        root=nullptr;
        head=nullptr;
        tail=nullptr;
    }
    BTNode* CreateBTree(vector<int>& arr, int& index);//根据前序遍历序列创造二叉树
    void findLeaves(BTNode* node); // 找到所有叶子节点并链接成单链表
    void display();//输出单链表
};
BTNode* BTree::CreateBTree(vector<int>& arr, int& index)
{
    if(index >= arr.size() || arr[index] == 0)
    {
        index++;
        return nullptr;
    }
    BTNode* newNode = new BTNode(arr[index++]);
    newNode->lchild = CreateBTree(arr, index);
    newNode->rchild = CreateBTree(arr, index);
    return newNode;
}
//递归遍历找到所有叶子节点并链接成单链表（前序遍历方式）
void BTree::findLeaves(BTNode* node)
{
    if(node == nullptr)
    {
        return;
    }
    // 如果是叶子节点，添加到单链表中
    if(node->lchild == nullptr && node->rchild == nullptr)
    {
        LinkNode* newNode = new LinkNode(node->data);
        if(head == nullptr) // 第一个节点
        {
            head = newNode;
            tail = newNode;
        }
        else // 链接到链表末尾
        {
            tail->next = newNode;
            tail = newNode;
        }
        return;
    }
    // 递归遍历左子树
    if(node->lchild != nullptr)
    {
        findLeaves(node->lchild);
    }
    // 递归遍历右子树
    if(node->rchild != nullptr)
    {
        findLeaves(node->rchild);
    }
}
void BTree::display()
{
    LinkNode* current = head;
    while(current != nullptr)
    {
        cout << current->data;
        if(current->next != nullptr)
        {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}
int main()
{
    int treeNumber;
    while(true)
    {
        cout<<"Please enter the number of binary tree (input -1 to exit)"<<endl;
        cin>>treeNumber;
        if(treeNumber == -1)
        {
            break; // 输入-1终止程序
        }
        if(treeNumber <= 0)
        {
            continue; // 无效输入，继续循环
        }
        BTree* tree = new BTree[treeNumber];
        for(int t = 0; t < treeNumber; t++)
        {
            cout<<"Please enter the size of the binary tree array"<<endl;
            int n;
            cin >> n;
            cout<<"Please enter the numbers in the binary tree (0 for null node)"<<endl;
            vector<int> number;
            for(int i = 0; i < n; i++)
            {
                int val;
                cin >> val;
                number.push_back(val);
            }
            int index = 0;
            tree[t].root = tree[t].CreateBTree(number, index);
            tree[t].findLeaves(tree[t].root);
            tree[t].display();
        }
        delete[] tree;
    }
    return 0;
}


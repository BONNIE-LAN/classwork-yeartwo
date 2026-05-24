#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct BTNode
{
    char data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode() { lchild = rchild = NULL; }
    BTNode(char d) { data = d; lchild = rchild = NULL; }
};

class BTree
{
public:
    BTNode *r;
    BTree() { r = NULL; }

    ~BTree()
    {
        DestroyBTree(r);
        r = NULL;
        cout << "销毁二叉树" << endl;
    }

    void DestroyBTree(BTNode *b)
    {
        if (!b) return;
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        delete b;
    }

    // 用括号表示法创建二叉树，例如 A(B(D(,G)),C(E,F))
    void CreateBTree(const string &str)
    {
        stack<BTNode*> st;
        BTNode *p = nullptr;
        int k = 0; // 1 表示接下来是左孩子，2 表示右孩子

        for (size_t i = 0; i < str.length(); ++i)
        {
            char ch = str[i];
            if (isalpha(static_cast<unsigned char>(ch)) || isdigit(static_cast<unsigned char>(ch)))
            {
                p = new BTNode(ch);
                if (!r) r = p;
                else
                {
                    if (!st.empty())
                    {
                        BTNode *parent = st.top();
                        if (k == 1) parent->lchild = p;
                        else if (k == 2) parent->rchild = p;
                    }
                }
            }
            else if (ch == '(')
            {
                st.push(p);
                k = 1;
            }
            else if (ch == ',')
            {
                k = 2;
            }
            else if (ch == ')')
            {
                if (!st.empty()) st.pop();
            }
        }
    }

    void DispBTree() { DispBTree1(r); }

    // 修正后的输出：只在应当显示逗号时输出逗号
    void DispBTree1(BTNode *b)
    {
        if (!b) return;
        cout << b->data;
        // 只有当至少有一个子节点存在时才输出括号
        if (b->lchild != NULL || b->rchild != NULL)
        {
            cout << "(";
            // 左子树存在就输出左子树
            if (b->lchild)
            {
                DispBTree1(b->lchild);
            }
            // 如果右子树存在，需要输出逗号分隔（无论左子树是否存在）
            if (b->rchild)
            {
                cout << ",";
                DispBTree1(b->rchild);
            }
            cout << ")";
        }
    }

    BTNode *FindNode(char x) { return FindNode1(r, x); }

    BTNode *FindNode1(BTNode *b, char x)
    {
        if (!b) return NULL;
        if (b->data == x) return b;
        BTNode *p = FindNode1(b->lchild, x);
        if (p) return p;
        return FindNode1(b->rchild, x);
    }

    int Height() { return Height1(r); }

    int Height1(BTNode *b)
    {
        if (!b) return 0;
        int hl = Height1(b->lchild);
        int hr = Height1(b->rchild);
        return (hl > hr ? hl : hr) + 1;
    }
};

int main()
{
    string str;
    if (!(cin >> str)) return 0;
    char x;
    cin >> x;

    BTree bt;
    bt.CreateBTree(str);
    cout << "二叉树bt:"; bt.DispBTree(); cout << endl;
    cout << "bt的高度:" << bt.Height() << endl;
    if (bt.FindNode(x))
        cout << "bt中找到值为" << x << "的结点" << endl;
    else
        cout << "bt中没有找到值为" << x << "的结点" << endl;

    return 0;
}

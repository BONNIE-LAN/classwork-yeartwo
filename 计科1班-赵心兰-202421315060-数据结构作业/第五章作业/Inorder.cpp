#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void preorderTraversal(vector<int>& tree, int n)
{
    stack<int> s;
    int i = 0;
    vector<int> result;

    while (i != -1 || !s.empty())
    {
        while (i < n && i != -1)
        {
            // 先访问当前结点
            result.push_back(tree[i]);

            // 入栈，之后回来找右孩子
            s.push(i);

            // 转向左孩子
            i = 2 * i + 1;
        }

        if (!s.empty())
        {
            i = s.top();
            s.pop();

            // 转向右孩子
            i = 2 * i + 2;
            if (i >= n) i = -1;
        }
    }

    for (int j = 0; j < result.size(); j++)
    {
        cout << result[j];
        if (j != result.size() - 1) cout << " ";
    }
    cout << endl;
}

void inorderTravelsal(vector<int>& tree,int n)
{
    stack<int> s;
    int i=0;//从根节点开始
    bool visited[1000]={false};//标记节点是否已被访问
    vector<int> result;
    while(i!=-1||!s.empty())
    {
        //一直向左走到底
        while(i<n &&i!=-1)
        {
            s.push(i);
            // 计算左字节点索引：2*i+1
            i=2*i+1;
        }
        //如果栈不空
        if(!s.empty())
        {
            i=s.top();
            s.pop();
            //输出当前节点
            result.push_back(tree[i]);
            //转向右子树：2*i+2
            i=2*i+2;
            //检查右子树是否已经处理过或者不存在
            if(i>=n)
            {
                i=-1;
            }
        }
    }
    for(int j=0;j<result.size();++j)
    {
        cout<<result[j];
        if(j!=result.size()-1) cout<<" ";
    }
    cout<<endl;
}
void postorderTraversal(vector<int>& tree, int n)
{
    if (n == 0) return;

    stack<int> s1, s2;
    vector<int> result;

    s1.push(0); // 根结点下标

    while (!s1.empty())
    {
        int i = s1.top();
        s1.pop();
        s2.push(i);

        // 左孩子
        int left = 2 * i + 1;
        if (left < n)
            s1.push(left);

        // 右孩子
        int right = 2 * i + 2;
        if (right < n)
            s1.push(right);
    }

    // s2 中的顺序即为后序
    while (!s2.empty())
    {
        result.push_back(tree[s2.top()]);
        s2.pop();
    }

    for (int j = 0; j < result.size(); j++)
    {
        cout << result[j];
        if (j != result.size() - 1) cout << " ";
    }
    cout << endl;
}
void levelOrderTraversal(vector<int>& tree, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tree[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    while(cin>>n && n!=-1)
    {
        vector<int> tree(n);
        //输入二叉树的节点数据
        for(int i=0;i<n;i++)
        {
            cin>>tree[i];
        }
        //进行中序遍历
        inorderTravelsal(tree,n);
    }
    return 0;
}

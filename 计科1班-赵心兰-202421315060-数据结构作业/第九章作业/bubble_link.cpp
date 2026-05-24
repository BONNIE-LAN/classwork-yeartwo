#include<iostream>
using namespace std;
//链表节点
struct ListNode
{
    int data;
    ListNode* next;
};
//创建新节点
ListNode* createNode(int val)
{
    ListNode* node=new ListNode();
    node->data=val;
    node->next=nullptr;
    return node;
}
//尾插法
void insertAtEnd(ListNode*& head,int val)
{
    if(!head)
    {
        head=createNode(val);
        return;
    }
    ListNode* temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=createNode(val);
}
//打印链表
void printList(ListNode* head)
{
    if(head==nullptr)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    cout<<endl;
}
//负责比较相邻节点，并将最大值排到最后
bool bubbleOnce(ListNode* head)
{
    bool swapped=false;
    ListNode* cur=head;
    while(cur&&cur->next)
    {
        if(cur->data>cur->next->data)
        {
            int temp=cur->data;
            cur->data=cur->next->data;
            cur->next->data=temp;
            swapped=true;
        }
        cur=cur->next;
    }
    return swapped;
}
//递归处理多轮冒泡
ListNode* bubbleSort(ListNode* head)
{
    //空链表或只有一个节点
    if(!head||!head->next)
    {
        return head;
    }
    //做一轮冒泡
    bool swapped=bubbleOnce(head);
    //如果这一轮发生交换，继续下一轮
    if(swapped)
    {
        bubbleSort(head);
    }
    return head;
}
//主函数
int main()
{
    ListNode* head=nullptr;
    while(true)
    {
        int input;
        cin>>input;
        if(input==-1) break;
        if(input==0)
        {
            //输入结束
            if(!head)
            {
                cout<<"Empty Link"<<endl;
            }
            else
            {
                cout<<"Before sorting: ";
                printList(head);
                //排序
                head=bubbleSort(head);
                cout<<"After serting: ";
                printList(head);
            }
            //清空链表，准备下一轮输入
           while(head)
           {
                ListNode* temp=head;
                head=head->next;
                delete temp;
            }
        }
        else
        {
            //创建链表
            insertAtEnd(head,input);
        }
    }
    return 0;
}
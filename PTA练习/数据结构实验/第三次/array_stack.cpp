#include <iostream>
using namespace std;
const int MaxSize=100;  //栈的容量 
template <typename T>
class SqStack                    //顺序栈类
{
    T *data;                    //存放栈中元素
    int top;                       //栈顶指针
public:
    SqStack()                    //构造函数
    {
        data=new T[MaxSize];    //为data分配容量为MaxSize的空间
        top=-1;                    //栈顶指针初始化
    }
    ~SqStack()                    //析构函数
    {
        delete [] data;
    }
    bool empty()                //判断栈是否为空
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool push(T e)                //进栈算法
    {//栈满时返回false
      //成功进栈返回true
        if(top==MaxSize-1)
        {
            return false;
        }
        top++;
        data[top]=e;
        return true;
    }
    bool pop(T &e)                //出栈算法
    {
    //栈为空的情况，即栈下溢出，返回false
    //出栈成功返回true
        if(top==-1)
        {
            return false;
        }
        e=data[top];
        top--;
        return true;
    
    }
    bool gettop(T &e)            //取栈顶元素算法
    {
        //栈为空的情况，即栈下溢出，返回false
        //取到栈顶返回true
        if(top==-1)
        {
            return false;
        }
        e=data[top];
        return true;
    }
 };
int main()
{    SqStack<char> st;            //定义一个字符顺序栈st
    char e;
    cout << "建立空栈st\n";
    cout << "栈st" << (st.empty()?"空":"不空") << endl;
    cout << "字符a进栈\n"; st.push('a');
    cout << "字符b进栈\n"; st.push('b');
    cout << "字符c进栈\n"; st.push('c');
    cout << "字符d进栈\n"; st.push('d');
    cout << "字符e进栈\n"; st.push('e');
    cout << "栈st" << (st.empty()?"空":"不空") << endl;
    st.gettop(e);
    cout << "栈顶元素:" << e << endl;
    cout << "所有元素出栈次序:";
    while (!st.empty())            //栈不空循环
    {    st.pop(e);                //出栈元素e并输出
        cout << e << " ";
    }
    cout << endl;
    cout << "销毁栈st" << endl;
    return 0;
}
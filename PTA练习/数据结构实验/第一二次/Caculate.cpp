#include<iostream>
using namespace std;
template <typename T>
class Caculate
{
    public:
    Caculate()
    {
       cin>>number1>>number2;
    }
    T getMax()
    {
        if(number1>number2)
        {
            return number1;
        }
        else
        {
            return number2;
        }
    }
    T getMin()
    {
        if(number1<number2)
        {
            return number1;
        }
        else
        {
            return number2;
        }
    }
    T getSum()
    {
        return number1+number2;
    }
    T getJian()
    {
        return number1-number2;
    }
    T getMutiple()
    {
        return number1*number2;
    }
    T getDivide()
    {
        return number1/number2;
    }
    void display()
    {
        cout<<getMax()<<" "<<getMin()<<" "<<getSum()<<" "<<getJian()<<" "<<getMutiple()<<" "<<getDivide()<<" "<<endl;
    }
    private:
    T number1;
    T number2;
};
int main()
{
    Caculate<int> n1;
    Caculate<float> n2;
    n1.display();
    n2.display();
    return 0;
}

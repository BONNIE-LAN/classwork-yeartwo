from math import sqrt
def area(a,b,c):
    if(a+b<=c or a+c<=b or b+c<=a):
        print("数据错误")
        return 0
    else:
        p = (a+b+c)/2
        S = sqrt( p*(p-a)*(p-b)*(p-c) )
        print("{:.2f}".format(S))      
        return S 
a=eval(input())
b=eval(input())
c=eval(input())
area(a,b,c)
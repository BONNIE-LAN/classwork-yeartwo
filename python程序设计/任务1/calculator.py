def calculator(x,y,op):
    if(op=="+"):
        return x+y
    if(op=="-"):
        return x-y
    if(op=="*"):
        return x*y
    if(op=="/"):
        if(y==0):
            print("除数不能为0")
            return None
        else:
            return x/y
while True:
    try:
        num1,num2,op=input("请输入整数运算符和运算符：").split()
        num1,num2=int(num1),int(num2)
        result=calculator(num1,num2,op)
        if result is not None:
            print("结果:{:.2f}".format(result))
        break
    except ValueError:
        print("输入错误,请输入俩个整数和一个运算符")





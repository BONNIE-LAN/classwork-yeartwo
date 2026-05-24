#创建Person类
class Person:
    def __init__(self,n,a,s):
        self.name=n
        self.age=a
        self.sex=s
    def personInfo(self):
        print("姓名为：{}，年龄为：{}，性别为：{}".format(self.name,self.age,self.sex))
#创建student类
class Student(Person):
    def __init__(self, n, a, s,college,class_name):
        super().__init__(n, a, s)
        self.college=college
        self.class_name=class_name
    def personInfo(self):
        #调用父类的方法
        super().personInfo()
        print("学院：{}，班级：{}".format(self.college,self.class_name))
#创建Teacher类，继承自Person
class Teacher(Person):
    def __init__(self, n, a, s,college,pro):
        super().__init__(n, a, s)
        self.college=college
        self.pro=pro
    def personInfo(self):
        super().personInfo()
        print("学院：{}，专业：{}".format(self.college,self.pro))
#定义一个函数Info，实现多态
def Info(obj):
    obj.personInfo()
#分别创建对象
p=Person('张三',30,'男')
s=Student('李四',20,'女','计算机学院','计科1班')
t=Teacher('王五',40,'男','外国语学院','英语专业')
#调用函数Info，实现多态
Info(p)
print('-'*30)
Info(s)
print('-'*30)
Info(t)

        


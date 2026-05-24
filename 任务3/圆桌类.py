import math
#创建圆类
class Circle:
    def __init__(self,R):
       self.Radius=R
    def getArea(self):
        return math.pi*(self.Radius**2)
#创建桌子类
class Table:
    def __init__(self,H):
        self.Heigt=H
    def getHeight(self):
        return self.Heigt
#派生出圆桌类
class RoundTable(Circle,Table):
    def __init__(self,r,h,c):
        Circle.__init__(self,r)
        Table.__init__(self,h)
        self.color=c
    def info(self):
        print('圆桌的面积为：{:.2f},高度为：{},颜色为：{}'.format(self.getArea(),self.getHeight(),self.color))
RT1=RoundTable(2,4,'红色')
RT1.info()

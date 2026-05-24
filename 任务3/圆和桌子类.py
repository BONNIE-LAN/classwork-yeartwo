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
c1=Circle(2)
t1=Table(4)
c2=Circle(4)
t2=Table(8)
print(f"圆的面积: {c1.getArea():.2f}")
print(f"桌子的高度: {t1.getHeight()}")
print(f"圆的面积: {c2.getArea():.2f}")
print(f"桌子的高度: {t2.getHeight()}")
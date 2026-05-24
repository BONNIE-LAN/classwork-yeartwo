x=eval(input())
if(x<=0):
    y=0
if(x<=15):
    y=(4*x)/3
else:
   y=2.5*x-17.5
print("{:.2f}".format(y))
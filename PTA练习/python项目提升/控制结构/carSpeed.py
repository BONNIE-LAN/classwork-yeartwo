carSpeed=eval(input())
limitSpeed=eval(input())
rate=(carSpeed-limitSpeed)/limitSpeed
if(carSpeed<=limitSpeed):
    print("未超速")
elif(rate<=0.1):
    print("超速警告")
elif(rate>0.1 and rate<=0.2):
    print("罚款100元")
elif(rate>0.2 and rate<=0.5):
    print("罚款500元")
elif(rate>0.5 and rate<=1):
    print("罚款1000元")
else:
    print("罚款2000元")
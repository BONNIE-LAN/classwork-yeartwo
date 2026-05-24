score=eval(input())
if(score<0 or score>100):
    print("输入成绩有误！")
    exit()
elif(score>=0 and score<60):
    GPA=0
    grade="E"
elif(score>=60 and score<70):
    GPA=1.0+(score-60)*0.1
    grade="D"
elif(score>=70 and score<80):
    GPA=2.0+(score-70)*0.1
    grade="C"
elif(score>=80 and score<90):
    GPA=3.0+(score-80)*0.1
    grade="B"
elif(score>=90 and score<=100):
    PA=4.0+(score-90)*0.1
    grade="A"
print("{}分对应的绩点为{:.2f}, 等级为{}。".format(score,GPA,grade))
    
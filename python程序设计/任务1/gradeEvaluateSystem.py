A=0
B=0
C=0
D=0
E=0
#评估等级
def EvaluateScore(s):
    global A,B,C,D,E
    if(s>=90 and s<=100):
        grade="优秀"
        A=A+1
    elif(s>=80 and s<90):
        grade="良好"
        B=B+1
    elif(s>=70 and s<80):
        grade="中等"
        C=C+1
    elif(s>=60 and s<70):
        grade="及格"
        D=D+1
    elif(s<60 and s>=0):
        grade="不及格"
        E=E+1
    return grade
#排序成绩
def sortScores(s):
    s_sorted=sorted(s,reverse=True)
    print("这是从高到低排序的成绩：")
    for score in s_sorted:
        print(score)
    return s_sorted
#查询成绩区间的学生
def search(s,n):
    upScope=eval(input("请输入你想要查询的成绩区间上限："))
    downScope=eval(input("请输入你想要查询的成绩区间下限："))
    found=False
    for i in range(len(s)):
        if downScope<=s[i]<=upScope:
            print(f"{n[i]}: {s[i]}")
            found=True
    if not found:
        print("没有查询到该区间的成绩")
    return " "
print("===== 学生成绩评定系统 =====")
print("请输入学生成绩(0-100)，输入-1结束录入")
i=1
sum=0
scores=[]
names=[]
while(True):
    try:
        score=eval(input("请输入第{}位学生的成绩：".format(i)))
        if(score==-1):
            break
        else:
            name=input("请输入学生的姓名：")
            scores.append(score)
            names.append(name)
            grade=EvaluateScore(score)
            print("学生{}：成绩{:.1f}-> 等级：{}".format(i,score,grade))
            i=i+1
            sum=sum+score
    except:
        print("请输入有效的数字")
print("===== 成绩统计报告 =====")
print("学生总数：",i-1)
print("平均成绩：{:.2f}".format(sum/(i-1)))
print("优秀人数：{}({:.2f}%)".format(A,(A/(i-1))*100))
print("良好人数：{}({:.2f}%)".format(B,(B/(i-1))*100))
print("中等人数：{}({:.2f}%)".format(C, (C/(i-1))*100))
print("及格人数：{}({:.2f}%)".format(D,(D/(i-1))*100))
print("不及格人数：{}({:.2f}%)".format(E,(E/(i-1))*100))
print("总体评价: 班级整体表现良好！")
print("这是学生的姓名和对应的成绩：")
for name,score in zip(names,scores):
    print(f"{name}:{score}")
sortScores(scores)
search(scores,names)





courses=[]
while True:
    line = input()
    if line == "":  # 输入空行，结束录入
        break

    # 拆分每行的信息
    parts = line.split()
    name, score = parts[0], int(parts[1])
    courses.append((name, score))  # 存为元组形式
BestScore=courses[0][1]
BestName=courses[0][0]
worstScore=courses[0][1]
worstName=courses[0][0]
sum=0
for i in range(len(courses)):
    if courses[i][1]>BestScore:
        BestScore=courses[i][1]
        BestName=courses[i][0]
    if courses[i][1]<worstScore:
        worstScore=courses[i][1]
        worstName=courses[i][0]
    sum=sum+courses[i][1]
average=sum/len(courses)
print("最高分课程是{}{}, 最低分课程是{}{}, 平均分是{:.2f}".format(BestName,BestScore,worstName,worstScore,average))
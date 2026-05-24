data=[]
ageSum=0
maleCount=0
rowNumber=0
line=input()
while line:
    name,gender,age=line.split()
    data.append((name,gender,int(age)))
    ageSum+=int(age)
    if(gender=="男"):
        maleCount+=1
    rowNumber+=1
    line=input()
averageAge=ageSum/rowNumber
print("平均年龄是{:.2f} 男性人数是{}".format(averageAge,maleCount))

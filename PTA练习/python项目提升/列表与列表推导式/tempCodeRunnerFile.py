s=input().strip()#输入整个字符串
s=s.strip('[]')#去掉中括号
items=s.split(',')#逗号分隔
list2=[]
for item in items:
       item=item.strip(" ")#去掉空格
       item=item.strip('""')#去掉引号
       if item not in list2:
              list2.append(item)
for i in list2:
    if(i==list2[-1]):
        print(i)
        break
    print(i,end=" ")
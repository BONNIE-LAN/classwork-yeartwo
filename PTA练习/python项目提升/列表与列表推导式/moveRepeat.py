"""list=[]
list2=[]
list.extend(input().split(','))#把每个元素拆开放入list中
for i in range(0,len(list),1):
            if(list[i] not in list2):
                list2.append(list[i])
for item in list2:
    print(item,end=" ")#空格分隔"""
#AI 查询版
"""s=input().strip()#输入整个字符串
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
    print(i,end=" ")"""
#再次AI修正版
s = input().strip()
s = s.strip('[]')  # 去掉中括号
items = s.split(',')  # 按逗号分割

list2 = []
for item in items:
    item = item.strip()  # 去掉首尾空格
    # 处理字符串类型的引号
    if item.startswith('"') and item.endswith('"'):
        item = item[1:-1]  # 去掉双引号
    elif item.startswith("'") and item.endswith("'"):
        item = item[1:-1]  # 去掉单引号
    # 判断是否已存在于 list2 中
    if item not in list2:
        list2.append(item)

# 输出结果，用空格分隔
for i in range(len(list2)):
    if i == len(list2) - 1:
        print(list2[i])
    else:
        print(list2[i], end=" ")
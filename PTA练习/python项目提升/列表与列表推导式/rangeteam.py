T=eval(input())
lists=[]
while T--:
    n=eval(input())
    for j in range(n):
        lists.append([]) #根据每一个位置添加一个空列表
    for i in range(1,(n*(n-1)/2)+1):
        i,j,p,q=map(int,input().split(" "))
        if(p>q):
            lists[i-1][0]+=3
        elif(p==q):
            lists[i-1][0]+=1
            lists[j-1][0]+=1
        elif(p<q):
            lists[j-1][0]+=3
        lists[i-1][1]+=p-q
        lists[j-1][1]+=q-p
        lists[i-1][2]+=p
        lists[j-1][2]+=q
        lists[i-1][3]=i
        lists[j-1][3]=j
    max=lists[0]
    for m in range(n):
        if(lists[m][0]>max[0]):
            swap(lists[m],lists[0])
            max=lists[m]
        if()
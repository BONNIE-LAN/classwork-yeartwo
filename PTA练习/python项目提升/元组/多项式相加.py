tuple1=input()
tuple2=input()
expersion1=tuple(map(int,tuple1.replace(',',' ').split()))
expersion2=tuple(map(int,tuple2.replace(',',' ').split()))
x=eval(input())
list=[]
for i in range(1,len(expersion1),2):
    if((expersion1[i])==x):
        list.append(int(expersion1[i-1]))
for i in range(1,len(expersion2),2):
    if(int(expersion2[i])==x):
        list.append(int(expersion2[i-1]))
print(sum(list))
        




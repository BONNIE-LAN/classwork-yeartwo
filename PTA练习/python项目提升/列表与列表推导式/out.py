N,M,K=map(int,input().split(" "))
peoples=list(range(1,N+1))
out=[]
round=1
count=0
while len(peoples)>N-K:
    count+=1
    if count==M*round:
        index=(count-1)%len(peoples)
        out.append(peoples[index])
        peoples.pop(index)
        round+=1
        count=index
for i in range(len(out)):
    if i==len(out)-1:
        print(out[i])
    else:
        print(out[i],end=' ')
#AI重写版
def josephus(N, M, K):
    people = list(range(1, N + 1))
    result = []  # 记录出圈顺序
    index = 0    # 从第一个人开始
    
    while len(people) > K:
        index = (index + M - 1) % len(people)
        result.append(people.pop(index))
    
    return result

# 读取输入
N, M, K = map(int, input().split())
out_order = josephus(N, M, K)

# 输出
print(" ".join(map(str, out_order)))

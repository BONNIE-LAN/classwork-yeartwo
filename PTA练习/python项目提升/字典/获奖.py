T=eval(input())
team={}
for _ in range(T):
    n=eval(input())
    ms=eval(input())
    for _ in range(n):
        s=eval(input())
        team['s']=[]
        m=eval(input())
        team['s'].append(m)
        g=eval(input())
        team['s'].append(g)
        n=n-1
    T=T-1
    sort_team=sorted(team.items(),key=lambda x:(-x[1][0],-x[1][1]))
for i in range(len(sort_team.keys())):
    if(sort_team.keys[i]==ms):
        rate=i
        break
if rate<=round(len(sort_team)*0.6):
    print("YES")
else:
    print("NO")
#AI version
T = int(input())

for _ in range(T):
    line = input().split()
    n = int(line[0])
    ms = line[1]  # 要判断的队伍名

    teams = []  # 存储每个队伍的 (name, m, g)

    for _ in range(n):
        data = input().split()
        s = data[0]
        m = int(data[1])
        g = int(data[2])
        teams.append((s, m, g))

    # 按规则排序：先按解题数降序，再按成绩降序
    teams.sort(key=lambda x: (-x[1], -x[2]))

    # 找到 ms 的排名（从 0 开始）
    rank = -1
    for i, (name, m, g) in enumerate(teams):
        if name == ms:
            rank = i
            break

    # 计算获奖人数（前60%，四舍五入）
    award_count = round(n * 0.6)

    # 如果排名在前 award_count 名，则获奖
    if rank < award_count:
        print("YES")
    else:
        print("NO")

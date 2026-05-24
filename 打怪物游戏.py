import random
role={"player":[5,2,3,4],"monster":[10,1,2]}
#游戏主循环：直到一方血量<=0
while role["player"][0]>0 and role["monster"][0]>0:
    #随机决定谁攻击
    attacker=random.randint(1,2)
    if attacker==1:#玩家攻击
        atk=random.choice(role["player"][1:])
        print("玩家攻击！造成{}点伤害".format(atk))
        role["monster"][0]-=atk
    else:#怪物攻击
        #随机选择怪物的一个攻击力
        atk=random.choice(role["monster"][1:])
        print("怪物攻击！造成{}点伤害".format(atk))
        role["player"][0]-=atk
    #显示当前血量
    print("玩家血量：{},怪物血量：{}".format(role['player'][0],role["monster"][0]))
#判断胜负
if role["player"][0]<=0:
    print("怪物胜利！剩余血量：{}".format(role["monster"][0]))
else:
    print("玩家胜利！剩余血量：{}".format(role["player"][0]))


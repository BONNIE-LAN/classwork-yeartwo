while True:
    try:
        n=eval(input())
        for cockNumber in range(0,n+1,1):
            for henNumber in range(0,n+1,1):
                chickenNumber=n-cockNumber-henNumber
                totalMoney=5*cockNumber+3*henNumber+1/3*chickenNumber
                if(totalMoney==n):
                    print(cockNumber,henNumber,chickenNumber)
    except EOFError:
        break
#AI 改进版本
"""
while True:
    try:
        n = int(input())   # 不要用 eval,更安全
        for cockNumber in range(0, n // 5 + 1):        # 公鸡最多 n//5 只
            for henNumber in range(0, n // 3 + 1):     # 母鸡最多 n//3 只
                chickenNumber = n - cockNumber - henNumber
                if chickenNumber >= 0 and (chickenNumber % 3 == 0):
                    totalMoney = 5 * cockNumber + 3 * henNumber + chickenNumber / 3
                    if totalMoney == n:
                        print(cockNumber, henNumber, chickenNumber)
    except EOFError:
        break

"""
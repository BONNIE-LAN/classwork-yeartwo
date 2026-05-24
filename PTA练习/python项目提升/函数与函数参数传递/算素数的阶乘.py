def caculate(n):
    if n < 0:
        return 0  # 或者抛出异常
    if(n==1 or n==0):
        result=1
    else:
        result=n*caculate(n-1)
    return result

def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

try:
    N = int(input())
except ValueError:
    print("Input Error!")
    exit(0)

if N < 0:
    print("Input Error!")
    exit(0)
elif N > 10:
    print("Too big!Game over!")
    exit(0)
else:
    outcome = 0
    for i in range(N):  # 修改为range(N)而不是range(0,N)
        try:
            number = int(input())  # 使用int()替代eval()
            if(is_prime(number)):
                add = caculate(number)
                outcome = outcome + add
        except ValueError:
            print("Input Error!")
            exit(0)
    print(outcome)
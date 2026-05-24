n=eval(input())
width=2*n-1
for number in range(n,0,-1):
    print(("*"*(2*number-1)).center(width))
for row in range(1,n,1):
    print(("*"*(2*row+1)).center(width))
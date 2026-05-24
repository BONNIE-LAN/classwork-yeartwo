'''利用高阶函数map求解所有3位、4位、5位水仙花数'''
def is_narcissistic(num):
    str_num=str(num)
    digits=len(str_num)
    sum_of_powers=sum(map(lambda x:x**digits,map(int,str_num)))
    #sum_of_powers = sum(map(lambda x: int(x)**digits, str_num))
    return sum_of_powers==num
#查找三位数水仙花数        
three_digits_range=range(100,1000)
three_digits_narcissistic=list(filter(is_narcissistic,three_digits_range))
#查找四位数水仙花数
four_digits_range=range(1000,10000)
four_digits_narcissistic=list(filter(is_narcissistic,four_digits_range))
#查找五位数水仙花数
five_digits_range=range(10000,100000)
five_digits_narcissistic=list(filter(is_narcissistic,five_digits_range))
#输出结果
print("三位数水仙花数：")
for num in three_digits_narcissistic:
    print(num)
print("\n四位数水仙花数：")
for num in four_digits_narcissistic:
    print(num)
print("\n五位数水仙花数：")
for num in five_digits_narcissistic:
    print(num)

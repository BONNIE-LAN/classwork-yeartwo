# 定义大写字母表元组
tuple1 = tuple('ABCDEFGHIJKLMNOPQRSTUVWXYZ')
# 反转后的元组
tuple2 = tuple1[::-1]

s = input()

for letter in s:
    if letter in tuple1:  # 只处理大写字母
        # 找出该字母在 tuple1 中的索引
        index = tuple1.index(letter)
        # 输出反转后对应的字母
        print(tuple2[index], end='')
    else:
        # 其他字符原样输出
        print(letter, end='')

print()  # 换行

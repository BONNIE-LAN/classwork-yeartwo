string=input().strip()
for word in string:
    if not(word.isdigit() or word.islower()):
        print("不全是数字和小写字母")
        break
else:
    print("全是数字和小写字母")

dic = {'admin': '123456', 'administrator': '12345678', 'root': 'password'}

for i in range(3):  # 最多允许三次输入
    name = input().strip()
    password = input().strip()
    
    if name in dic and dic[name] == password:
        print("登录成功")
        break
    else:
        print("登录失败")

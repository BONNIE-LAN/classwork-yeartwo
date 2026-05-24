def four_digit_to_chinese(num):
    """ 把四位以内的数字转为中文 """
    num_map = "零一二三四五六七八九"
    unit_map = ["", "十", "百", "千"]

    s = ""
    zero = False
    for i, d in enumerate(str(num).zfill(4)):
        d = int(d)
        if d == 0:
            zero = True
        else:
            if zero:
                s += "零"
                zero = False
            s += num_map[d] + unit_map[3 - i]
    return s.rstrip("零") or "零"


def number_to_chinese(num):
    """ 把大数转中文 """
    big_unit_map = ["", "万", "亿"]
    parts = []
    str_num = str(num)

    # 每四位分组
    while str_num:
        parts.append(int(str_num[-4:]))
        str_num = str_num[:-4]

    res = []
    for i, part in enumerate(parts):
        if part != 0:
            res.append(four_digit_to_chinese(part) + big_unit_map[i])
        else:
            res.append("零")

    # 组合结果（注意倒序）
    result = "".join(res[::-1])

    # 去掉多余零
    while "零零" in result:
        result = result.replace("零零", "零")
    result = result.strip("零")

    # 特殊情况：10 → "十"
    if result.startswith("一十"):
        result = result[1:]

    return result or "零"


# 主程序
n = int(input())
for _ in range(n):
    num = int(input())
    print(number_to_chinese(num))

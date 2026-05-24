string1 = input().strip()
string2 = input().strip()
dic1 = dict(eval(string1))
dic2 = dict(eval(string2))

merged_dic = {}
all_keys = set(dic1.keys()) | set(dic2.keys())
all_keys_sorted = sorted(all_keys, key=lambda x: str(x))

for key in all_keys_sorted:
    if key in dic1 and key in dic2:
        merged_dic[key] = dic1[key] + dic2[key]
    elif key in dic1:
        merged_dic[key] = dic1[key]
    else:
        merged_dic[key] = dic2[key]

# ---- 手动格式化输出 ----
out_items = []
for k, v in merged_dic.items():
    if isinstance(k, str):
        out_items.append(f'"{k}":{v}')
    else:
        out_items.append(f'{k}:{v}')

output = '{' + ','.join(out_items) + '}'
print(output)


        

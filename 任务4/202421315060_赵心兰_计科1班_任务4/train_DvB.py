import re
import json
import csv
#读入保存好的网页源代码文本
with open("Dylan_van_Baarle.txt","r",encoding="utf-8") as f:
    html_text=f.read()
pattern = r'"samples"\s*:\s*(\[\s*\{.*?\}\s*\])'
match = re.search(pattern, html_text, re.S)
if not match:
    raise ValueError("在 Dylan_van_Baarle.txt 中没有找到 JSON 数组，请检查源文件格式。")
json_text = match.group(1)
#把字符串解析为python列表
records=json.loads(json_text)
#需要提取的字段名
fields=[
    "ms",
    "speed",
    "elevation",
    "temperature",
    "cadence",
    "power",
    "distance",
    "positionLat",
    "positionLong"
]
filtered_records = []
for item in records:
    # 只保留包含数值数据的记录
    if "evt" in item and item["evt"] == "none" and "values" in item and item["values"]:
        filtered_records.append(item)
#写入trin_DvB.csv
with open("train_DvB.csv","w",newline="",encoding="utf-8") as f:
    writer=csv.writer(f)
    #表头
    writer.writerow(fields)
    #记录
    for item in filtered_records:
        values = item.get("values", [])
        row = [item.get("ms", "")]  # 先添加ms字段
        field_indices = {
            "speed": 1,
            "elevation": 3,
            "temperature": 4,
            "cadence": 5,
            "power": 2,
            "distance": 6,
            "positionLat": 7,
            "positionLong": 8
        }
        for field in fields[1:]:  # 跳过ms
            index = field_indices.get(field)
            if index is not None and index < len(values):
                row.append(values[index])
            else:
                row.append("")
                
        writer.writerow(row)
print("共写入{} 条记录到train_DvB.csv".format(len(records)))
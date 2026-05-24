import json
import csv
#读入json文件中的信息
with open("beijing_aqi.json","r",encoding="utf-8") as f:
    data=json.load(f)
#取json中每条记录的键作为表头
header=list(data[0].keys())
#按给定键值升序排序
sorted_data=sorted(data,key=lambda x:x["aqi"])
#将表头和排序好的内容写入csv文件
with open("beijing_aqi.csv","w",encoding="utf-8",newline="") as f:
    writer=csv.writer(f)
    #写表头
    writer.writerow(header)
    #写每行数据
    for item in sorted_data:
        row=[item[key]for key in header]
        writer.writerow(row)
    
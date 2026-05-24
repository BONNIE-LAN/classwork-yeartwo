import csv
import json
#将csv文件读取到列表scores_list
scores_list=[]
with open('scores.csv','r',encoding='utf-8') as f:
    reader=csv.reader(f)
    headers=next(reader) #跳过表头
    for row in reader:
        scores_list.append(row)
#转换为字典列表scores_dict
scores_dict=[]
for row in scores_list:
    student_dict={
        '学号':row[0],
        '语文':int(row[1]),
        '数学':int(row[2]),
        '英语':int(row[3]),
        '总分':int(row[4]),
    }
    scores_dict.append(student_dict)
#写入json文件
with open('scores.json','w',encoding='utf-8') as f:
    json.dump(scores_dict,f,ensure_ascii=False,indent=4)
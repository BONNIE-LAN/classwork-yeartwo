import matplotlib.pyplot as plt
import numpy as np

# 文件路径
head_file = 'd:\\学习\\作业\\python程序设计\\实验5：可视化\\WN18RR\\GAT+2sides_head_tail.txt'
tail_file = 'd:\\学习\\作业\\python程序设计\\实验5：可视化\\WN18RR\\GAT+convauto_head_tail.txt'

# 读取数据
def read_data(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()
    # 去除空格和换行符，转换为整数列表
    data = []
    for line in lines:
        values = [int(x.strip()) for x in line.split() if x.strip()]
        data.append(values)
    return data

# 读取头实体和尾实体数据
head_data = read_data(head_file)  # [[BDRAN_head], [BDRAN+CA_head]]
tail_data = read_data(tail_file)  # [[BDRAN_tail], [BDRAN+CA_tail]]

# 提取数据
bdran_head = head_data[0]  # [1050, 246, 92, 264, 425, 847]
bdran_ca_head = head_data[1]  # [1253, 98, 56, 156, 278, 1083]

bdran_tail = tail_data[0]  # [1103, 272, 100, 277, 423, 749]
bdran_ca_tail = tail_data[1]  # [1299, 89, 62, 159, 316, 999]

# 定义横坐标标签
x_labels = ['1', '2', '3', '4-10', '11-100', '101-']

# 设置图形大小
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(12, 10))

# 第一个子图：头实体预测
x = np.arange(len(x_labels))
width = 0.35

ax1.bar(x - width/2, bdran_head, width, label='BDRAN', color='red')
ax1.bar(x + width/2, bdran_ca_head, width, label='BDR+CA', color='blue')

ax1.set_title('Performance of head entity prediction on WN18RR')
ax1.set_xlabel('Range of rank')
ax1.set_ylabel('Number of entities')
ax1.set_xticks(x)
ax1.set_xticklabels(x_labels)
ax1.legend()
ax1.grid(axis='y', linestyle='--', alpha=0.7)

# 在柱子上方添加数值标签
for i, (h, ca) in enumerate(zip(bdran_head, bdran_ca_head)):
    ax1.text(i - width/2, h + 10, str(h), ha='center', va='bottom', fontsize=9)
    ax1.text(i + width/2, ca + 10, str(ca), ha='center', va='bottom', fontsize=9)

# 第二个子图：尾实体预测
ax2.bar(x - width/2, bdran_tail, width, label='BDRAN', color='red')
ax2.bar(x + width/2, bdran_ca_tail, width, label='BDR+CA', color='blue')

ax2.set_title('Performance of tail entity prediction on WN18RR')
ax2.set_xlabel('Range of rank')
ax2.set_ylabel('Number of entities')
ax2.set_xticks(x)
ax2.set_xticklabels(x_labels)
ax2.legend()
ax2.grid(axis='y', linestyle='--', alpha=0.7)

# 添加数值标签
for i, (h, ca) in enumerate(zip(bdran_tail, bdran_ca_tail)):
    ax2.text(i - width/2, h + 10, str(h), ha='center', va='bottom', fontsize=9)
    ax2.text(i + width/2, ca + 10, str(ca), ha='center', va='bottom', fontsize=9)

plt.tight_layout()
plt.show()
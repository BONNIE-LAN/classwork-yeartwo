import pandas as pd
import networkx as nx
import matplotlib.pyplot as plt

# 读取CSV文件
file_path = 'd:\\学习\\作业\\python程序设计\\实验5：可视化\\triples.csv'
df = pd.read_csv(file_path, encoding='utf-8')

# 创建有向图
G = nx.DiGraph()

# 添加边（head -> tail）
for _, row in df.iterrows():
    head = row['head']
    tail = row['tail']
    G.add_edge(head, tail)

# 设置图形大小
plt.figure(figsize=(14, 12))  # 增大画布以容纳文字

# 使用Kamada-Kawai布局（适合复杂图，避免交叉）
pos = nx.kamada_kawai_layout(G)

# 绘制节点（红色圆形）
nx.draw_networkx_nodes(G, pos, node_size=15, node_color='red', alpha=0.9, edgecolors='black')

# 绘制边（黑色箭头）
nx.draw_networkx_edges(G, pos, arrows=True, arrowstyle='->', arrowsize=15, edge_color='black', alpha=0.8)

# 显示节点标签（人物名）
nx.draw_networkx_labels(
    G, 
    pos, 
    font_size=6,           # 字体大小，较小以避免重叠
    font_family='SimHei',  # 中文支持（黑体）
    font_weight='normal',
    verticalalignment='center',
    horizontalalignment='center'
)

# 关闭坐标轴
plt.axis('off')
plt.tight_layout()
plt.show()
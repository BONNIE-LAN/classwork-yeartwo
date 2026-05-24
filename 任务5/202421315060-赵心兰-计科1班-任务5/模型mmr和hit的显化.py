import matplotlib.pyplot as plt
import numpy as np
#读取数据
filename='d:\\学习\\作业\\python程序设计\\实验5：可视化\\wn18.txt'
data=[]
with open(filename,'r') as f:
    lines=f.readlines()
current_model=None
models={'TransE':[],'TransD':[],'ComplEx':[]}
for line in lines:
    line=line.strip()
    if not line:
        continue
    if line.startswith('TransE') or line.startswith('TransD') or line.startswith('ComplEx'):
        current_model=line.strip()
        continue
    else:
        parts=line.split()
        mrr=float(parts[0])
        hits=float(parts[1])
        epoch=int(parts[2])
        models[current_model].append((epoch,mrr,hits))
#提取数据
def extract_data(model_name):
    epochs=[]
    mrrs=[]
    hits=[]
    for epoch,mrr,hit in models[model_name]:
        epochs.append(epoch)
        mrrs.append(mrr)
        hits.append(hit)
    return epochs,mrrs,hits
#获取各模型数据
epochs_T,mrr_T,hits_T=extract_data('TransE')
epochs_D,mrr_D,hits_D=extract_data('TransD')
epochs_C,mrr_C,hits_C=extract_data('ComplEx')
#创建图形
fig,(ax1,ax2)=plt.subplots(1,2,figsize=(14,6))
#MRR
ax1.plot(epochs_T,mrr_T,'g-',marker='x',label='TransE',linewidth=2)
ax1.plot(epochs_D,mrr_D,'r-',marker='*',label='TransD',linewidth=2)
ax1.plot(epochs_C,mrr_C,'b-',marker='o',label='ComplEx',linewidth=2)
ax1.set_title('WN18 Validation MRR')
ax1.set_xlabel=('Epochs')
ax1.set_ylabel=('MRR')
ax1.legend()
ax1.grid(True)
#Hits@10
ax2.plot(epochs_T,hits_T,'g-',marker='x',label='TransE',linewidth=2)
ax2.plot(epochs_D,hits_D,'r-',marker='*',label='TransD',linewidth=2)
ax2.plot(epochs_C,hits_C,'b-',marker='o',label='ComplEx',linewidth=2)
ax2.set_title('WN18 Validation Hits@10')
ax2.set_xlabel=('Epochs')
ax2.set_ylabel=('Hits@10')
ax2.legend()
ax2.grid(True)
#调整布局
plt.tight_layout()
plt.show()


import distance_function as df
diamension1=df.distance(x1=1,x2=2)
diamension2=df.distance(x1=1,y1=1,x2=2,y2=2)
diamension3=df.distance(x1=1,y1=1,z1=1,x2=2,y2=2,z2=2)
# 直接获取距离值
x_dist1, total_dist1 = df.distance(x1=1, x2=2)
print(f"x之间的距离为{x_dist1:.2f},空间之间的距离为{total_dist1:.2f}")

x_dist2, total_dist2 = df.distance(x1=1, y1=1, x2=2, y2=2)
print(f"x之间的距离为{x_dist2:.2f},空间之间的距离为{total_dist2:.2f}")

x_dist3, total_dist3 = df.distance(x1=1, y1=1, z1=1, x2=2, y2=2, z2=2)
print(f"x之间的距离为{x_dist3:.2f},空间之间的距离为{total_dist3:.2f}")




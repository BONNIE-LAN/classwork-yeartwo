import random
# 模拟多传感器数据输入
current_speed = random.randint(30, 120)  # 当前车速(km/h)
front_distance = random.randint(0, 200)  # 前方障碍物距离(m)
road_condition = random.choice(["干燥", "湿滑", "积雪"])  # 道路条件
weather = random.choice(["晴朗", "小雨", "大雨", "雾天"])  # 天气条件
traffic_light = random.choice(["绿色", "黄色", "红色"])  # 交通信号灯

# 打印当前环境状态
print("=== 自动驾驶系统决策日志 ===")
print(f"当前车速: {current_speed} km/h")
print(f"前方障碍物距离: {front_distance} m")
print(f"道路条件: {road_condition}")
print(f"天气条件: {weather}")
print(f"交通信号灯: {traffic_light}")

# 决策逻辑
decision = ""
emergency = False

# 紧急情况：前方障碍物太近（< 50米）
if front_distance < 50:
    decision = "紧急刹车！"
    emergency = True
elif traffic_light == "红色":
    decision = "停车等待"
elif traffic_light == "黄色":
    decision = "减速准备停车"
elif traffic_light == "绿色":
    # 根据天气和路况调整速度
    if weather in ["大雨", "雾天"] or road_condition in ["湿滑", "积雪"]:
        if current_speed > 60:
            decision = "减速行驶"
        else:
            decision = "保持当前速度"
    else:
        decision = "保持当前速度"

# 输出决策结果
print(f"\n决策结果: {decision}")

# 记录驾驶日志（写入文件）
with open("driving_log.txt", "a", encoding="utf-8") as f:
    f.write(f"时间: {random.randint(1, 24):02d}:{random.randint(0, 59):02d}\n")
    f.write(f"车速: {current_speed} km/h\n")
    f.write(f"障碍物距离: {front_distance} m\n")
    f.write(f"道路: {road_condition}, 天气: {weather}, 信号灯: {traffic_light}\n")
    f.write(f"决策: {decision}\n")
    f.write("-" * 40 + "\n")

print("\n驾驶日志已记录到 driving_log.txt")

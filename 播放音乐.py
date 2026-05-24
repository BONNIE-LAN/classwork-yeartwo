import os
import random
import pygame
import time

# 初始化pygame.mixer
pygame.mixer.init()

# 获取音乐文件路径
happy_path = r'D:\学习\作业\python程序设计\music\happy'  # 开心音乐文件夹路径
sad_path = r'D:\学习\作业\python程序设计\music\sad'      # 伤心音乐文件夹路径

# 筛选音乐文件（只保留音频文件，如 .mp3、.wav）
def get_music_files(path):
    return [f for f in os.listdir(path) if f.lower().endswith(('.mp3', '.wav', '.ogg'))]

# 获取两类音乐列表
happy_list = get_music_files(happy_path)
sad_list = get_music_files(sad_path)

# 用户输入心情
mood = int(input("请输入心情 (0: 开心, 1: 伤心, 8: 不想听了): "))

# 根据心情选择播放列表
while mood != 8:
    if mood == 0:
        music_file = random.choice(happy_list)
        music_path = os.path.join(happy_path, music_file)
    elif mood == 1:
        music_file = random.choice(sad_list)
        music_path = os.path.join(sad_path, music_file)
    else:
        print("无效输入，请重新输入。")
        mood = int(input("请输入心情 (0: 开心, 1: 伤心, 8: 不想听了): "))
        continue

    # 播放音乐
    pygame.mixer.music.load(music_path)
    pygame.mixer.music.play()
    print(f"正在播放: {music_file}")

    # 播放100秒后停止
    time.sleep(100)
    pygame.mixer.music.stop()

    # 询问是否继续
    mood = int(input("请输入心情 (0: 开心, 1: 伤心, 8: 不想听了): "))

print("播放结束。")
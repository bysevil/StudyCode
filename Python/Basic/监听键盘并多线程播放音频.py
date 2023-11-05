"""
监听键盘。打印每个按下的按键
在按下按键时，创建一个新线程，播放一段音频
"""

from pynput import keyboard
from playsound import playsound
from threading import Thread

def onRelease(key):
    """
    这个函数由Listener调用
    :param key:用户按下了哪个键
    """
    # 在控制台打印按下的案件
    print(key)

    # 创建线程，作用是播放音效
    t = Thead(targetr=playsound,args=('按键音.mp3'))

    # 启用线程
    t.start()

# 监听键盘
listener = keyboard.Listener(on_press=onRelease)

# 开始监听
listener.start()


listener.join()

"""
输入字符串来生成二维码（一般来说输入网址）
"""

import qrcode

str = input('输入要转换为二维码的字符串：')

#生成二维码
img = qrcode.make(str)

#保存文件
img.save('qrcode.png')
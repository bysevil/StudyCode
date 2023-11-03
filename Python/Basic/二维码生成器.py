import qrcode

str = input('输入要转换为二维码的字符串：')
img = qrcode.make(str)

img.save('qrcode.png')
# 在指定目录和其子目录查找具有指定关键词的文件或目录
import os

inputpath = input('输入查找目录：')
pattern = input('输入查找关键词：')

for dirpath,dirnames,filenames in os.walk(inputpath):
    # dirpath:当前所在目录
    # dirnames:列表，当前目录的所以子目录名
    # filename：列表，当前目录下有哪些文件

    # os.walk()多次执行时会自动递归的查找当前目录和所有子目录

    for dirname in dirnames:
        if pattern in dirname:
            print(f'{dirpath}/{dirname}')

    for filename in filenames:
        if pattern in filename:
            print(f'{dirpath}/{filename}')
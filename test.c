#include<stdio.h>
#include<string.h>

void sort(char* a, char* b, int len1) {
    char arr[100] = "";//储存左旋数
    int i = 0;
    int flag = 0;
    //枚举左旋
    for (i = 0; i < len1; i++)
    {
        int j = 0;
        //储存左旋变量
        for (j = 0; j <= i; j++)
        {
            *(arr + j) = *(a + j);
        }
        //开始左旋
        for (j = 0; j <= i; j++) {
            *(a + j) = *(a+j);
        }
        //将储存的左旋数放回数组末尾
        int c = 0;
        for (j = i; j < len1; j++) {
            *(a + j) = *(arr + c);
            c++;
        }
        //判断二者是否相等
        int result = strcmp(a, b);
        if (result == 0) 
        {
            flag = 1;
            printf("1");
            break;
        }
    }
    if (flag == 0)
    {
        printf("0");
    }
}
int main() {
    char str1[100] = "abcde";
    char str2[100] = "bcdea";
    int k = 2;
    sort(str1,str2,5);
    return 0;
}
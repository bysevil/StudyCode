#include<stdio.h>
#include<string.h>

int strchrs(char* p[], char* str, char ch) {
    int i = 0;
    while (*str) {
        if (*str == ch) p[i++] = str;
        str++;
    }
    return i;
}

int ynright(char* str1, char* str2) {
    return 1;
}

int ynleft(char* str1, char* str2) {
    char* p[10];
    int num = strchrs(p, str2, str1[0]);
    while (num) {
        if (p[num-1]) {
            char* flag = p[num-1];
            while (*flag) {
                if (*str1 == *flag) str1++, flag++;
                else return 0;
            }
            while (*str1) {
                if (*str1 == *str2) str1++, str2++;
                else return 0;
            }
        }
        else return 0;
        num--;
        return 1;
    }
    return 0;
}

int main() {
    char* str1 = "abcade";
    char* str2 = "adeabc";
    char* str3 = "acdbar";

    if (strlen(str1) == strlen(str2) && ynleft(str1, str2)) printf("str2是str1旋转后的字符\n");
    else printf("str2不是str1旋转后的字符\n");

    if (strlen(str1) == strlen(str3) && ynleft(str1, str3)) printf("str3是str1旋转后的字符\n");
    else printf("str3不是str1旋转后的字符\n");

    return 0;
}
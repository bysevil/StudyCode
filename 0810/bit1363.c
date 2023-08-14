#include<stdio.h>
#include<string.h>

int ynleft(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char* p = strchr(str2, str1[0]);

    if (p) {
        char* flag = p;
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
    return 1;
}

int main() {
    char* str1 = "abcde";
    char* str2 = "deabc";
    char* str3 = "acdba";

    if (ynleft(str1, str2)) printf("str2是str1左旋后的字符\n");
    else printf("str2不是str1左旋后的字符\n");

    if (ynleft(str1, str3)) printf("str3是str1左旋后的字符\n");
    else printf("str3不是str1左旋后的字符\n");

    return 0;
}
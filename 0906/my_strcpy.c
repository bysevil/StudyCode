#include<stdio.h>
#include<assert.h>

char* my_strcpy(char *dest, const char *src){
    assert(dest);
    assert(src);
    while(*dest++ = *src++);
    return dest;
}

int main(){
    const char* str1 = "hello";
    const char* str2 = "world";
    char str3[100];
    my_strcpy(str3, str1);
    printf("%s\n", str3);
    my_strcpy(str3, str2);
    printf("%s\n", str3);
    return 0;
}
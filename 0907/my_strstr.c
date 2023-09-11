#include<stdio.h>
#include<stdbool.h>
#include<assert.h>

bool my_strcmp(const char *str1, const char *str2){
    while(*str1 == *str2){
        if(*str2 == '\0') return true;
        str1++; str2++;
    }
    return false;
}

char* my_strstr(const char *str1, const char *str2){
    assert(str1 && str2);
    while(*str1){
        if(my_strcmp(str1, str2)) return str1;
        str1++;
    }
    return NULL;
}

int main(){
    char *str1 = "hello world";
    char *str2 = "world";
    char *str3 = "hi";

    char* p = my_strstr(str1, str2);
    if (p) printf("%s\n",p);
    else printf("not found\n");

    p = my_strstr(str1, str3);
    if (p) printf("%s\n",p);
    else printf("not found\n");

    return 0;
}
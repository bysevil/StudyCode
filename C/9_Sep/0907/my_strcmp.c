#include<stdio.h>
#include<assert.h>

int strcmp(char* s1, char* s2){
    assert(s1 && s2);
    while(*s1 == *s2){
        if(*s1 == '\0') return 0;
        s1++;s2++;
    }
    return *s1 - *s2;
}

int main(){
    char s1[] = "abc";
    char s2[] = "abd";
    printf("%d\n", strcmp(s1, s2));
    return 0;
}
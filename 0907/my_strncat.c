#include<stdio.h>
#include<assert.h>

char* my_strncat(char* dest, const char* src, size_t n){
    assert(dest && src);
    char* hard = dest;
    while(*dest) dest++;
    while(n-- && *src){
        *dest++ = *src++;
    }
    *dest = '\0';
    return hard;
}

int main(){
    char dest[100] = "hello";
    char src[100] = " world";
    my_strncat(dest, src, 100);
    printf("%s\n", dest);
    return 0;
}
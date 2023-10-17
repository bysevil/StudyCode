#include<stdio.h>
#include<assert.h>

char* my_strcat(char* dest, const char* src){
    assert(dest);
    assert(src);
    char* temp = dest;
    while(*temp++);
    temp--;
    while(*temp++ = *src++);
    return dest;
}

int main(){
    char dest[100] = "hello";
    const char* src = "world";
    my_strcat(dest, src);
    printf("%s\n", dest);
    return 0;
}
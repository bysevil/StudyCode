#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t n){
    char* d = (char*)dest;
    char* s = (char*)src;
    while(n--){
        *d++ = *s++;
    }
    return dest;
}

int main(){
    char str[] = "Hello World";
    char str2[] = "Hello bit";
    printf("%s\n", my_memcpy(str, str2, 10));
    return 0;
}
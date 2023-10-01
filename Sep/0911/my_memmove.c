#include<stdio.h>
#include<assert.h>

void* my_memmove(void* dest, const void* src, int count){
    assert(dest && src);
    if(dest < src){
        char* d = (char*)dest;
        const char* s = (const char*)src;
        while(count--){
            *d++ = *s++;
        }
    }else if(dest > src){
        char* d = (char*)dest + count - 1;
        const char* s = (const char*)src + count - 1;
        while(count--){
            *d-- = *s--;
        }
    }
    return dest;
}

int main(){
    char dest[] = "12345678";
    my_memmove(dest,dest + 2, 4);
    printf("%s\n", dest);
    my_memmove(dest + 2,dest, 4);
    printf("%s\n", dest);
    return 0;
}
#include<stdio.h>
#include<assert.h>

char* my_strncpy(const char *src, char *dest, size_t n){
    assert(src && dest);
    char* hard = dest;
    while(n--){
        if(*src) {
            *dest = *src;
            src++; 
        }else{
            *dest = '\0';
        }
        dest++;
    }
    return hard;
}

int main(){
    char str[] = "Hello World";
    char str2[100];
    size_t n = 15;
    char* p =  my_strncpy(str, str2, 15);
    while(n--){
        if(*p) printf("%c", *p);
        else printf("\\0");
        p++;
    }
    return 0;
}
#include<stdio.h>
#include<assert.h>

size_t my_strlen(char *str){
    assert(str);
    size_t i = 0;
    while(i++,*str++);
    return i;
}

int main(){
    char* str = "Hello World";
    size_t len = my_strlen(str);
    printf("%zu\n",len);
    return 0;
}
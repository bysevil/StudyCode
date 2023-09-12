#include<stdio.h>
#include<string.h>
#include<assert.h>

int my_atoi(char *str){
    assert(str);
    while(*str && isdigit(*str) == 0) str++;
    if(*str){
        int ans = 0;
        if(str-1 != NULL && *(str-1) == '-'){
            while(isdigit(*str)) ans = ans * 10 - *str++ + '0';
        }
        else{
            while(isdigit(*str)) ans = ans * 10 + *str++ - '0';
        }
        return ans;
    }else{
        return 0;
    }
}

int main(){
    char* str = "hello-12345world789";
    printf("%d\n", my_atoi(str));
    return 0;
}



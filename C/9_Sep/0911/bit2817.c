#include<stdio.h>
#include<stdbool.h>

bool largeORsmall(){
    int a = 1;
    return (*(char*)&a);
}

int main(){
    if(largeORsmall()){
        printf("小端字节序\n");
    }else{
        printf("大端字节序\n");
    }
    return 0;
}
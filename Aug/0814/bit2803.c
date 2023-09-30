#include<stdio.h>

int add(int a,int b){
    return a + b;
}

int sub(int a,int b){
    return a - b;
}

int count(int (*ptr)(int,int),int a,int b){
    return ptr(a,b);
}

int main(){
    int (*ptr[])(int,int) = {add,sub};
    int input,a,b;
    scanf("%d %d %d",&input,&a,&b);
    int (*p)(int(*)(int,int),int,int) = count;
    printf("%d",p(ptr[input],a,b));
    return 0;
}
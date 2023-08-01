/*
求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
例如：2+22+222+2222+22222
*/
#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    printf("%d",a*5+a*40+a*300+a*2000+a*10000);
    return 0;
}
#include<stdio.h>

int main()
{
    union{
        char a;
        int b;
    }s;
    s.b = 1;
    if(s.a) printf("小端存储");
    else printf("大端存储");
    return 0;
}
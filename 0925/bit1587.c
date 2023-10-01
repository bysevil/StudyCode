#include<stdio.h>

#define offsetof(type,member) ((size_t)(&((type*)0)->member))

struct stu{
    int a;
    char b;
    short c;
};

int main(){
    size_t num = offsetof(struct stu,c);
    printf("%d\n",num);
    return 0;
}
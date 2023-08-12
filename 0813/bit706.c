#include<stdio.h>

int main() {
    int num;
    int flag = 1;
    int i = 0,j = 0;
    int odd[100] = { 0 },eve[100] = { 0 };
    scanf("%d", &num);
    while (num > 0)
    {
        flag ? (odd[i++] = num & 1) : (eve[j++] = num & 1);
        num >>= 1;
        flag = !flag;
    }
    while (i > 0) printf("%d ", odd[--i]);
    printf("\n");
    while (j > 0) printf("%d ", eve[--j]);
    return 0;
}
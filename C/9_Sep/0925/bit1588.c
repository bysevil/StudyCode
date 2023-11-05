#include<stdio.h>

#define SWAP_BITS(num) (((num) & 0xAAAAAAAA) >> 1) | (((num) & 0x55555555) << 1)

int main(){
    int num = 0x01234567;
    printf("%x\n",SWAP_BITS(num));
    return 0;
}
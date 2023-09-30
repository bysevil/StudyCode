#include<math.h>
#include<stdio.h>

int isPowerOfTwo(unsigned int n){
    float flag = log2(n);
    if((int)flag == flag) return 1;
    else return 0;
}


int main(){
    int n;
    scanf("%d",&n);
    if(isPowerOfTwo(n)) printf("%d是2的幂次方",n);
    else printf("%d不是2的幂次方",n);
    return 0;
}
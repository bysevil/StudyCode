#include<stdio.h>

int bit677(int a){
    for(int i = 1;i <= a;i++){
        for(int j = 1;j <= i;j++){
            printf("%dx%d=%d\t",i,j,i*j);
        }
        printf("\n");
    }
    return 0;
}

int main(){
    int a;
    scanf("%d",&a);
    bit677(a);
    return 0;
}
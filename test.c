#include<stdio.h>

int sds(int arr[]){
    printf("%d",sizeof(arr));
}

int main() {
    int arr[] = {0,1,2,3};
    printf("%d\n",sizeof(arr));
    sds(arr);
}

#include<stdio.h>

void swap(int* a,int* b){
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void bubsort(int* arr,int len){
    len--;
    while(len){
        int flag = 1;
        for(int i = 0;i < len;i++){
            if(arr[i]>arr[i+1]) {
                swap(arr+i,arr+i+1);
                flag = 0;
            }
        }
        if(flag) return;
    }
}

void print(int* arr,int len){
    for(int i = 0;i<len;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[] = {5,3,6,4,5,1,3,9,7,8,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubsort(arr,len);
    print(arr,len);
    return 0;
}
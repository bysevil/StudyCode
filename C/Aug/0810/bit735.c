#include<stdio.h>

void print(int* arr,int len){
    for(int i = 0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int* a,int* b){
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

int oddfront(int* arr,int len){
    int* left = arr;
    int* right = arr+len-1;
    while(right>left){
        if(*right & 1){
            while(*left & 1) left++;
            if(right>left) swap(left,right);
            else return;
        }
        right--;
    }
}


int main(){
    int arr[] = {1,7,5,8,4,76,3,657,23,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    oddfront(arr,len);
    print(arr,len);
    return 0;
}
#include<stdio.h>

int init(int *arr,int lenarr){
    for(int i = 0;i < lenarr;i++) arr[i] = 0;
    return 0;
}

int print(int *arr,int lenarr){
    for(int i = 0;i < lenarr;i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

int reverse(int *arr,int lenarr){
    for(int i = 0;i < lenarr/2;i++){
        arr[i] = arr[i] ^ arr[lenarr-i-1];
        arr[lenarr-i-1] = arr[i] ^ arr[lenarr-i-1];
        arr[i] = arr[i] ^ arr[lenarr-i-1];
    }
    return 0;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int lenarr = sizeof(arr)/sizeof(*arr);
    print(arr,lenarr);
    reverse(arr,lenarr);
    print(arr,lenarr);
    init(arr,lenarr);
    print(arr,lenarr);
}

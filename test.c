class


#include<stdio.h>
int main() {
    int num = 0;
    int sum = 0;
    char arr[] = {17,13,15,19,14,16,11} ;
    int arr2[] = {0};
    for(int i =0;i<7;i++){
        num
        if(arr[i] > num) {
            arr2[i] = arr[i] - num;
            num += arr2[i];
            sum += arr2[i];
        }else{
            arr2[i] = 0;
        }
    }
}
//arr[1] + arr[2] + arr[3] + arr[4] +arr[5] >= arr2[5] 
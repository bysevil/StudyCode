#include <stdio.h>

void findSingleNumbers(int arr[], int n) {
    int xor_result = 0;
    for (int i = 0; i < n; i++) {
        xor_result ^= arr[i];
    }
    
    int bit = 1;
    while ((xor_result & bit) == 0) {
        bit <<= 1;
    }
    
    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++) {
        if ((arr[i] & bit) == 0) {
            num1 ^= arr[i];
        } else {
            num2 ^= arr[i];
        }
    }
    
    printf("只出现一次的两个数字是：%d 和 %d\n", num1, num2);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    findSingleNumbers(arr, n);
    
    return 0;
}
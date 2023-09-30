#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int bc92() {
    int arr[10];
    for (int i = 0; i < 10; i++) scanf("%d", arr+i);
    for (int i = 9; i >= 0; i--) printf("%d ", arr[i]);
    return 0;
}
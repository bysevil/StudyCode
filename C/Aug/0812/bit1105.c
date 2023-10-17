#include<stdio.h>
#define HOW 100

int main() {
    int arr[HOW][HOW] = { 0 };
    int (*p)[HOW] = arr;
    **p = 1;
    printf("%d\n", **p);
    for (int i = 1; i < HOW; i++) {
        **(p+i) = 1;
        printf("%d ", **(p+i));
        for (int j = 1; j < i; j++) {
            *(*(p+i)+j) = *(*(p+i-1)+j-1) + *(*(p+i - 1)+j);
            printf("%d ", *(*(p+i)+j));
        }
        *(*(p+i)+i) = 1;
        printf("%d", *(*(p+i)+i));
        printf("\n");
    }
}
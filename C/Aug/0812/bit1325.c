#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define HOW 10

void print(int arr[HOW][HOW]) {
    for (int i = 0; i < HOW; i++) {
        for (int j = 0; j < HOW; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void rng(int arr[HOW][HOW]) {
    srand((unsigned)time(NULL));
    arr[0][0] = rand();
    for (int i = 1; i < HOW; i++) arr[i][0] = rand() / 10 + arr[i - 1][0];
    for (int j = 1; j < HOW; j++) arr[0][j] = rand() / 10 + arr[0][j - 1];
    for (int i = 1; i < HOW; i++) {
        for (int j = 1; j < HOW; j++) {
            if (arr[i - 1][j] > arr[i][j - 1]) arr[i][j] = rand() / 10 + arr[i - 1][j];
            else arr[i][j] = rand() / 10 + arr[i][j - 1];
        }
    }
    print(arr);
}

void sort(int num,int arr[HOW][HOW],int flag[2]) {
    int i = 0,j = HOW - 1;
    while (i || j) {
        if (arr[i][j] == num) {
            flag[0] = i;
            flag[1] = j;
            return;
        }
        else if (arr[i][j] > num) {
            if (j > -1) j--;
            else return;
        }
        else
        {
            if (i < HOW) i++;
            else return;
        }
    }
}

int main() {
    int arr[HOW][HOW]; rng(arr);
    int flag[] = { -1,-1 };
    int num;
    while (scanf("%d",&num) != EOF) {
        sort(num, arr, flag);
        if (flag[0] == -1) printf("没有找到选定的数字num = %d\n", num);
        else printf("数字%d在数组中的位置为%d %d\n", num, flag[0], flag[1]);
    }
    return 0;
}
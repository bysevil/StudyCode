#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

int BC107() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[10][10];//VS��֧�ֱ䳤���飬����˴�ӦΪ int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}
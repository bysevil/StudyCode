#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int bc69() {
    int a;
    while (scanf("%d", &a) != EOF) {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if (i == 0 || j == 0 || i == a - 1 || j == a - 1) printf("* ");
                else printf("  ");
            }
        printf("\n");
        }
    }
    return 0;
}
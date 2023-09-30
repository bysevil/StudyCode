#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int bc68() {
    int a;
    while (scanf("%d", &a) != EOF) { 
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                if (i == j || i + j == a - 1) printf("* ");
                else printf("  ");
            }
            printf("\n");
        }
    }
    return 0;
}
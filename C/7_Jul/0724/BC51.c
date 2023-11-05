#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>

int BC51() {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF) { 
        if (a + b > c && a + c > b && b + c > a) {
            if (a == b && a == c) printf("Equilateral triangle!\n");
            else if (a == b || a == c || b == c) printf("Isosceles triangle!\n");
            else printf("Ordinary triangle!\n");
        }
        else printf("Not a triangle!\n");
    }
    return 0;
}
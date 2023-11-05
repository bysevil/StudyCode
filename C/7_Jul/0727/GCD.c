#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int gcd() {
	int a, b,c,max;
	scanf("%d %d", &a, &b);
	c = a > b ? b : a;
	for (int i = c ; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			max = i;
			break;
		}
	}
	printf("%d", max);
	return 0;
}
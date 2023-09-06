#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>

void swap(int *a, int *b) {
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

int sizeratio() {
	int a, b, c;
	while (scanf("%d %d %d", &a, &b, &c) != EOF) {
		if (b > a) interchange(&a, &b);
		if (c > a) {
			swap(&b, &c);
			swap(&a, &b);
		}
		printf("%d %d %d", a ,b, c);
		break;
	}
	return 0;
}



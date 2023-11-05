#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>

int tenmax() {
	int num[10];
	scanf("%d", num);
	int max = num[0];
	for (int i = 1; i < 10; i++) {
		scanf("%d", num + i);
		if (num[i] > max) max = num[i];
	}
	printf("%d", max);
	return 0;
}
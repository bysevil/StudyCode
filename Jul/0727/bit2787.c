#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>

int bit2787() {
	int arr[10];
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", arr+i);
		sum += arr[i];
	}
	printf("%f", sum / 10.0);
	return 0;
}
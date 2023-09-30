#include<stdio.h>

int interchangearray(int* arr1,int* arr2,int lenarr) {
	printf("%d\n", sizeof(arr1));
	for (int i = 0; i < lenarr; i++)
		printf("%d\t", arr1[i]);
	printf("\n");
	for (int i = 0; i < lenarr; i++)
		printf("%d\t", arr2[i]);
	printf("\n");
	for (int i = 0; i < lenarr; i++) {
		arr1[i] = arr1[i] ^ arr2[i];
		arr2[i] = arr2[i] ^ arr1[i];
		arr1[i] = arr1[i] ^ arr2[i];
	}
	for (int i = 0; i < lenarr; i++)
		printf("%d\t", arr1[i]);
	printf("\n");
	for (int i = 0; i < lenarr; i++)
		printf("%d\t", arr2[i]);
	printf("\n");
	return 0;
}


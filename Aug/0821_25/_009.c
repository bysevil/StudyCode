#include <stdio.h>

void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void bub_sort(int* arr, int len) {
	for (int i = len-1; i > 0; i--) {
		int flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr+j,arr+j + 1);
				flag = 0;
			}
		}
		if (flag) break;
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}

int main() {
	int arr[] = { 9,6,5,8,2,6,3,7,3,1 };
	bub_sort(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
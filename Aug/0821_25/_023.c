#include <stdio.h>

int main() {
	int arr[] = {1,4,7,2,7,5,8,9,0,2,5,8,1,0};
	int len = sizeof(arr) / sizeof(arr[0]);

	int num;
	scanf("%d", &num);

	int j = 0;
	for (int i = 0; i < len; i++) {
		if (i != j) arr[j] = arr[i];
		if (arr[i] != num) j++;
	}
	len = j;

	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
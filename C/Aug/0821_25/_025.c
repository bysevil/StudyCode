#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int arr1[30], arr2[30];
	for (int i = 0; i < n; i++) {
		scanf("%d", arr1 + i);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", arr2 + i);
	}

	int arr3[60];
	int i1 = 0, i2 = 0;
	for (int i = 0; i < n + m; i++) {
		if (i1 < n && i2 < m) {
			if (arr1[i1] > arr2[i2]) {
				arr3[i] = arr2[i2];
				i2++;
			}
			else {
				arr3[i] = arr1[i1];
				i1++;
			}
		}
		else if (i1 < n) {
			arr3[i] = arr1[i1];
			i1++;
		}
		else{
			arr3[i] = arr2[i2];
			i2++;
		}
	}

	for (int i = 0; i < m + n; i++) {
		printf("%d ", arr3[i]);
	}
	
	return 0;
}
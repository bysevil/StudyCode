#include<stdio.h>

int main() {
	int n, m, a = 0, b = 0;
	scanf("%d %d", &n, &m);
	int arr1[n], arr2[m];
	for (int i = 0; i < n; i++) scanf("%d", arr1 + i);
	for (int i = 0; i < m; i++) scanf("%d", arr2 + i);
	for (int i = 0; i < n + m; i++) {
		if (a == n) {
			if (b == n + 1) break;
			printf("%d ", arr2[b++]);
			continue;
		}
		if (b == m) {
			if (a == n+1) break;
			printf("%d ", arr1[a++]);
			continue;
		}
		if (arr1[a] < arr2[b]) {
			printf("%d ", arr1[a++]);
		}
		else {
			printf("%d ", arr2[b++]);
		}
	}
	return 0;
}
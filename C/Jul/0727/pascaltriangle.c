#include<stdio.h>

int main() {
	int num[10][10] = { 0 };
	for (int i = 0; i < 10; i++) {
		num[i][0] = 1;
		if (i > 0) printf("%d\t", num[i][0]);
		for (int j = 1; j < i; j++) {
			num[i][j] = num[i - 1][j - 1] + num[i - 1][j];
			printf("%d\t", num[i][j]);
		}
		num[i][i] = 1;
		printf("%d\n", num[i][i]);
	}
	return 0;
}
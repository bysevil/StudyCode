#include<stdio.h>

int sum01() {
	double sum = 0.0;
	for (int i = 1; i < 100; i+=2) {
		sum += 1 / (double)(i * (i + 1));
	}
	printf("%Lf\n", sum);
	return 0;
}
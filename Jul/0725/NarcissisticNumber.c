#include<stdio.h>

int narcissisticnumber() {
	int n, m, k;
	for (int i = 100; i < 1000; i++) {
		n = i % 10;
		m = i / 10 % 10;
		k = i / 100;
		if (i == n * n * n + m * m * m + k * k * k) printf("%d\n",i);
	}
	return 0;
}